#ifndef NOISEPARAMETERS_H
#define NOISEPARAMETERS_H


class NoiseParameters
{
public:
    NoiseParameters();
    NoiseParameters(int o,float a,float l,float p,float f,float scale);
    int octaves;
    float frequency;
    float amplitude;
    float lacunarity;
    float persistence;
    float scale;
    virtual ~NoiseParameters();

protected:

private:
};

#endif // NOISEPARAMETERS_H
