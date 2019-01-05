#include "Transformable.h"

Transformable::Transformable(glm::vec3 newpos)
{
    //ctor
    set_position(newpos);
}
void Transformable::set_position(glm::vec3 newpos)
{
    position=newpos;
}
glm::vec3 Transformable::get_position()
{
    return position;
}
glm::mat4 Transformable::Get_position_matrix()
{
    glm::mat4 model(1);
    glm::vec3 pos=get_position();
    model = glm::translate(model,pos);
    return model;
}
Transformable::~Transformable()
{
    //dtor
}
