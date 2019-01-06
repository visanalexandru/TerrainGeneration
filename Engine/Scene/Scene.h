#ifndef SCENE_H
#define SCENE_H
#include"../Drawable/Drawable3d.h"
#include<iostream>
#include<vector>
class Scene
{
public:
    Scene();
    virtual ~Scene();
    void add_drawable(Drawable3d&to_add);
    vector<Drawable3d*>to_draw;
protected:

private:

};

#endif // SCENE_H
