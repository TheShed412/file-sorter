#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <boost/array.hpp>

#include "MediaInfoCMD.hpp"
#include "MediaDate.hpp"
#include "SystemUtils.hpp"
#include "spdlog/spdlog.h"
#include "MediaMapper.hpp"



using namespace std;
using namespace spdlog;

string getInfo(const char* cmd);

int main() {
    info("Media Sorter started");
    string dateKey = "Encoded date";
    MediaInfoCMD cmd("mediainfo /home/tyler/Downloads/Project1_2019_06_22_1.mp4");

    string result = cmd.Exec();
    map<string, string> videoAtts = cmd.GetGeneralInfo();

    MediaDate date(videoAtts.at(dateKey));
    info("Video Record Date: {}", date.GetDateString());
    string envStr = getenvUtil("SORTER_PATH");
    bool madeDir = mkdirUtil(envStr + "/test");
    vector<string> entries = lsUtil(envStr);
    info("Environment: {}", envStr);
    info("Dir made: {}", envStr);

    MediaMapper mapper;

    boost::array<int, 4> arr;

    // for(map<string,string>::iterator it = videoAtts.begin(); it != videoAtts.end(); ++it) {
    //     cout << it->first << ": " << it->second << "\n";
    // }

    //cout << result << endl;

    return 0;
}
