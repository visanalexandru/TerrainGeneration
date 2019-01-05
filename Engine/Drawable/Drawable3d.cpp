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
    glm::vec3 off(new_mesh.bounds[0],new_mesh.bounds[2],new_mesh.bounds[4]);
    AABB_position=get_position()+off;
    dimensions.x=new_mesh.bounds[1]-new_mesh.bounds[0];
    dimensions.y=new_mesh.bounds[3]-new_mesh.bounds[2];
    dimensions.z=new_mesh.bounds[5]-new_mesh.bounds[4];
}
Drawable3d::~Drawable3d()
{
    //dtor
}
