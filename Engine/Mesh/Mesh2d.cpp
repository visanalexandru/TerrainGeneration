#include "Mesh2d.h"

Mesh2d::Mesh2d(ShaderProgram*prog,Texture2d*tex):Mesh(prog,tex)
{
    //ctor
}
void Mesh2d::create_vao(MeshData&data)
{
    int s1=data.verticeslist.size();
    int s2=data.triangleslist.size();
    unsigned int VBO, EBO;
    glGenVertexArrays(1, &vao_index);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(vao_index);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, s1*sizeof(float), &data.verticeslist[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, s2*sizeof(unsigned), &data.triangleslist[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

}
Mesh2d::~Mesh2d()
{
    //dtor
}
