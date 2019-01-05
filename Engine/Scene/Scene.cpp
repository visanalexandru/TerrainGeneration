#include "Scene.h"

Scene::Scene()
{
    //ctor
}
void Scene::add_drawable(Drawable3d&to_add){
to_draw.push_back(&to_add);
}
Scene::~Scene()
{
    //dtor
}
