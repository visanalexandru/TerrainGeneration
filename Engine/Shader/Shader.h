#ifndef SHADER_H
#define SHADER_H
#include"../Graphics/GraphicsUtil.h"
#include"../FileReader/FileReader.h"
class Shader
{
public:
    Shader();
    virtual ~Shader();
    virtual void load_shader(std::string path)=0;
    void delete_shader();
    virtual void check_for_shader_compilation_succes(std::string path)=0;
    unsigned get_shader_index();
protected:
    unsigned shader_index;

private:
};

#endif // SHADER_H
