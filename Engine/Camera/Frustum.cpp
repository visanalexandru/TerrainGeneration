#include "Frustum.h"
#define ANG2RAD 3.14159265358979323846/180.0


Frustum::Frustum()
{

}

enum Planes

{

    Near,

    Far,

    Left,

    Right,

    Top,

    Bottom,

};

float Plane::distanceToPoint(const glm::vec3& point) const

{
    return glm::dot(point, normal) + distanceToOrigin;
}
bool Frustum::boxInFrustum(AABB& box)

{

    bool result = true;

    for (auto& plane : m_planes)
    {

        if (plane.distanceToPoint(box.getVP(plane.normal)) < 0)
        {

            return false;

        }
        else if (plane.distanceToPoint(box.getVN(plane.normal)) < 0)
        {

            result = true;

        }

    }

    return result;

}
void Frustum::update(const glm::mat4& mat)

{

    // left

    m_planes[Planes::Left].normal.x = mat[0][3] + mat[0][0];

    m_planes[Planes::Left].normal.y = mat[1][3] + mat[1][0];

    m_planes[Planes::Left].normal.z = mat[2][3] + mat[2][0];

    m_planes[Planes::Left].distanceToOrigin = mat[3][3] + mat[3][0];



    // right

    m_planes[Planes::Right].normal.x = mat[0][3] - mat[0][0];

    m_planes[Planes::Right].normal.y = mat[1][3] - mat[1][0];

    m_planes[Planes::Right].normal.z = mat[2][3] - mat[2][0];

    m_planes[Planes::Right].distanceToOrigin = mat[3][3] - mat[3][0];



    // bottom

    m_planes[Planes::Bottom].normal.x = mat[0][3] + mat[0][1];

    m_planes[Planes::Bottom].normal.y = mat[1][3] + mat[1][1];

    m_planes[Planes::Bottom].normal.z = mat[2][3] + mat[2][1];

    m_planes[Planes::Bottom].distanceToOrigin = mat[3][3] + mat[3][1];



    // top

    m_planes[Planes::Top].normal.x = mat[0][3] - mat[0][1];

    m_planes[Planes::Top].normal.y = mat[1][3] - mat[1][1];

    m_planes[Planes::Top].normal.z = mat[2][3] - mat[2][1];

    m_planes[Planes::Top].distanceToOrigin = mat[3][3] - mat[3][1];



    // near

    m_planes[Planes::Near].normal.x = mat[0][3] + mat[0][2];

    m_planes[Planes::Near].normal.y = mat[1][3] + mat[1][2];

    m_planes[Planes::Near].normal.z = mat[2][3] + mat[2][2];

    m_planes[Planes::Near].distanceToOrigin = mat[3][3] + mat[3][2];



    // far

    m_planes[Planes::Far].normal.x = mat[0][3] - mat[0][2];

    m_planes[Planes::Far].normal.y = mat[1][3] - mat[1][2];

    m_planes[Planes::Far].normal.z = mat[2][3] - mat[2][2];

    m_planes[Planes::Far].distanceToOrigin = mat[3][3] - mat[3][2];



    for (auto& plane : m_planes)

    {

        float length = glm::length(plane.normal);
        plane.normal /= length;
        plane.distanceToOrigin /= length;

    }



}

Frustum::~Frustum()
{
}

bool Frustum::pointInFrustum(Vec3 &p)
{

    for (int i = 0; i < 6; i++)
    {

        if (m_planes[i].distanceToPoint(p) < 0)
            return false;
    }
    return(true);

}
