#include <iostream>
#include <unistd.h>
#include <cstdio>

#include "MediaInfoCMD.hpp"
#include "MediaDate.hpp"
#include "SystemUtils.hpp"
#include "spdlog/spdlog.h"



using namespace std;
using namespace spdlog;

string getInfo(const char* cmd);

int main() {
    info("ayy {}", "lmao");
    string dateKey = "Encoded date";
    MediaInfoCMD cmd("mediainfo /home/tyler/Downloads/Project1_2019_06_22_1.mp4");

    string result = cmd.Exec();
    map<string, string> videoAtts = cmd.GetGeneralInfo();

    MediaDate date(videoAtts.at(dateKey));
    string envStr = getenvUtil("SORTER_PATH");
    bool madeDir = mkdirUtil(envStr + "/test");
    vector<string> entries = lsUtil(envStr);
    info("Environment: {}", envStr);
    info("Dir made: {}", envStr);

    for(string ent : entries) {
        info("File: {}", ent);
    }

    // for(map<string,string>::iterator it = videoAtts.begin(); it != videoAtts.end(); ++it) {
    //     cout << it->first << ": " << it->second << "\n";
    // }

    //cout << result << endl;

    return 0;
}
