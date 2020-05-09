#include "SystemUtils.hpp"
#include "spdlog/spdlog.h"
#include <cstdlib>
#include <iostream>
#include <ios>
#include <fstream>
#include <cstdio>
#include <dirent.h>
#include <bits/stdc++.h>
#include <sys/stat.h> 
#include <sys/types.h> 

bool mvUtil(string srcLoc, string destLoc) {
    ifstream in(srcLoc, std::ios::in | std::ios::binary);
    ofstream out(destLoc, std::ios::out | std::ios::binary);
    if(in && out) {
        out << in.rdbuf();
    } else {
        spdlog::error("Failed onpening files");
        spdlog::error("Source: {}", srcLoc);
        spdlog::error("Dest: {}", destLoc);

        return false;
    }

    // TODO: a check at the new location to make sure it exists before removing
    remove(srcLoc.c_str());
    return true;
}

/*
    This is just returning the dirs now, might make one that returns everything from ls in the future
*/
vector<string> getDirUtil(string dirName) {
    vector<string> dirents;

    struct dirent *entry;
    DIR *dir = opendir(dirName.c_str());
    
    if (dir == NULL) {
        return dirents;
    }
    while ((entry = readdir(dir)) != NULL) {
        if(entry->d_type == DT_DIR) {
            dirents.push_back(string(entry->d_name));
        }
    }

    return dirents;
}

vector<string> lsUtil(string dirName) {
    vector<string> dirents;

    struct dirent *entry;
    DIR *dir = opendir(dirName.c_str());
    
    if (dir == NULL) {
        return dirents;
    }
    while ((entry = readdir(dir)) != NULL) {
        dirents.push_back(string(entry->d_name));
    }

    return dirents;
}

vector<string> getFilesOfType(string dirName, string extension) {
    vector<string> files;

    vector<string> allFiles = lsUtil(dirName);

    for (size_t i = 0; i < allFiles.size(); i++)
    {
        if(allFiles.at(i).find(extension) != string::npos){
            files.push_back(dirName + "/" + allFiles.at(i));
        }
    }

    return files;
}

int mkdirUtil(string dirName) {
    const char* dirNameC = dirName.c_str();
    int dirRet = mkdir(dirNameC, 0777);
    return dirRet;
}

string getenvUtil(string envVarName) {
    const char* envVarNameArr = envVarName.c_str();
    char* envVarArr = getenv(envVarNameArr);

    if(envVarArr != NULL) {
        string envStr(envVarArr);
        return envStr;
    } else {
        return "NOVAR";
    }
}