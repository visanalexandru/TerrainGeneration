#include "Texture3d.h"

Texture3d::Texture3d():Texture()
{
    //ctor
    paths[0]="right.jpg";
    paths[1]="left.jpg";
    paths[2]="top.jpg";
    paths[3]="bottom.jpg";
    paths[4]="front.jpg";
    paths[5]="back.jpg";
}
void Texture3d::load_texture(std::string path)
{
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
// set the texture wrapping/filtering options (on the currently bound texture object)
// load and generate the texture
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(false);
    for(int i=0; i<6; i++)
    {
        std::string newpath=path+"/"+paths[i];
        unsigned char *data = stbi_load(newpath.c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            std::cout<<"Texture loaded: "<<newpath<<std::endl;
        }
        else
        {
            std::cout << "Failed to load texture :" <<newpath<<std::endl;
        }
        stbi_image_free(data);
    }

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    texture_index=texture;

}
void Texture3d::bind_texture()
{

    glBindTexture(GL_TEXTURE_CUBE_MAP, texture_index);

}
Texture3d::~Texture3d()
{
    //dtor
}
