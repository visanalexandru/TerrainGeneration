#include "Renderer.h"

Renderer::Renderer(GLFWwindow*context,Camera&camera):main_camera(camera)
{
    //ctor
    context_window=context;
}
void Renderer::Render(Drawable3d&to_draw)
{
    if(to_draw.mesh&&main_camera.can_see(to_draw) )
    {
        Mesh&mesh=*to_draw.mesh;
        vertices_rendered+=mesh.vertices_size;
        mesh.bind_mesh(false);
        mesh.shader_program->set_mat4(camera_view_matrix,view);
        mesh.shader_program->set_mat4(main_camera.getProjectionMatrix(),proj);
        mesh.shader_program->set_mat4(to_draw.Get_position_matrix(),model);
        glDrawElements(GL_TRIANGLES, mesh.triangles_size, GL_UNSIGNED_INT,(void*)0);
    }
}
void Renderer::Render_scene(Scene&scene)
{
    scene.bind_resources();
    int si=scene.to_draw.size();
    for(int i=0; i<si; i++)
        Render(*scene.to_draw[i]);

}
void Renderer::Render(Skybox&skybox)
{
    glDepthMask(GL_FALSE);
    SkyboxMesh&mesh=skybox.mesh;
    mesh.bind_mesh(true);
    mesh.shader_program->set_mat4(glm::mat3(camera_view_matrix),view);
    mesh.shader_program->set_mat4(main_camera.getProjectionMatrix(),proj);
    glDrawElements(GL_TRIANGLES, mesh.triangles_size, GL_UNSIGNED_INT,(void*)0);
    glDepthMask(GL_TRUE);


}
void Renderer::Prepare_frame()
{
    vertices_rendered=0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera_view_matrix=main_camera.getViewMatrix();
}
void Renderer::End_frame()
{
    glfwSwapBuffers(context_window);
}
Renderer::~Renderer()
{
    //dtor
}
