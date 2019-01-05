#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H
#include"../Graphics/GraphicsUtil.h"
#include"../Camera/Camera.h"
class PlayerInput
{
public:
    PlayerInput(GLFWwindow*context,Camera&player_camera_in);
    Camera&player_camera;
    GLFWwindow*context_window;
    virtual ~PlayerInput();
    void process_input();
    float get_delta_time();
protected:

private:
    void check_callbacks();
    float sensitivity;
    double lastX;
    double lastY;
    float last_time;
    void check_for_exit();
    void move_camera();
    void rotate_camera();
    void update_camera_frustum();
};

#endif // PLAYERINPUT_H
