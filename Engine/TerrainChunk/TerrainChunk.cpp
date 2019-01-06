#include "TerrainChunk.h"

TerrainChunk::TerrainChunk(glm::vec3 pos,NoiseParameters heightmap_properties,ShaderProgram* prog,Texture2d*texture,Heightmap&aux,float sizex):
    Drawable3d(pos),
    heightmap_builder(pos.x,pos.z,0,heightmap_properties),
    heightmap(aux),
    lods{2,1,0.5f,0.2f,0.1f}

{
    //ctor
    needs_to_build_mesh=false;
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
void TerrainChunk::build_meshes_data()
{
    int size=(sizeofmesh+1)*2;
    heightmap_builder.generate_heightmap(&heightmap,size,2);
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
    float distance=glm::distance(centre,camera_position);
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
    float y1,y2,y3,y4;
    float x1,x2,x3,x4;
    float y1h,y2h,y3h,y4h;
    MeshBuilder builder(data);
    float y,x;
    for(y=0; y<sizeofmesh; y+=unit)
    {
        for(x=0; x<sizeofmesh; x+=unit)
        {
            curr=glm::vec3(x,0,y);
            x1=x;
            y1=y;
            x2=x+unit;
            y2=y;
            x3=x+unit;
            y3=y+unit;
            x4=x;
            y4=y+unit;
            y1h=heightmap.values[(int)(2*y1)][(int)(2*x1)];
            y2h=heightmap.values[(int)(2*y2)][(int)(2*x2)];
            y3h=heightmap.values[(int)(2*y3)][(int)(2*x3)];
            y4h=heightmap.values[(int)(2*y4)][(int)(2*x4)];
            builder.Add_face(curr,y4h,y3h,y2h,y1h,unit);
        }
    }
}

TerrainChunk::~TerrainChunk()
{
    //dtor
    destroy_meshes();
}
