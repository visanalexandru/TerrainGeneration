#include "Mesh3d.h"

Mesh3d::Mesh3d(ShaderProgram*prog,Texture2d*tex):Mesh(prog,tex)
{
    //ctor
}
void Mesh3d::create_vao(MeshData&data)
{
    get_bounds(data);
    int v1=data.get_vertices_size();
    int v2=data.get_triangles_size();
    unsigned int VBO, EBO;
    glGenVertexArrays(1, &vao_index);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(vao_index);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, v1*sizeof(float),data.get_vertices_list(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, v2*sizeof(unsigned),data.get_triangles_list(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5*sizeof(float)));
    glEnableVertexAttribArray(2);
    glBindVertexArray(0);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    triangles_size=v2;
    vertices_size=v1;

}
Mesh3d::~Mesh3d()
{
    //dtor
}
