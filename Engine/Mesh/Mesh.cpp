#include "Mesh.h"

Mesh::Mesh(ShaderProgram*prog,Texture*tex)
{
    //ctor
    shader_program=prog;
    texture=tex;
    vao_index=0;
}
void Mesh::bind_mesh(bool bind_texture_and_shader)
{
    if(bind_texture_and_shader)
    {
        shader_program->use_program();
        texture->bind_texture();
    }
    bind_vertex_array();

}
float*Mesh::Get_bounds_pointer()
{
    return bounds;
}
ShaderProgram*Mesh::Get_shader()
{
    return shader_program;
}
Texture*Mesh::Get_texture()
{
    return texture;
}
void Mesh::get_bounds(MeshData&data)
{
    for(int i=0; i<6; i++)
    {
        bounds[i]=data.bounds[i];
    }
}
unsigned Mesh::Get_triangles_size()
{
    return triangles_size;

}
unsigned Mesh::Get_vertices_size()
{
    return vertices_size;
}
void Mesh::bind_vertex_array()
{
    glBindVertexArray(vao_index);
}
void Mesh::delete_vertex_array()
{
    glDeleteVertexArrays(1,&vao_index);
}
Mesh::~Mesh()
{
    //dtor
    delete_vertex_array();
}
