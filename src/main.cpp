#include <iostream>
#include <unistd.h>

#include "MediaInfoCMD.hpp"

using namespace std;

string getInfo(const char* cmd);

int main() {
    
    MediaInfoCMD cmd("mediainfo /home/tyler/Downloads/Project1_2019_06_22_1.mp4");

    string result = cmd.Exec();
    
    map<string, string> videoAtts = cmd.GetVideoInfo();

    for(map<string,string>::iterator it = videoAtts.begin(); it != videoAtts.end(); ++it) {
        cout << it->second << "\n";
    }

    return 0;
}
