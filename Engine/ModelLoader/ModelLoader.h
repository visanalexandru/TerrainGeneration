#ifndef MODELLOADER_H
#define MODELLOADER_H
#include<iostream>
#include<fstream>
#include"../Mesh/Mesh3d.h"
#include"../MeshData/MeshData.h"
#include"../Mesh/MeshBuilder.h"
#include<unordered_map>
using namespace std;
struct vertex
{
    glm::vec3 position;
    glm::vec2 uv;
    vertex(glm::vec3 pos,glm::vec2 uvc)
    {
        position=pos;
        uv=uvc;
    }
    string get_id()
    {
        string a="";
        a+=to_string(position.x);
        a+=" ";
        a+=to_string(position.y);
        a+=" ";
        a+=to_string(position.z);
        a+=" ";
        a+=to_string(uv.x);
        a+=" ";
        a+=to_string(uv.y);
        return a;

    }
    bool operator==(vertex other)
    {
        if(other.position==this->position && other.uv==this->uv)
            return true;
        return false;
    }
    void prt()
    {
        cout<<position.x<<" "<<position.y<<" "<<position.z<<" "<<uv.x<<" "<<uv.y<<endl;

    }

};
class ModelLoader
{
public:

    ModelLoader(string path);
    void load_model(MeshData&data);
    virtual ~ModelLoader();

protected:

private:
    void load_vertices();
    int get_unique_index(vertex& vert);
    unordered_map<string,int>unique_vertices;
    vector<vertex> verts;
    ifstream reader;

};

#endif // MODELLOADER_H
