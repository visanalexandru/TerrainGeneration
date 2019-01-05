#include "Texture.h"

Texture::Texture()
{
    //ctor
    texture_index=0;
}

Texture::~Texture()
{
    //dtor
    glDeleteTextures(1, &texture_index);
}
