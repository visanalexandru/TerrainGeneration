#include "Scene.h"

Scene::Scene(Texture*a,ShaderProgram*b)
{
    //ctor
    texture_to_bind=a;
    shader_to_bind=b;
}
void Scene::add_drawable(Drawable3d&to_add)
{
    to_draw.push_back(&to_add);
}
Scene::~Scene()
{
    //dtor
}
