#include "World.h"

World::World(ShaderProgram*prog,Texture2d*tex,Camera&p_camera,int view_rangein,int chunk_sizein):
    player_camera(p_camera)
{
    //ctor
    terrain_shader=prog;
    terrain_texture=tex;
    view_range=view_rangein;
    chunk_size=chunk_sizein;
    create_worker_thread();
}
string World::vector2_to_string(glm::vec2 in)
{
    string a;
    int b=in.x,c=in.y;
    a+=to_string(b);
    a+=" ";
    a+=to_string(c);
    return a;
}
glm::vec2 World::player_chunk_relative_position()
{
    return chunk_relative_position(player_camera.get_position());

}
void World::create_worker_thread()
{
    is_running=true;
    worker_thread=new thread([=] { thread_function(); });
    cout<<"STARTED WORLD THREAD"<<endl;
}
void World::delete_worker_thread()
{
    is_running=false;
    worker_thread->join();
    cout<<"STOPPED THREAD"<<endl;
    delete worker_thread;
}
void World::thread_function()
{
    while(is_running)
    {
        tick();
    }

}
void World::lock()
{
    lockx.lock();
}
void World::unlock()
{
    lockx.unlock();
}
void World::tick()
{
    spawn_closest_chunk();
    update_chunks();
    //std::this_thread::sleep_for(0s);

}
void World::spawn_chunk_at(glm::vec2 position)
{
    NoiseParameters a;
    TerrainChunk*chunk=new TerrainChunk(glm::vec3(position.x,0,position.y),a,terrain_shader,terrain_texture,chunk_size);
    string p=vector2_to_string(position);
    lock();
    chunks.insert({p,chunk});
    chunk_list.push_back(chunk);
    unlock();

}
void World::create_meshes()
{
    int a=chunk_list.size();
    for(int i=0; i<a; i++)
    {
        if(chunk_list[i]->needs_to_build_mesh)
        {
            chunk_list[i]->create_meshes();
        }
    }

}
bool World::chunk_exists_at(glm::vec2 position)
{
    string a=vector2_to_string(position);
    if (chunks.find(a) !=chunks.end())
    {
        return true;
    }
    return false;
}
void World::update_chunks()
{
    lock();
    int a=chunk_list.size();
    for(int i=0; i<a; i++)
    {
        chunk_list[i]->Update_LOD(player_camera.get_position());
    }
    unlock();
}
void World::add_chunk_to_scene(TerrainChunk*to_add)
{
    scene.add_drawable(*to_add);

}
void World::delete_all_chunks()
{
    int a=chunk_list.size();
    for(int i=0; i<a; i++)
        delete chunk_list[i];
}
float World::distance2d_between(glm::vec2 a,glm::vec2 b)
{
    return glm::distance(a,b);

}
void World::spawn_closest_chunk()
{
    int limit=view_range*chunk_size;
    glm::vec2 player_chunk=player_chunk_relative_position();
    float min_distance=limit*10;
    glm::vec2 best_position;
    bool found=false;
    for(int z=-limit; z<=limit; z+=chunk_size)
    {
        for(int x=-limit; x<=limit; x+=chunk_size)
        {
            glm::vec2 cr(x,z);
            glm::vec2 truechunk=cr+player_chunk;
            float dist=distance2d_between(truechunk,player_chunk);
            if(!chunk_exists_at(truechunk)&&could_a_chunk_be_seen_at(truechunk)&&dist<min_distance)
            {
                min_distance=dist;
                best_position=truechunk;
                found=true;
            }

        }
    }
    if(found)
        spawn_chunk_at(best_position);



}
glm::vec2 World::chunk_relative_position(glm::vec3 position)
{
    float x=position.x;
    float y=position.z;
    glm::vec2 a(floor(x/chunk_size),floor(y/chunk_size));
    return a*(float)chunk_size;

}
glm::vec2 World::to_vec2(glm::vec3 pos)
{
    return glm::vec2(pos.x,pos.z);
}
void World::delete_chunk(int chunk_index)
{
    TerrainChunk*rf=chunk_list[chunk_index];
    glm::vec2 keyv=to_vec2(rf->get_position());
    string key=vector2_to_string(keyv);
    chunk_list.erase(chunk_list.begin()+chunk_index);
    chunks.erase(key);
    delete rf;
}
void World::destroy_out_of_range_chunks()
{
    for(int i=0; i<chunk_list.size(); i++)
    {
        TerrainChunk*sp=chunk_list[i];
        if(is_too_far(sp))
        {
            delete_chunk(i);
            i--;
        }
    }

}
bool World::could_a_chunk_be_seen_at(glm::vec2 position)
{
    AABB box(glm::vec3(position.x,0,position.y),glm::vec3(chunk_size,100,chunk_size));
    if(player_camera.can_see(box))
        return true;
    return false;

}
bool World::is_too_far(TerrainChunk*chunk)
{
    glm::vec2 player_pos=to_vec2(player_camera.get_position());
    glm::vec2 chunk_pos=to_vec2(chunk->get_position());
    float xdiff=abs(chunk_pos.x-player_pos.x);
    float ydiff=abs(chunk_pos.y-player_pos.y);
    float maxx=(view_range+1)*chunk_size;
    if(xdiff>maxx ||ydiff>maxx)
        return true;
    return false;

}
void World::create_scene()
{
    scene.to_draw.clear();
    int a=chunk_list.size();
    for(int i=0; i<a; i++)
        add_chunk_to_scene(chunk_list[i]);
}
World::~World()
{
    //dtor
    delete_worker_thread();
    delete_all_chunks();
}
