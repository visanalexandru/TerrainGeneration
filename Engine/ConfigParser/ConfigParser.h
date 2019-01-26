#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H
#include<fstream>
#include<iostream>
using namespace std;
struct window_camera_properties
{
    int width;
    int height;
    float fov;
    bool use_vsync;
    string program_name;
    window_camera_properties(int w,int h,float fovc,bool vsync,string prog)
    {
        width=w;
        height=h;
        fov=fovc;
        use_vsync=vsync;
        program_name=prog;

    }
    window_camera_properties() //default settings
    {
        width=500;
        height=500;
        fov=100;
        use_vsync=true;
        program_name="program";
    }

};
class ConfigParser
{
public:
    ConfigParser(string path_to_config);
    window_camera_properties w_properties;
    virtual ~ConfigParser();

protected:
private:
    void parse(string path);

};

#endif // CONFIGPARSER_H
