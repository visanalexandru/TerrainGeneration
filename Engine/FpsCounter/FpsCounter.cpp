#include "FpsCounter.h"

FpsCounter::FpsCounter()
{
    //ctor
    frames=0;
    total_sum=0;
}
void FpsCounter::Start()
{
    frame_begin_time=glfwGetTime();
}
void FpsCounter::End()
{
    float frame_end_time=glfwGetTime();
    float difference=frame_end_time-frame_begin_time;
    float fps=1.f/difference;
    total_sum+=fps;
    frames++;
    cout<<"CURRENT FPS: "<<fps<<" "<<"AVERAGE FPS: "<<total_sum/frames<<endl;
}
FpsCounter::~FpsCounter()
{
    //dtor
}
