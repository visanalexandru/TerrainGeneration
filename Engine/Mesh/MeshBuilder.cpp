#include "MeshBuilder.h"

MeshBuilder::MeshBuilder(MeshData&meshdata):to_modify(meshdata)
{
    //ctor
    cube_face[0][0]=glm::vec3(1,0,0);
    cube_face[0][1]=glm::vec3(0,0,0);
    cube_face[0][3]=glm::vec3(1,1,0);
    cube_face[0][2]=glm::vec3(0,1,0);


    cube_face[1][0]=glm::vec3(1,0,1);
    cube_face[1][1]=glm::vec3(1,0,0);
    cube_face[1][2]=glm::vec3(1,1,0);
    cube_face[1][3]=glm::vec3(1,1,1);


    cube_face[2][0]=glm::vec3(0,0,1);
    cube_face[2][1]=glm::vec3(1,0,1);
    cube_face[2][2]=glm::vec3(1,1,1);
    cube_face[2][3]=glm::vec3(0,1,1);


    cube_face[3][0]=glm::vec3(0,0,0);
    cube_face[3][1]=glm::vec3(0,0,1);
    cube_face[3][2]=glm::vec3(0,1,1);
    cube_face[3][3]=glm::vec3(0,1,0);


    cube_face[4][3]=glm::vec3(0,1,0);
    cube_face[4][2]=glm::vec3(1,1,0);
    cube_face[4][1]=glm::vec3(1,1,1);
    cube_face[4][0]=glm::vec3(0,1,1);


    cube_face[5][0]=glm::vec3(0,0,0);
    cube_face[5][1]=glm::vec3(1,0,0);
    cube_face[5][2]=glm::vec3(1,0,1);
    cube_face[5][3]=glm::vec3(0,0,1);
}
void MeshBuilder::Add_vertex(glm::vec3 position,glm::vec2 texture_coordinates)
{
    to_modify.add_vertex(position,texture_coordinates,glm::vec3(0,0,0));
}
void MeshBuilder::Add_vertex(glm::vec3 position,glm::vec2 texture_coordinates,glm::vec3 normal)
{
    to_modify.add_vertex(position,texture_coordinates,normal);
}
void MeshBuilder::Add_cube(glm::vec3 position)
{
    for(int i=0; i<6; i++)
    {
        Add_face(position,i);
    }
}
void MeshBuilder::Add_face(glm::vec3 position,float heights[],float unit,glm::vec3 normal[])
{

    int v=to_modify.get_vertices_size()/8;
    glm::vec3 off1(0,heights[0],0);
    glm::vec3 off2(0,heights[1],0);
    glm::vec3 off3(0,heights[2],0);
    glm::vec3 off4(0,heights[3],0);
    glm::vec3 point1=position+cube_face[4][0]*unit+off1;
    glm::vec3 point2=position+cube_face[4][1]*unit+off2;
    glm::vec3 point3=position+cube_face[4][2]*unit+off3;
    glm::vec3 point4=position+cube_face[4][3]*unit+off4;
    point1.y-=unit;
    point2.y-=unit;
    point3.y-=unit;
    point4.y-=unit;
    Add_vertex(point1,glm::vec2(0,0),normal[0]);
    Add_vertex(point2,glm::vec2(1,0),normal[1]);
    Add_vertex(point3,glm::vec2(1,1),normal[2]);
    Add_vertex(point4,glm::vec2(0,1),normal[3]);
    Add_triangle(v,v+1,v+2);
    Add_triangle(v+2,v+3,v+0);

}
void MeshBuilder::Add_face(glm::vec3 position,int face_index)
{
    int v=to_modify.get_vertices_size()/5;
    Add_vertex(position+cube_face[face_index][0],glm::vec2(0,0));
    Add_vertex(position+cube_face[face_index][1],glm::vec2(1,0));
    Add_vertex(position+cube_face[face_index][2],glm::vec2(1,1));
    Add_vertex(position+cube_face[face_index][3],glm::vec2(0,1));
    Add_triangle(v,v+1,v+2);
    Add_triangle(v+2,v+3,v+0);
}
void MeshBuilder::Add_triangle(unsigned index1,unsigned index2,unsigned index3)
{
    to_modify.add_triangle(index1);
    to_modify.add_triangle(index2);
    to_modify.add_triangle(index3);
}
MeshBuilder::~MeshBuilder()
{
    //dtor
}
