#ifndef MESHBUILDER_H
#define MESHBUILDER_H
#include"../MeshData/MeshData.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class MeshBuilder
{
public:
    MeshBuilder(MeshData&meshdata);
    void Add_vertex(glm::vec3 position,glm::vec2 texture_coordinates);
    void Add_vertex(glm::vec3 position,glm::vec2 texture_coordinates,glm::vec3 normal);
    void Add_triangle(unsigned index1,unsigned index2,unsigned index3);
    void Add_face(glm::vec3 position,int face_index);
    void Add_cube(glm::vec3 position);
    void Add_face(glm::vec3 position,float y1,float y2,float y3,float y4,float unit);
    void Set_bounds(float x,float y,float z);
    virtual ~MeshBuilder();
protected:

private:
    glm::vec3 calculate_normal(glm::vec3 p1,glm::vec3 p2,glm::vec3 p3);
    glm::vec3 cube_face[6][4];
    MeshData&to_modify;
};

#endif // MESHBUILDER_H
