#ifndef WORLD_H
#define WORLD_H
#include"../Scene/Scene.h"
#include<unordered_map>
#include"../Camera/Camera.h"
#include<string>
#include"../TerrainChunk/TerrainChunk.h"
#include<thread>
#include<mutex>
class World
{
public:
    World(ShaderProgram*prog,Texture2d*tex,Camera&p_camera,int view_rangein,int chunk_sizein);
    virtual ~World();
    Scene scene;
    void tick();
    void lock();
    void unlock();
    void create_meshes();
    void create_scene();
    void destroy_out_of_range_chunks();

protected:
private:
    mutex lockx;
    thread* worker_thread;
    bool is_running;
    void thread_function();
    int chunk_size;
    int view_range;
    ShaderProgram*terrain_shader;
    string vector2_to_string(glm::vec2 to_convert);
    Texture2d*terrain_texture;
    Camera&player_camera;
    unordered_map<string,TerrainChunk*>chunks;//we use string to transform its position into a hashable datatype
    glm::vec2 chunk_relative_position(glm::vec3 position);
    glm::vec2 player_chunk_relative_position();
    float distance2d_between(glm::vec2 a,glm::vec2 b);
    void add_chunk_to_scene(TerrainChunk*chunk);
    void delete_all_chunks();
    bool chunk_exists_at(glm::vec2 position);
    void delete_chunk(int chunk_index);
    glm::vec2 to_vec2(glm::vec3 pos);
    bool is_too_far(TerrainChunk*chunk);
    void spawn_chunk_at(glm::vec2 position);//we use vector2 because we only need x and z coordinates
    void update_chunks();
    void spawn_closest_chunk();
    void create_worker_thread();
    void delete_worker_thread();
    vector<TerrainChunk*>chunk_list;
    bool could_a_chunk_be_seen_at(glm::vec2 position);
    Heightmap<float> auxiliary;


};

#endif // WORLD_H
