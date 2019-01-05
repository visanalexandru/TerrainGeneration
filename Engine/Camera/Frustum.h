#ifndef FRUSTUM_H
#define FRUSTUM_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include"../AABB/AABB.h"
typedef glm::vec3 Vec3;
struct Plane

{
    float distanceToPoint(const glm::vec3& point) const;
    float distanceToOrigin;
    glm::vec3 normal;

};

class Frustum
{
public:
    void update(const glm::mat4& projViewMatrix);
    Frustum();
    virtual ~Frustum();
    bool pointInFrustum(Vec3 &p);
    bool boxInFrustum(AABB&box);


private:
    Plane m_planes[6];
};

#endif // FRUSTUM_H
