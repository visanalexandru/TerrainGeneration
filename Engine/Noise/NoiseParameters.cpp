#include "NoiseParameters.h"
NoiseParameters::NoiseParameters()
{
    //ctor
    frequency=1.0f;
    amplitude=1.0f;
    lacunarity=2.0f;
    persistence=0.5f;
    octaves=8;
    scale=100.f;
}
NoiseParameters:: NoiseParameters(int o,float a,float l,float p,float f,float scalei)
{
    octaves=o;
    amplitude=a;
    lacunarity=l;
    persistence=p;
    scale=scalei;
    frequency=f;
}
NoiseParameters::~NoiseParameters()
{
    //dtor
}
