#include <stdexcept>

using namespace std;

class File_Not_Opened : public runtime_error
{
    public:
        File_Not_Opened() : runtime_error("Cannot open the file!"){}
        File_Not_Opened(string what) : runtime_error(what) {}
};

class File_At_End : public runtime_error
{
    public:
        File_At_End() : runtime_error("The file reached an end"){}
        File_At_End(string what) : runtime_error(what){}
};

class Figuur_read_error : public runtime_error
{
    public:
        Figuur_read_error() : runtime_error("Error happened while reading figure"){};
        Figuur_read_error(string what) : runtime_error(what){};

};
