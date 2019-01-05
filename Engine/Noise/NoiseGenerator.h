#ifndef NOISEGENERATOR_H
#define NOISEGENERATOR_H
#include"SimplexNoise.h"
#include"Heightmap.h"
#include"NoiseParameters.h"

class NoiseGenerator
{
public:
    NoiseGenerator(float xpositiony,float ypositiony,float seedy,NoiseParameters params);
    virtual ~NoiseGenerator();
    void generate_heightmap(Heightmap*heightmap,int sizex,float unit);
    float get_noise_at(float x,float y);

protected:

private:
    int octaves;
    SimplexNoise generator;
    NoiseParameters parameters;
    float xposition;
    float yposition;
    float seed;
};

#endif // NOISEGENERATOR_H
