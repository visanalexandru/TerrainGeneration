#ifndef GRAPHICSUTIL_H
#define GRAPHICSUTIL_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include"../Camera/Camera.h"
namespace GraphicsUtil
{
extern Camera*main_camera;
void initialize_glfw();
GLFWwindow* create_window(int width,int height,std::string title);
bool initialize_glad();
void make_current_context(GLFWwindow*window);
void set_viewport(int width,int height);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void destroy_window(GLFWwindow*window);
void terminate_glfw();
void poll_events();
void set_main_camera(Camera*cam);
};

#endif // GRAPHICSUTIL_H
