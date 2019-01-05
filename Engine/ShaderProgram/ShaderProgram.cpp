#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(VertexShader vertex_shader,FragmentShader fragment_shader)
{
    //ctor
    shader_program_index=glCreateProgram();
    attach_fragment_shader(fragment_shader);
    attach_vertex_shader(vertex_shader);
    glLinkProgram(shader_program_index);
    check_for_succes();

}
void ShaderProgram::attach_fragment_shader(FragmentShader v)
{
    glAttachShader(shader_program_index, v.get_shader_index());
}
void ShaderProgram::attach_vertex_shader(VertexShader v)
{
    glAttachShader(shader_program_index, v.get_shader_index());
}
void ShaderProgram::check_for_succes()
{
    int success;
    char infoLog[512];
    glGetProgramiv(shader_program_index, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(shader_program_index, 512, NULL, infoLog);
        std::cout<<"Shader program compilation failed :"<<std::endl;
        std::cout<<infoLog<<std::endl;
    }
    else
        std::cout<<"Shader program compilation success"<<std::endl;
}
void ShaderProgram::use_program()
{
    glUseProgram(shader_program_index);
}
void ShaderProgram::delete_program()
{
    glUseProgram(0);
    glDeleteProgram(shader_program_index);
}
void ShaderProgram::set_mat4(glm::mat4 to_set,std::string& name)
{
    int modelLoc = glGetUniformLocation(shader_program_index, name.c_str());
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(to_set));
}

ShaderProgram::~ShaderProgram()
{
    //dtor
    delete_program();
}
