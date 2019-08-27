#include <iostream>

#include "ExecCMD.hpp"
using namespace std;

string getInfo(const char* cmd);

int main() {
    string out = getInfo("mediainfo");

    cout <<  out << endl;

    return 0;
}

// TODO: make a general class to do any cmd (make external lib?) and make one implementing/extending that to use with mediainfo
string getInfo(const char* cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}