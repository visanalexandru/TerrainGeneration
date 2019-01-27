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
    float x,y,z;
    x=position.x;
    y=position.y;
    z=position.z;
    float x2,y2;
    x2=texture_coordinates.x;
    y2=texture_coordinates.y;
    to_modify.verticeslist.push_back(x);
    to_modify.verticeslist.push_back(y);
    to_modify.verticeslist.push_back(z);
    to_modify.verticeslist.push_back(x2);
    to_modify.verticeslist.push_back(y2);
    Set_bounds(x,y,z);
}
void MeshBuilder::Add_vertex(glm::vec3 position,glm::vec2 texture_coordinates,glm::vec3 normal)
{
    float x,y,z;
    x=position.x;
    y=position.y;
    z=position.z;
    float x2,y2;
    x2=texture_coordinates.x;
    y2=texture_coordinates.y;
    float x3,y3,z3;
    x3=normal.x;
    y3=normal.y;
    z3=normal.z;
    to_modify.verticeslist.push_back(x);
    to_modify.verticeslist.push_back(y);
    to_modify.verticeslist.push_back(z);
    to_modify.verticeslist.push_back(x2);
    to_modify.verticeslist.push_back(y2);
    to_modify.verticeslist.push_back(x3);
    to_modify.verticeslist.push_back(y3);
    to_modify.verticeslist.push_back(z3);
    Set_bounds(x,y,z);
}
void MeshBuilder::Set_bounds(float x,float y,float z)
{
    float params[] {x,y,z};
    for(int i=0; i<6; i+=2)
    {
        float current_bound=params[i/2];
        if(to_modify.has_not_set_bounds)
        {
            to_modify.bounds[i]=current_bound;
            to_modify.bounds[i+1]=current_bound;
        }
        else
        {
            if(current_bound<to_modify.bounds[i])
                to_modify.bounds[i]=current_bound;
            if(current_bound>to_modify.bounds[i+1])
                to_modify.bounds[i+1]=current_bound;
        }

    }
    to_modify.has_not_set_bounds=false;
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

    int v=to_modify.verticeslist.size()/8;
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
    int v=to_modify.verticeslist.size()/5;
    Add_vertex(position+cube_face[face_index][0],glm::vec2(0,0));
    Add_vertex(position+cube_face[face_index][1],glm::vec2(1,0));
    Add_vertex(position+cube_face[face_index][2],glm::vec2(1,1));
    Add_vertex(position+cube_face[face_index][3],glm::vec2(0,1));
    Add_triangle(v,v+1,v+2);
    Add_triangle(v+2,v+3,v+0);
}
void MeshBuilder::Add_triangle(unsigned index1,unsigned index2,unsigned index3)
{
    to_modify.triangleslist.push_back(index1);
    to_modify.triangleslist.push_back(index2);
    to_modify.triangleslist.push_back(index3);
}
MeshBuilder::~MeshBuilder()
{
    //dtor
}
