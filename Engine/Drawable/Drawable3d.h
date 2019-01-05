#ifndef DRAWABLE3D_H
#define DRAWABLE3D_H
#include"../Transformable/Transformable.h"
#include"../AABB/AABB.h"
#include"../Mesh/Mesh.h"

class Drawable3d:public AABB,public Transformable
{
public:
    Drawable3d(glm::vec3 position);
    virtual ~Drawable3d();
    virtual void Set_mesh(Mesh&new_mesh);
    void UpdateAABB(Mesh&new_mesh);
    Mesh*mesh;
protected:

private:
};

#endif // DRAWABLE3D_H
