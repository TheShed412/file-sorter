#include <iostream>
#include <unistd.h>

#include "MediaInfoCMD.hpp"

using namespace std;

string getInfo(const char* cmd);

int main() {
    
    MediaInfoCMD cmd("mediainfo /home/tyler/Downloads/Project1_2019_06_22_1.mp4");

    vector<string> args = cmd.GetArgs();

    cout << "Num Args :: " << args.size() << endl;

    string result = cmd.Exec();
    
    cout << result << endl;

    return 0;
}
