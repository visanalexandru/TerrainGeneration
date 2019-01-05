#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H
#include"../Graphics/GraphicsUtil.h"//for glfwgettime
#include<iostream>
using namespace std;
class FpsCounter
{
    public:

        void Start();
        FpsCounter();
        virtual ~FpsCounter();
        void End();
    protected:

    private:
    float last_frame_time;
    float frame_begin_time;
    float total_sum;
    int frames;
};

#endif // FPSCOUNTER_H
