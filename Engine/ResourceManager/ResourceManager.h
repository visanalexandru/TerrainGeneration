#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include<map>
#include<iostream>
#include"../ShaderProgram/ShaderProgram.h"
#include"../Texture/Texture2d.h"
#include"../Texture/Texture3d.h"
#include"../MeshData/MeshData.h"
#include"../ModelLoader/ModelLoader.h"
using namespace std;

class ResourceManager
{
public:
    ResourceManager();
    void create_program(string vshadername,string fshadername,string name);
    void load_texture(string path,string name);
    void load_cubemap(string path,string name);
    void load_vertex_shader(string path,string name);
    void load_fragment_shader(string path,string name);
    void load_model(string path,string name);
    MeshData& get_model(string name);
    Texture2d*get_texture(string name);
    Texture3d*get_cubemap(string name);
    ShaderProgram* get_shader_program(string name);
    virtual ~ResourceManager();
    void delete_all_programs();
    void delete_all_cubemaps();
    void delete_all_textures();
    void delete_all_shaders();
    void delete_all_models();
protected:

private:
    map<string,Texture2d*> loaded_textures;
    map<string,Texture3d*> loaded_cubemaps;
    map<string,ShaderProgram*> loaded_shader_programs;
    map<string,VertexShader*> loaded_vertex_shaders;
    map<string,FragmentShader*> loaded_fragment_shaders;
    map<string,MeshData*> models_loaded;
};

#endif // RESOURCEMANAGER_H
