#ifndef SCENE_H
#define SCENE_H
#include"../Drawable/Drawable3d.h"
#include<iostream>
#include<vector>
#include"../ShaderProgram/ShaderProgram.h"
#include"../Texture/Texture.h"
class Scene
{
public:
    Texture*texture_to_bind;
   ShaderProgram*shader_to_bind;
    Scene(Texture*a,ShaderProgram*b);
    virtual ~Scene();
    void add_drawable(Drawable3d&to_add);
    vector<Drawable3d*>to_draw;
protected:

private:

};

#endif // SCENE_H
