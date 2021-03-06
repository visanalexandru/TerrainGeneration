#include <iostream>
#include"Engine/Graphics/GraphicsUtil.h"
#include"Engine/Input/PlayerInput.h"
#include"Engine/Mesh/MeshBuilder.h"
#include"Engine/Graphics/Renderer.h"
#include"Engine/Mesh/Mesh3d.h"
#include"Engine/Skybox/Skybox.h"
#include"Engine/ResourceManager/ResourceManager.h"
#include"Engine/World/World.h"
#include"Engine/FpsCounter/FpsCounter.h"
using namespace std;
void load_all_resources(ResourceManager&manager)
{
    manager.load_vertex_shader("Resources/Shaders/vertex_shader3d.vert","basicvert");
    manager.load_fragment_shader("Resources/Shaders/fragment_shader.frag","basicfrag");
    manager.load_vertex_shader("Resources/Shaders/skybox_shader.vert","skyboxvert");
    manager.load_fragment_shader("Resources/Shaders/skybox_shader.frag","skyboxfrag");
    manager.create_program("basicvert","basicfrag","basic_shader");
    manager.create_program("skyboxvert","skyboxfrag","skybox_shader");
    manager.load_texture("Resources/Textures/grass2.jpg","test3");
    manager.load_cubemap("Resources/Cubemap","test4");
}
ConfigParser parse_config()
{
    return ConfigParser("Resources/config.txt");

}
int main()
{
    GraphicsUtil::initialize_glfw();
    ResourceManager manager;
    ConfigParser parsed=parse_config();
    GLFWwindow*window=GraphicsUtil::create_window(parsed.w_properties);
    if(window==NULL)
        return -1;
    load_all_resources(manager);
    ShaderProgram* basic_prog=manager.get_shader_program("basic_shader");
    ShaderProgram* skybox_prog=manager.get_shader_program("skybox_shader");
    Texture2d*basic_texture=manager.get_texture("test3");
    Skybox sky(skybox_prog,manager.get_cubemap("test4"));
    Camera camera(glm::vec3(10,20,10),parsed.w_properties);
    GraphicsUtil::set_main_camera(&camera);
    PlayerInput input_processer(window,camera);
    NoiseParameters a(8,1.f,1.7f,0.5f,1,100.f);
    Renderer renderer(window,camera);
    World world(basic_prog,basic_texture,camera,10,60);
    FpsCounter counter;
    while(!glfwWindowShouldClose(window))
    {
        counter.Start();
        input_processer.process_input();
        renderer.Prepare_frame();
        renderer.Render(sky);
        world.lock();//makes the world thread wait for completion
        world.destroy_out_of_range_chunks();
        world.create_meshes();
        world.create_scene();
        renderer.Render_scene(world.scene);
        world.unlock();//the world thread is resumed
        renderer.End_frame();
        counter.End();
    }
    GraphicsUtil::destroy_window(window);
    GraphicsUtil::terminate_glfw();
    return 0;
}
