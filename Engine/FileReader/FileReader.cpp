#include "FileReader.h"

FileReader::FileReader(string path_to_file)
{
    //ctor
    path=path_to_file;
}
char* FileReader::get_string_from_file()
{
    ifstream in(path);
    in.get(char_array,5000,EOF);
    return char_array;
}
FileReader::~FileReader()
{
    //dtor
}
