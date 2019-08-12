#ifndef FILE_PROC
#define FILE_PROC

#include <string>

using namespace std;

struct Date {
    string day;
    string month;
    string year;
};

class FileProcessor {
    public:
        Date getDate();
};

#endif