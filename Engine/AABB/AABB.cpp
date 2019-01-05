#include "AABB.h"



AABB::AABB(Vec3 positionin, Vec3 dimensionin)
{
    AABB_position = positionin;
    dimensions = dimensionin;
}

glm::vec3 AABB::getVN(const glm::vec3& normal)

{

    glm::vec3 res = AABB_position;



    if (normal.x < 0)

    {

        res.x += dimensions.x;

    }

    if (normal.y < 0)

    {

        res.y += dimensions.y;

    }

    if (normal.z < 0)

    {

        res.z += dimensions.z;

    }



    return res;

}



glm::vec3 AABB::getVP(const glm::vec3& normal)

{

    glm::vec3 res = AABB_position;



    if (normal.x > 0)

    {

        res.x += dimensions.x;

    }

    if (normal.y > 0)

    {

        res.y += dimensions.y;

    }

    if (normal.z > 0)

    {

        res.z += dimensions.z;

    }



    return res;

}
AABB::~AABB()
{
}
