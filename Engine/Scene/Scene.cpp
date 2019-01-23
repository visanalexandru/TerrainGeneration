#include "Scene.h"

Scene::Scene(Texture*a,ShaderProgram*b)
{
    //ctor
    texture_to_bind=a;
    shader_to_bind=b;
}
void Scene::bind_resources()
{
    texture_to_bind->bind_texture();
    shader_to_bind->use_program();
}
void Scene::add_drawable(Drawable3d&to_add)
{
    to_draw.push_back(&to_add);
}
Scene::~Scene()
{
    //dtor
}
