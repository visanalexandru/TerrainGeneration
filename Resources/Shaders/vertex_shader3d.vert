#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in vec3 aNormal;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
out vec2 TexCoord;
out vec3 Normal;
out vec3 FragPos;
void main()
{
    vec4 md=model*vec4(aPos, 1.0);
    gl_Position =projection*view*md;
    TexCoord = aTexCoord;
    FragPos = vec3(md);
    Normal=aNormal;

}
