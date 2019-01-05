#include "MeshData.h"

MeshData::MeshData()
{
    //ctor
    has_not_set_bounds=true;
}
void MeshData::clear_data()
{
    vector<float>().swap(verticeslist);
    vector<unsigned>().swap(triangleslist);
}
MeshData::~MeshData()
{
    //dtor
}
