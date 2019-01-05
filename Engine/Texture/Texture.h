#ifndef TEXTURE_H
#define TEXTURE_H
#include"../Graphics/GraphicsUtil.h"
#include<iostream>
#include"stb_image.h"
class Texture//abstract class ,different types of textures will inherit from this class
{
public:
    Texture();
    virtual void load_texture(std::string path)=0;
    virtual void bind_texture()=0;
    virtual ~Texture();
protected:
    unsigned texture_index;
private:
};

#endif // TEXTURE_H
