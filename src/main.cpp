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

// TODO: Need to do the check for if there is no encoded date

vector<map<MediaDate, string>> runMap() {
    string dateKey = "Encoded date";
    vector<map<MediaDate, string>> mapped;
    string envString = getenvUtil("SORTER_PATH");
    vector<string> videoFiles = getFilesOfType(envString, ".mp4");// TODO: add multiple file types
    vector<map<string, string>> videoAtts;
    for (size_t i = 0; i < videoFiles.size(); i++)
    {
        MediaInfoCMD cmd("mediainfo " + videoFiles.at(i));
        info("Processing: {}", videoFiles.at(i));
        cmd.Exec();
        map<string, string> vidAtt = cmd.GetGeneralInfo();
        MediaDate date(vidAtt.at(dateKey));
        info("Date: {}", date.GetDateString());
    }

    return mapped;
}

int main() {
    info("Media Sorter started");
    // string dateKey = "Encoded date";
    // MediaInfoCMD cmd("mediainfo /home/tyler/Downloads/Project1_2019_06_22_1.mp4");

    // string result = cmd.Exec();
    // map<string, string> videoAtts = cmd.GetGeneralInfo();

    // MediaDate date(videoAtts.at(dateKey));
    // info("Video Record Date: {}", date.GetDateString());
    // string envStr = getenvUtil("SORTER_PATH");
    // string newFolder = envStr + "/" + date.GetDateString();
    // bool madeDir = mkdirUtil(newFolder);
    // vector<string> entries = getDirUtil(envStr);
    // for (size_t i = 0; i < entries.size(); i++)
    // {
    //     /* code */
    //     info("Entry ls: {}", entries.at(i));
    // }
    
    // info("Dir Made: {}", madeDir);
    // info("Environment: {}", envStr);
    // info("Dir made: {}", newFolder);

    // MediaMapper mapper;

    // boost::array<int, 4> arr;

    // for(map<string,string>::iterator it = videoAtts.begin(); it != videoAtts.end(); ++it) {
    //     cout << it->first << ": " << it->second << "\n";
    // }

    //cout << result << endl;

    runMap();

    return 0;
}
