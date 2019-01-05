#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H
#include"../Shader/VertexShader.h"
#include"../Shader/FragmentShader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class ShaderProgram
{
public:
    ShaderProgram(VertexShader vertex_shader,FragmentShader fragment_shader);
    virtual ~ShaderProgram();
    unsigned shader_program_index;
    void attach_vertex_shader(VertexShader v);
    void attach_fragment_shader(FragmentShader v);
    void check_for_succes();
    void use_program();
    void delete_program();
    void set_mat4(glm::mat4 to_set,string& name);
protected:

private:
};

#endif // SHADERPROGRAM_H
