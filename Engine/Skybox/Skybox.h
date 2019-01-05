#ifndef SKYBOX_H
#define SKYBOX_H
#include"../Texture/Texture3d.h"
#include"../Mesh/SkyboxMesh.h"
class Skybox
{
public:
    Skybox(ShaderProgram*shaderprog,Texture3d*skybox_texture);
    virtual ~Skybox();
    SkyboxMesh mesh;
protected:
private:
};

#endif // SKYBOX_H
