#ifndef MESH3D_H
#define MESH3D_H
#include"Mesh.h"

class Mesh3d:public Mesh
{
public:
    Mesh3d(ShaderProgram*prog,Texture2d*tex);
    virtual ~Mesh3d();
    void create_vao(MeshData&data);

protected:

private:
};

#endif // MESH3D_H
