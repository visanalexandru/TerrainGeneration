#include "ModelLoader.h"
#include<sstream>
ModelLoader::ModelLoader(string path):reader(path)
{
    //ctor
}
void ModelLoader::load_vertices()
{
    char line[300];
    char tokened[300];
    int params[4];
    int params2[4];
    char delimiter;
    vector<glm::vec3> positions;
    vector<glm::vec2> uvs;
    while(reader>>line)
    {
        if(strcmp(line,"v")==0)//vertex
        {
            glm::vec3 to_insert;
            reader>>to_insert.x>>to_insert.y>>to_insert.z;
            positions.push_back(to_insert);//add coordinate to positions
        }
        else if(strcmp(line,"vt")==0)//vertex texture coordinate
        {
            glm::vec2 to_insert;
            reader>>to_insert.x>>to_insert.y;
            uvs.push_back(to_insert);//add texture coordinate to uvs

        }
        else if(strcmp(line,"f")==0)//face
        {
            reader.get(tokened,1000,'\n');//here we split the line into tokens (3 or 4) delimited by space
            char*token=strtok(tokened," ");//this is the tokened char array
            int countx=0;
            while(token!=NULL)
            {
                if(strlen(token)==1)
                    break;
                int p=0;
                int p2=0;
                stringstream str_stream;//we create a stringstream object to parse through the tokenized char array
                str_stream<<token;//we give it the tokenized char array
                str_stream>>p>>delimiter>>p2;//we read the vertex index and the texture coordinate index
                params[countx]=p;
                params2[countx]=p2;
                token=strtok(NULL," ");
                countx++;//we count how many vertices
            }
            if(countx==3)//3 vertices (1 face)
            {
                glm::vec3 a=positions[params[0]-1];
                glm::vec3 b=positions[params[1]-1];
                glm::vec3 c=positions[params[2]-1];
                glm::vec2 uv1=uvs[params2[0]-1];
                glm::vec2 uv2=uvs[params2[1]-1];
                glm::vec2 uv3=uvs[params2[2]-1];
                verts.push_back(vertex(a,uv1));//we create different vertices with given attributes
                verts.push_back(vertex(b,uv2));
                verts.push_back(vertex(c,uv3));

            }
            else if(countx==4)//this is a rectangular face, we triangulate it into 2 triangles(6 vertices)
            {
                glm::vec3 a=positions[params[0]-1];
                glm::vec3 b=positions[params[1]-1];
                glm::vec3 c=positions[params[2]-1];
                glm::vec3 d=positions[params[3]-1];
                glm::vec2 uv1=uvs[params2[0]-1];
                glm::vec2 uv2=uvs[params2[1]-1];
                glm::vec2 uv3=uvs[params2[2]-1];
                glm::vec2 uv4=uvs[params2[3]-1];
                verts.push_back(vertex(a,uv1));
                verts.push_back(vertex(b,uv2));
                verts.push_back(vertex(c,uv3));
                verts.push_back(vertex(c,uv3));
                verts.push_back(vertex(d,uv4));
                verts.push_back(vertex(a,uv1));
            }
        }

    }
}
void ModelLoader::load_model(MeshData&data)
{
    MeshBuilder builder(data);
    load_vertices();
    cout<<"Loaded model data ,creating attributes"<<endl;
    int sizex=verts.size();
    int pushed=0;
    for(int i=0; i<sizex; i++)
    {
        int index=get_unique_index(verts[i]);
        if(index!=-1)
        {
            data.triangleslist.push_back(index);//has found an identical vertex->do not use this one
        }
        else
        {
            data.triangleslist.push_back(pushed);
            unique_vertices.insert({verts[i].get_id(),pushed});
            builder.Add_vertex(verts[i].position,verts[i].uv);
            pushed++;

        }

    }
    cout<<"model loaded successfully: "<<data.verticeslist.size()<<" vertices, "<<data.triangleslist.size()<<" triangles"<<endl;
}
int ModelLoader::get_unique_index(vertex&vert)
{
    std::unordered_map<string,int>::const_iterator got = unique_vertices.find(vert.get_id());
    if(got==unique_vertices.end())
        return -1;
    else
        return got->second;
}
ModelLoader::~ModelLoader()
{
    //dtor
}
