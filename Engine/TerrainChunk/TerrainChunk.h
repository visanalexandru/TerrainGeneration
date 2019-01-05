#ifndef TERRAINCHUNK_H
#define TERRAINCHUNK_H
#include"../Drawable/Drawable3d.h"
#include"../Mesh/Mesh3d.h"
#include"../Noise/Heightmap.h"
#include"../Noise/NoiseGenerator.h"
#include"../Mesh/MeshBuilder.h"
class TerrainChunk:public Drawable3d
{
public:
    TerrainChunk(glm::vec3 pos,NoiseParameters heightmap_properties,ShaderProgram*prog,Texture2d*texture,float sizex);
    virtual ~TerrainChunk();
    void create_meshes();
    void Update_LOD(glm::vec3 camera_pos);
    bool needs_to_build_mesh;


protected:

private:
    Mesh3d* meshes[5];
    MeshData meshes_data[5];
    NoiseGenerator heightmap_builder;
    float sizeofmesh;
    void create_mesh_data(float unit,MeshData&data);
    int get_lod_index(glm::vec3 camera_position);
    void init_meshes(ShaderProgram*,Texture2d*t);
    glm::vec3 centre;
    void destroy_meshes();
    void build_meshes_data();
    Heightmap heightmap;
    float lods[5];
    void Create_all_LODS();


};

#endif // TERRAINCHUNK_H
