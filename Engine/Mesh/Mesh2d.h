#ifndef MESH2D_H
#define MESH2D_H
#include"Mesh.h"

class Mesh2d:public Mesh
{
public:
    Mesh2d(ShaderProgram*prog,Texture2d*tex);
    virtual ~Mesh2d();
    void create_vao(MeshData&data);
protected:

private:
};

#endif // MESH2D_H
