#ifndef FILE_PROC
#define FILE_PROC

#include <string>
#include <iostream>

using namespace std;

struct Date {
    string day;
    string month;
    string year;
};

template <typename T> 
class FileProcessor {
    public:
        T processFile(fstream);
};

#endif