#ifndef MESH_H
#define MESH_H
#include"../ShaderProgram/ShaderProgram.h"
#include"../Texture/Texture2d.h"
#include"../Texture/Texture3d.h"
#include"../MeshData/MeshData.h"
class Mesh
{
public:
    Mesh(ShaderProgram*prog,Texture*tex);
    virtual ~Mesh();
    virtual void create_vao(MeshData&data)=0;
    void get_bounds(MeshData&data);
    void bind_mesh();
    ShaderProgram*shader_program;
    Texture*texture;
    float bounds[6];
    unsigned vertices_size;
    unsigned triangles_size;
protected:
    unsigned vao_index;

private:
    void bind_vertex_array();
    void delete_vertex_array();
};

#endif // MESH_H
