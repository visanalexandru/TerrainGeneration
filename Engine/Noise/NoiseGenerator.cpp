#include "NoiseGenerator.h"
#include<iostream>
NoiseGenerator::NoiseGenerator(float xpositiony,float ypositiony,float seedy,NoiseParameters params)
{
    //ctor
    xposition=xpositiony;
    yposition=ypositiony;
    seed=seedy;
    parameters=params;
    generator=SimplexNoise(params.frequency,params.amplitude,params.lacunarity,params.persistence);
    octaves=params.octaves;

}
void NoiseGenerator::generate_heightmap(Heightmap*heightmap,int sizex,float unit)
{
    SimplexNoise noise;
    for(int y=0; y<sizex; y++)
    {
        for(int x=0; x<sizex; x++)
        {
            float offx=(float)x/unit+xposition;
            float offy=(float)y/unit+yposition;
            float noiseresult=get_noise_at(offx,offy);
            heightmap->values[y][x]=noiseresult;

        }

    }

}
float NoiseGenerator::get_noise_at(float x,float y)
{
    float div=parameters.scale;
    float a=generator.fractal(octaves,x/div,y/div)*30;
    return a;
}
NoiseGenerator::~NoiseGenerator()
{
    //dtor
}
