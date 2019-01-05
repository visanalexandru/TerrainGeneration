#ifndef FRAGMENTSHADER_H
#define FRAGMENTSHADER_H
#include"Shader.h"

class FragmentShader:public Shader
{
public:
    FragmentShader();
    virtual ~FragmentShader();
    void load_shader(std::string path);
    void check_for_shader_compilation_succes(std::string path);
protected:

private:
};

#endif // FRAGMENTSHADER_H
