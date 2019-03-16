#include "TerrainChunk.h"

TerrainChunk::TerrainChunk(glm::vec3 pos,NoiseParameters heightmap_properties,ShaderProgram* prog,Texture2d*texture,Chunk_auxiliaries aux,float sizex):
    Drawable3d(pos),
    heightmap_builder(pos.x,pos.z,0,heightmap_properties),
    heightmap(aux.height_aux),
    lods{2,1,0.5f,0.2f,0.1f},
    normal_map(aux.normal_aux)
{
    //ctor
    needs_to_build_mesh=false;
    max_height=0;
    init_meshes(prog,texture);
    sizeofmesh=sizex;
    build_meshes_data();
    centre=pos+glm::vec3((float)sizex/2,0,(float)sizex/2);
    Set_mesh(*meshes[0]);
    needs_to_build_mesh=true;

}
void TerrainChunk::init_meshes(ShaderProgram*p,Texture2d*t)
{
    for(int i=0; i<5; i++)
        meshes[i]=new Mesh3d(p,t);

}
void TerrainChunk::init_aux()
{
    int sizet=2*(sizeofmesh)+1;
    for(int i=0; i<sizet; i++)
        for(int k=0; k<sizet; k++)
        {
            normal_map.values[i][k]=glm::vec3(0,0,0);
        }

}
void TerrainChunk::generate_normal_map()
{
    float p1,p2,p3,p4;
    glm::vec3 a,b,c,d,normal1,normal2,avrg;
    int maxx=2*(sizeofmesh);
    for(int i=0; i<maxx; i++)
    {
        for(int k=0; k<maxx; k++)
        {
            p1=heightmap.values[i][k];
            p2=heightmap.values[i][k+1];
            p3=heightmap.values[i+1][k+1];
            p4=heightmap.values[i+1][k];
            a=glm::vec3(i,p1,k);
            b=glm::vec3(i,p2,k+0.5);
            c=glm::vec3(i+0.5,p3,k+0.5);
            d=glm::vec3(i+0.5,p4,k);
            normal1=calculate_normal(a,b,c);
            normal2=calculate_normal(c,d,a);
            normal_map.values[i][k]+=normal1;
            normal_map.values[i][k+1]+=normal1;
            normal_map.values[i+1][k+1]+=normal1;
            normal_map.values[i+1][k+1]+=normal2;
            normal_map.values[i+1][k]+=normal2;
            normal_map.values[i][k]+=normal2;

        }
    }


}
glm::vec3 TerrainChunk::calculate_normal(glm::vec3 p1,glm::vec3 p2,glm::vec3 p3)
{
    glm::vec3 u=p2-p1;
    glm::vec3 v=p3-p1;
    glm::vec3 normal=glm::cross(u,v);
    return normal;

}
void TerrainChunk::build_meshes_data()
{
    int size=(sizeofmesh)*2+1;
    init_aux();
    heightmap_builder.generate_heightmap(&heightmap,size,2);
    generate_normal_map();
    Create_all_LODS();
}
void TerrainChunk::Create_all_LODS()
{
    for(int i=0; i<5; i++)
        create_mesh_data(1/lods[i],meshes_data[i]);
}
void TerrainChunk::create_meshes() //TO BE CALLED FROM THE MAIN THREAD
{
    for(int i=0; i<5; i++)
    {
        meshes[i]->create_vao(meshes_data[i]);
        meshes_data[i].clear_data();
    }
    needs_to_build_mesh=false;
}
void TerrainChunk::destroy_meshes()
{
    for(int i=0; i<5; i++)
        delete meshes[i];
}
int TerrainChunk::get_lod_index(glm::vec3 camera_position)
{
    float distance;
    if(camera_position.y<max_height)
    {
        glm::vec3 centre2=centre;
        centre2.y=camera_position.y;
        distance=glm::distance(centre2,camera_position);
    }
    else
    {
        glm::vec3 centre2=centre;
        centre2.y=max_height;
        distance=glm::distance(centre2,camera_position);
    }
    int index=distance/100;
    index=min(index,4);
    return index;
}
void TerrainChunk::Update_LOD(glm::vec3 camera_pos)
{
    int index=get_lod_index(camera_pos);
    Set_mesh(*meshes[index]);
}
void TerrainChunk::create_mesh_data(float unit,MeshData&data)
{
    glm::vec3 curr;
    float heights[4];
    glm::vec3 normals[4];
    glm::vec2 p1,p2,p3,p4;
    MeshBuilder builder(data);
    float y,x;
    for(y=0; y<sizeofmesh; y+=unit)
    {
        for(x=0; x<sizeofmesh; x+=unit)
        {
            curr=glm::vec3(x,0,y);
            p1=glm::vec2(x,y);
            p1.x=x;
            p1.y=y;
            p2.x=x+unit;
            p2.y=y;
            p3.x=x+unit;
            p3.y=y+unit;
            p4.x=x;
            p4.y=y+unit;
            heights[3]=get_height_at(p1);
            heights[2]=get_height_at(p2);
            heights[1]=get_height_at(p3);
            heights[0]=get_height_at(p4);
            for(int i=0; i<4; i++)
                max_height=max(max_height,heights[i]);
            normals[3]=get_normal_at(p1);
            normals[2]=get_normal_at(p2);
            normals[1]=get_normal_at(p3);
            normals[0]=get_normal_at(p4);
            builder.Add_face(curr,heights,unit,normals);
        }
    }
}
float TerrainChunk::get_height_at(glm::vec2 pos)
{
    return heightmap.values[(int)(2*pos.y)][(int)(2*pos.x)];
}
glm::vec3 TerrainChunk::get_normal_at(glm::vec2 pos)
{
    glm::vec3 a=normal_map.values[(int)(2*pos.y)][(int)(2*pos.x)];
    return a;
}
TerrainChunk::~TerrainChunk()
{
    //dtor
    destroy_meshes();
}
