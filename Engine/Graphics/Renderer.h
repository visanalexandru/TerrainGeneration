#ifndef RENDERER_H
#define RENDERER_H
#include"../Drawable/Drawable3d.h"
#include"../Skybox/Skybox.h"
#include"../Camera/Camera.h"
#include"../Scene/Scene.h"
class Renderer
{
public:
    Renderer(GLFWwindow*context,Camera&camera);
    GLFWwindow*context_window;
    Camera&main_camera;
    void Render(Drawable3d&to_draw);
    void Render(Skybox&skybox);
    void Prepare_frame();
    virtual ~Renderer();
    void End_frame();
    void Render_scene(Scene&scene);
protected:

private:
    string model="model";
    string proj="projection";
    string view="view";
    glm::mat4 camera_view_matrix;
};

#endif // RENDERER_H
