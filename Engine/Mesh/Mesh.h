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
    void bind_mesh(bool bind_texture_and_shader);

    unsigned Get_vertices_size();
    unsigned Get_triangles_size();
    float* Get_bounds_pointer();
    ShaderProgram*Get_shader();
    Texture*Get_texture();
protected:
    unsigned vao_index;
    unsigned vertices_size;
    unsigned triangles_size;
    ShaderProgram*shader_program;
    Texture*texture;
    float bounds[6];
private:
    void bind_vertex_array();
    void delete_vertex_array();
};

#endif // MESH_H
