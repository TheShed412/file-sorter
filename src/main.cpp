#include <iostream>
#include <unistd.h>

#include "MediaInfoCMD.hpp"
#include "MediaDate.hpp"
#include "SystemUtils.hpp"

using namespace std;

string getInfo(const char* cmd);

int main() {
    string dateKey = "Encoded date";
    MediaInfoCMD cmd("mediainfo /home/tyler/Downloads/Project1_2019_06_22_1.mp4");

    string result = cmd.Exec();
    map<string, string> videoAtts = cmd.GetGeneralInfo();

    MediaDate date(videoAtts.at(dateKey));
    string envStr = getenvUtil("SORTER_PATH");
    bool madeDir = mkdirUtil(envStr + "/test");
    cout << envStr << endl;
    cout << madeDir << endl;

    // for(map<string,string>::iterator it = videoAtts.begin(); it != videoAtts.end(); ++it) {
    //     cout << it->first << ": " << it->second << "\n";
    // }

    //cout << result << endl;

    return 0;
}
