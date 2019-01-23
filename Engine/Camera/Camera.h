#ifndef CAMERA_H
#define CAMERA_H
#include"../Transformable/Transformable.h"
#include<cmath>
#include"Frustum.h"
class Camera:public Transformable
{
public:
    Camera(glm::vec3 newpos,int screenwidth,int screenheight,float fov);
    virtual ~Camera();
    glm::mat4 getProjectionMatrix();
    glm::mat4 getViewMatrix();
    float camera_speed;
    glm::vec3 cameraFront;
    glm::vec3 cameraUp;
    float yaw;
    float pitch;
    void Update_front_vector();
    void Update_frustum();
    bool can_see(AABB&box);
    void update_projection_matrix(int width,int height);
protected:

private:
    float camera_fov;
    Frustum frustum;
    glm::mat4 projection_matrix;
    glm::mat4 makeProjectionMatrix(float fov,int width,int height);


};

#endif // CAMERA_H
