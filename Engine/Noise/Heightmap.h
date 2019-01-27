#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

template<typename type>
class Heightmap
{
public:
    type**values;
    Heightmap(int sizeofmatrix);
    virtual ~Heightmap();

protected:

private:
    int sizex;
    void initialize(int sizex);
    void destroy_matrix(int sizex);
};
template<typename type>
Heightmap<type>::Heightmap(int sizeofmatrix)
{
    //ctor
    initialize(sizeofmatrix);
    sizex=sizeofmatrix;

}
template<typename type>
void Heightmap<type>::initialize(int sizex)
{
    values=new type*[sizex];
    for(int i=0; i<sizex; i++)
        values[i]=new type[sizex];

}
template<typename type>
void Heightmap<type>::destroy_matrix(int sizex)
{
    for(int i=0; i<sizex; i++)
        delete[] values[i];
    delete []values;

}
template<typename type>
Heightmap<type>::~Heightmap()
{
    //dtor
    destroy_matrix(sizex);
}
#endif // HEIGHTMAP_H
