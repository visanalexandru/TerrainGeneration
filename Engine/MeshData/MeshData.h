#ifndef MESHDATA_H
#define MESHDATA_H
#include<iostream>
#include<vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace std;

class MeshData
{
public:
    MeshData();
    virtual ~MeshData();
    float bounds[6];
    bool has_not_set_bounds;
    void clear_data();
    float*get_vertices_list();
    unsigned*get_triangles_list();
    int get_vertices_size();
    int get_triangles_size();
    void add_vertex(glm::vec3 to_add,glm::vec2 texturecoord,glm::vec3 normal);
    void add_vertex(glm::vec3 to_add,glm::vec2 texturecoord);
    void add_vertex(glm::vec3 to_add);
    void add_triangle(unsigned to_add);
protected:

private:
    void Set_bounds(glm::vec3 to_add);
    int vertices_list_size;
    int triangles_list_size;
    float* verticeslist;
    unsigned*triangleslist;
};

#endif // MESHDATA_H
