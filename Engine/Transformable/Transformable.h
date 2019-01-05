#ifndef TRANSFORMABLE_H
#define TRANSFORMABLE_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transformable
{
public:
    Transformable(glm::vec3 newpos);
    virtual ~Transformable();
    void set_position(glm::vec3 new_pos);
    glm::mat4 Get_position_matrix();
    glm::vec3 get_position();
protected:

private:
    glm::vec3 position;

};

#endif // TRANSFORMABLE_H
