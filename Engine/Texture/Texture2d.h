#ifndef TEXTURE2D_H
#define TEXTURE2D_H
#include"Texture.h"

class Texture2d:public Texture
{
public:
    Texture2d();
    virtual ~Texture2d();
    void load_texture(std::string path);
    void bind_texture();
protected:

private:
};

#endif // TEXTURE2D_H
