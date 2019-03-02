#include "MeshData.h"

MeshData::MeshData()
{
    //ctor
    has_not_set_bounds=true;
    verticeslist=new float[470000];
    triangleslist=new unsigned[100000];
    vertices_list_size=0;
    triangles_list_size=0;
}
float*MeshData::get_vertices_list()
{
    return verticeslist;

}
unsigned*MeshData::get_triangles_list()
{
    return triangleslist;

}
int MeshData::get_vertices_size()
{
    return vertices_list_size;
}
void MeshData::add_vertex(glm::vec3 to_add,glm::vec2 texturecoord,glm::vec3 normal)
{
    verticeslist[vertices_list_size]=to_add.x;
    verticeslist[vertices_list_size+1]=to_add.y;
    verticeslist[vertices_list_size+2]=to_add.z;
    verticeslist[vertices_list_size+3]=texturecoord.x;
    verticeslist[vertices_list_size+4]=texturecoord.y;
    verticeslist[vertices_list_size+5]=normal.x;
    verticeslist[vertices_list_size+6]=normal.y;
    verticeslist[vertices_list_size+7]=normal.z;
    vertices_list_size+=8;


}
void MeshData::add_vertex(glm::vec3 to_add,glm::vec2 texturecoord)
{

    verticeslist[vertices_list_size]=to_add.x;
    verticeslist[vertices_list_size+1]=to_add.y;
    verticeslist[vertices_list_size+2]=to_add.z;
    verticeslist[vertices_list_size+3]=texturecoord.x;
    verticeslist[vertices_list_size+4]=texturecoord.y;
    vertices_list_size+=5;


}
void MeshData::add_vertex(glm::vec3 to_add)
{
    verticeslist[vertices_list_size]=to_add.x;
    verticeslist[vertices_list_size+1]=to_add.y;
    verticeslist[vertices_list_size+2]=to_add.z;
    vertices_list_size+=3;


}
void MeshData::add_triangle(unsigned to_add)
{
    triangleslist[triangles_list_size]=to_add;
    triangles_list_size+=1;


}
int MeshData::get_triangles_size()
{
    return triangles_list_size;
}
void MeshData::clear_data()
{
    vertices_list_size=0;
    triangles_list_size=0;
    delete[] verticeslist;
    delete[] triangleslist;
}
MeshData::~MeshData()
{
    //dtor
}
