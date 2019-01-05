#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
    //ctor
}
void ResourceManager::create_program(string vshadername,string fshadername,string name)
{
    VertexShader v=*loaded_vertex_shaders[vshadername];
    FragmentShader f=*loaded_fragment_shaders[fshadername];
    ShaderProgram* prog=new ShaderProgram(v,f);
    loaded_shader_programs[name]=prog;
}
void ResourceManager::load_texture(string path,string name)
{
    Texture2d*text=new Texture2d();
    text->load_texture(path);
    loaded_textures[name]=text;
}
void ResourceManager::load_model(string path,string name)
{
    ModelLoader loader(path);
    MeshData*data=new MeshData();
    loader.load_model(*data);
    models_loaded[name]=data;
}
MeshData& ResourceManager::get_model(string name)
{
    MeshData&refx=*models_loaded[name];
    return refx;
}
void ResourceManager::delete_all_models()
{
    map<string,MeshData*>::iterator map_iterator;
    for(map_iterator=models_loaded.begin(); map_iterator!=models_loaded.end(); map_iterator++)
    {
        delete map_iterator->second;
    }

}
void ResourceManager::load_fragment_shader(string path,string name)
{
    FragmentShader*shader=new FragmentShader();
    shader->load_shader(path);
    loaded_fragment_shaders[name]=shader;
}
void ResourceManager::load_vertex_shader(string path,string name)
{
    VertexShader*shader=new VertexShader();
    shader->load_shader(path);
    loaded_vertex_shaders[name]=shader;
}
Texture2d* ResourceManager::get_texture(string name)
{
    return loaded_textures[name];
}
Texture3d* ResourceManager::get_cubemap(string name)
{
    return loaded_cubemaps[name];
}
void ResourceManager::delete_all_shaders()
{

    map<string,VertexShader*>::iterator map_iterator;
    for(map_iterator=loaded_vertex_shaders.begin(); map_iterator!=loaded_vertex_shaders.end(); map_iterator++)
    {
        delete map_iterator->second;
    }
    map<string,FragmentShader*>::iterator map_iterator2;
    for(map_iterator2=loaded_fragment_shaders.begin(); map_iterator2!=loaded_fragment_shaders.end(); map_iterator2++)
    {
        delete map_iterator2->second;
    }
}

void ResourceManager::load_cubemap(string path,string name)
{
    Texture3d*texture3d=new Texture3d();
    texture3d->load_texture(path);
    loaded_cubemaps[name]=texture3d;
}
ShaderProgram* ResourceManager::get_shader_program(string name)
{
    return loaded_shader_programs[name];
}
void ResourceManager::delete_all_programs()
{
    map<string, ShaderProgram*>::iterator map_iterator;
    for(map_iterator=loaded_shader_programs.begin(); map_iterator!=loaded_shader_programs.end(); map_iterator++)
    {
        delete map_iterator->second;
    }

}
void ResourceManager::delete_all_textures()
{
    map<string, Texture2d*>::iterator map_iterator;
    for(map_iterator=loaded_textures.begin(); map_iterator!=loaded_textures.end(); map_iterator++)
    {
        delete map_iterator->second;
    }

}
void ResourceManager::delete_all_cubemaps()
{
    map<string, Texture3d*>::iterator map_iterator;
    for(map_iterator=loaded_cubemaps.begin(); map_iterator!=loaded_cubemaps.end(); map_iterator++)
    {
        delete map_iterator->second;
    }

}
ResourceManager::~ResourceManager()
{
    //dtor
    delete_all_programs();
    delete_all_textures();
    delete_all_cubemaps();
    delete_all_shaders();
    delete_all_models();
}
