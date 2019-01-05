#ifndef MESHDATA_H
#define MESHDATA_H
#include<iostream>
#include<vector>
using namespace std;

class MeshData
{
public:
    MeshData();
    virtual ~MeshData();
    vector<float> verticeslist;
    vector<unsigned>triangleslist;
    float bounds[6];
    bool has_not_set_bounds;
    void clear_data();
protected:

private:
};

#endif // MESHDATA_H
