#include "GraphicsUtil.h"
#include<string>
Camera *GraphicsUtil::main_camera=NULL;
void GraphicsUtil::initialize_glfw()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

}
void GraphicsUtil::set_main_camera(Camera*cam)
{
    main_camera=cam;
}
GLFWwindow* GraphicsUtil::create_window(window_camera_properties prop)
{
    string title=prop.program_name;
    GLFWwindow* window = glfwCreateWindow(prop.width, prop.height,title.c_str(), NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    else
        make_current_context(window);
    initialize_glad();
    glViewport(0,0,prop.width,prop.height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glEnable(GL_BLEND);
    glfwSwapInterval(prop.use_vsync);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    return window;
}
void GraphicsUtil::poll_events()
{
    glfwPollEvents();
}
void GraphicsUtil::make_current_context(GLFWwindow*window)
{
    glfwMakeContextCurrent(window);
}
bool GraphicsUtil::initialize_glad()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }
    return true;

}
void GraphicsUtil::destroy_window(GLFWwindow*window)
{
    glfwDestroyWindow(window);
}
void GraphicsUtil::set_viewport(int width,int height)
{
    glViewport(0, 0,width, height);
}

void GraphicsUtil::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    if(main_camera)
    {
        main_camera->update_projection_matrix(width,height);
    }
}
void GraphicsUtil::terminate_glfw()
{
    glfwTerminate();

}
