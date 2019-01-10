#ifndef FILEREADER_H
#define FILEREADER_H
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class FileReader
{
public:
    FileReader(string path_to_file);
    char*get_string_from_file();
    virtual ~FileReader();

protected:

private:
    string path;
    char char_array[5000];
};

#endif // FILEREADER_H
