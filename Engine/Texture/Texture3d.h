#ifndef TEXTURE3D_H
#define TEXTURE3D_H
#include"Texture.h"

class Texture3d:public Texture//for skyboxes
{
public:
    Texture3d();
    virtual ~Texture3d();
    void load_texture(std::string path);
    void bind_texture();
    std::string paths[6];
protected:

private:
};

#endif // TEXTURE3D_H
