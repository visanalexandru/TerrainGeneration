#ifndef SKYBOXMESH_H
#define SKYBOXMESH_H
#include"Mesh.h"

class SkyboxMesh:public Mesh
{
public:
    SkyboxMesh(ShaderProgram*prog,Texture3d*tex);
    void create_vao(MeshData&data);
    virtual ~SkyboxMesh();

protected:

private:
};

#endif // SKYBOXMESH_H
