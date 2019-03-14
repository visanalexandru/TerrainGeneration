#include "Drawable3d.h"

Drawable3d::Drawable3d(glm::vec3 position):AABB(position,glm::vec3(0,0,0)),Transformable(position)
{
    //ctor
    mesh=NULL;
}
void Drawable3d::Set_mesh(Mesh&new_mesh)
{
    mesh=&new_mesh;
    UpdateAABB(new_mesh);
}
void Drawable3d::UpdateAABB(Mesh&new_mesh)
{
    float*b_pointer=new_mesh.Get_bounds_pointer();
    glm::vec3 off(b_pointer[0],b_pointer[2],b_pointer[4]);
    AABB_position=get_position()+off;
    dimensions.x=b_pointer[1]-b_pointer[0];
    dimensions.y=b_pointer[3]-b_pointer[2];
    dimensions.z=b_pointer[5]-b_pointer[4];
}
Mesh* Drawable3d::Get_mesh()
{
    return mesh;
}
Drawable3d::~Drawable3d()
{
    //dtor
}
