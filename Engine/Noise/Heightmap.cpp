#include "Heightmap.h"

Heightmap::Heightmap(int sizeofmatrix)
{
    //ctor
    initialize(sizeofmatrix);
    sizex=sizeofmatrix;

}
void Heightmap::initialize(int sizex)
{
    values=new float*[sizex];
    for(int i=0; i<sizex; i++)
        values[i]=new float[sizex];

}
void Heightmap::destroy_matrix(int sizex)
{
    for(int i=0; i<sizex; i++)
        delete[] values[i];
    delete []values;

}
Heightmap::~Heightmap()
{
    //dtor
    destroy_matrix(sizex);
}
