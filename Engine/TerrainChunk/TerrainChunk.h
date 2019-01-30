#ifndef TERRAINCHUNK_H
#define TERRAINCHUNK_H
#include"../Drawable/Drawable3d.h"
#include"../Mesh/Mesh3d.h"
#include"../Noise/Heightmap.h"
#include"../Noise/NoiseGenerator.h"
#include"../Mesh/MeshBuilder.h"
struct Chunk_auxiliaries
{
    Heightmap<float>&height_aux;
    Heightmap<glm::vec3>&normal_aux;
    Chunk_auxiliaries(Heightmap<float>&a,Heightmap<glm::vec3>&b):height_aux(a),normal_aux(b) {}

};
class TerrainChunk:public Drawable3d
{
public:
    TerrainChunk(glm::vec3 pos,NoiseParameters heightmap_properties,ShaderProgram* prog,Texture2d*texture,Chunk_auxiliaries aux,float sizex);
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
    Heightmap<float>& heightmap;
    float lods[5];
    void Create_all_LODS();
    float get_height_at(glm::vec2 pos);
    float max_height;
    Heightmap<glm::vec3>&normal_map;
    void generate_normal_map();
    glm::vec3 calculate_normal(glm::vec3 p1,glm::vec3 p2,glm::vec3 p3);
    glm::vec3 get_normal_at(glm::vec2 pos);
    void init_aux();


};

#endif // TERRAINCHUNK_H
