#include "PlayerInput.h"

PlayerInput::PlayerInput(GLFWwindow*context,Camera&player_camera_in):player_camera(player_camera_in)
{
    //ctor
    context_window=context;
    last_time=glfwGetTime();
    glfwGetCursorPos(context,&lastX,&lastY);
    sensitivity=0.05f;
}
void PlayerInput::process_input()
{
    GraphicsUtil::poll_events();
    check_for_exit();
    move_camera();
    rotate_camera();
    update_camera_frustum();
}
void PlayerInput::update_camera_frustum()
{
    player_camera.Update_frustum();
}
void PlayerInput::rotate_camera()
{
    double newx,newy;
    glfwGetCursorPos(context_window,&newx,&newy);
    float diffx=newx-lastX;
    float diffy=lastY-newy;
    diffx*=sensitivity;
    diffy*=sensitivity;
    lastX=newx;
    lastY=newy;
    player_camera.pitch+=diffy;
    player_camera.yaw+=diffx;
    player_camera.Update_front_vector();
}
void PlayerInput::check_for_exit()
{
    if(glfwGetKey(context_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(context_window, true);
}
float PlayerInput::get_delta_time()
{
    float now=glfwGetTime();
    float to_return=now-last_time;
    last_time=now;
    return to_return;
}
void PlayerInput::check_callbacks()
{
    if(glfwGetKey(context_window,GLFW_KEY_1)==GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    if(glfwGetKey(context_window,GLFW_KEY_2)==GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

}
void PlayerInput::move_camera()
{
    check_callbacks();
    float delta_time=get_delta_time();
    float cameraSpeed = player_camera.camera_speed*delta_time;
    glm::vec3 cameraPos=player_camera.get_position();
    glm::vec3 cameraFront=player_camera.cameraFront;
    glm::vec3 cameraUp=player_camera.cameraUp;
    if(glfwGetKey(context_window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        cameraSpeed*=2;
    if (glfwGetKey(context_window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(context_window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(context_window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(context_window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    player_camera.set_position(cameraPos);

}
PlayerInput::~PlayerInput()
{
    //dtor
}
