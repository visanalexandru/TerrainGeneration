#include "VertexShader.h"

VertexShader::VertexShader():Shader()
{
    //ctor
}
void VertexShader::load_shader(std::string path)
{
    FileReader reader(path);
    const char* shader_to_compile=reader.get_string_from_file();
    shader_index = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader_index,1,&shader_to_compile, NULL);
    glCompileShader(shader_index);
    check_for_shader_compilation_succes(path);
}
void VertexShader::check_for_shader_compilation_succes(string path)
{
    int  success;
    char infoLog[512];
    glGetShaderiv(shader_index, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader_index, 512, NULL, infoLog);
        std::cout << "Vertex Shader compilation failed: " <<path<<std::endl<<"ERRORS:"<<std::endl<<infoLog << std::endl;
    }
    else
    {
        std::cout<<"Vertex Shader compilation successful: "<<path<<std::endl;
    }
}

VertexShader::~VertexShader()
{
    //dtor
}
