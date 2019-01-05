#ifndef AABB_H
#define AABB_H

#include"../Transformable/Transformable.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
typedef glm::vec3 Vec3;
class AABB
{
public:
    Vec3 AABB_position;
    Vec3 dimensions;
    AABB(Vec3 positionin, Vec3 dimensionin);
    glm::vec3 getVN(const glm::vec3& normal);
    glm::vec3 getVP(const glm::vec3& normal);
    virtual ~AABB();
};

#endif // AABB_H
