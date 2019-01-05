#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H


class Heightmap
{
public:
    float**values;
    Heightmap(int sizeofmatrix);
    virtual ~Heightmap();

protected:

private:
    int sizex;
    void initialize(int sizex);
    void destroy_matrix(int sizex);
};

#endif // HEIGHTMAP_H
