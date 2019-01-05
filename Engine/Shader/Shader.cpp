#include "Shader.h"

Shader::Shader()
{
    //ctor
    shader_index=0;
}
void Shader::delete_shader()
{
    glDeleteShader(shader_index);
}
unsigned Shader::get_shader_index()
{
    return shader_index;
}
Shader::~Shader()
{
    //dtor
    delete_shader();
}
