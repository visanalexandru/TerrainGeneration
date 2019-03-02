#include "Skybox.h"

Skybox::Skybox(ShaderProgram*shaderprog,Texture3d*skybox_texture):mesh(shaderprog,skybox_texture)
{
    //ctor
    glm::vec3 skyboxVertices[] =
    {
        //front
        glm::vec3(-1.0, -1.0,  1.0),
        glm::vec3(1.0, -1.0,  1.0),
        glm::vec3(1.0,  1.0,  1.0),
        glm::vec3( -1.0,  1.0,  1.0),
        // back
        glm::vec3(-1.0, -1.0, -1.0),
        glm::vec3( 1.0, -1.0, -1.0),
        glm::vec3( 1.0,  1.0, -1.0),
        glm::vec3(-1.0,  1.0, -1.0),
    };
    unsigned skyboxindices[]=
    {

// front
        0, 3, 2,
        2, 1, 0,
        // right
        1, 2, 6,
        6, 5, 1,
        // back
        7, 4, 5,
        5, 6, 7,
        // left
        4, 7, 3,
        3, 0, 4,
        // bottom
        4, 0, 1,
        1, 5, 4,
        // top
        3, 7, 6,
        6, 2, 3,
    };
    MeshData data;
    for(int i=0; i<24; i++)
        data.add_vertex(skyboxVertices[i]);
    for(int i=0; i<36; i++)
        data.add_triangle(skyboxindices[i]);
    mesh.create_vao(data);

}

Skybox::~Skybox()
{
    //dtor
}
