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

// mapper maps MediaDates to file paths
vector<std::pair<MediaDate, string>> runMap() {
    string dateKey = "Encoded date";
    vector<std::pair<MediaDate, string>> mapped;
    string envString = getenvUtil("SORTER_PATH");
    vector<string> videoFiles = getFilesOfType(envString, ".mp4");// TODO: add multiple file types
    vector<map<string, string>> videoAtts;
    for (size_t i = 0; i < videoFiles.size(); i++)
    {
        string videoFile = videoFiles.at(i);
        MediaInfoCMD cmd("mediainfo " + videoFile);
        info("Processing: {}", videoFile);
        cmd.Exec();
        map<string, string> vidAtt = cmd.GetGeneralInfo();
        MediaDate date(vidAtt.at(dateKey));// TODO: Need to do the check for if there is no encoded date
        info("Date: {}", date.GetDateString());
        std::pair<MediaDate, string> dateFile(date, videoFile);
        mapped.push_back(dateFile);
    }

    return mapped;
}

// TODO: Need to add operator to MediaDate, also this is actually the reducer lol
// Combiner combines all files with specific dates in to a list, and keeps each one in a map
map<string, vector<string>> combiner(vector<std::pair<MediaDate, string>> dateFileList) {
    map<string, vector<string>>  dateFilesMap;
    string currDate;
    string currFile;

    for (size_t i = 0; i < dateFileList.size(); i++)
    {
        currDate = dateFileList.at(i).first.GetDateString();
        currFile = dateFileList.at(i).second;

        if(dateFilesMap.find(currDate) != dateFilesMap.end()) {
            info("Found date, adding another file");
            dateFilesMap.at(currDate).push_back(currFile);
        } else {
            info("Adding new date: {}", currDate);
            vector<string> newList;
            newList.push_back(currFile);
            dateFilesMap.insert({currDate, newList});
        }
    }
    
    return dateFilesMap;
}

// Reducer actually makes the folders and moves the files
void reducer(map<string, vector<string>> dateFilesMap) {
    string newDir;
    string dirPath;
    vector<string> newFiles;
    string newFile;
    string envStr = getenvUtil("SORTER_PATH");

    map<string, vector<string>>::iterator it;

    for ( it = dateFilesMap.begin(); it != dateFilesMap.end(); it++ )
    {
        newDir = it->first;
        newFiles = it->second;
        dirPath = envStr + "/" + newDir;
        int madeDir = mkdirUtil(dirPath);
        
        // If the dir was made successfully or it already exists
        if(madeDir == 0 || madeDir == EEXIST) {

            for (size_t i = 0; i < newFiles.size(); i++)
            {
                // TODO: need to make an object that I can easily get the file name sans-path
                newFile = newFiles.at(i);
                string fileName = newFile.substr(newFile.rfind("/"));
                info("Filename: {}", fileName);
                mvUtil(newFile, dirPath + fileName);
            }
            

        } else {
            error("Issue making dir");
        }

    }
    
}

int main() {
    info("Media Sorter started");

    vector<std::pair<MediaDate, string>> dateMap = runMap();
    map<string, vector<string>> combinedShit = combiner(dateMap);
    reducer(combinedShit);

    return 0;
}
