#include "SkyboxMesh.h"

SkyboxMesh::SkyboxMesh(ShaderProgram*prog,Texture3d*tex):Mesh(prog,tex)
{
    //ctor
}
void SkyboxMesh::create_vao(MeshData&data)
{
    unsigned int VBO, EBO;
    int v1=data.get_vertices_size();
    int v2=data.get_triangles_size();
    glGenVertexArrays(1, &vao_index);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(vao_index);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, v1*sizeof(float), data.get_vertices_list(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, v2*sizeof(unsigned),data.get_triangles_list(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    triangles_size=v2;
    vertices_size=v1;

}
SkyboxMesh::~SkyboxMesh()
{
    //dtor
}
