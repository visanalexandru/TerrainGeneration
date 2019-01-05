#include "GraphicsUtil.h"
#include<string>
void GraphicsUtil::initialize_glfw()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

}
GLFWwindow* GraphicsUtil::create_window(int width,int height,std::string title)
{
    GLFWwindow* window = glfwCreateWindow(width, height,title.c_str(), NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    else
        make_current_context(window);
    initialize_glad();
    glViewport(0,0,width,height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glEnable(GL_BLEND);
    glfwSwapInterval(1);
    glfwWindowHint(GLFW_SAMPLES, 4);
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
}
void GraphicsUtil::terminate_glfw()
{
    glfwTerminate();

}
