#include "SystemUtils.hpp"
#include <cstdlib>
#include <iostream>
#include <ios>
#include <fstream>
#include <cstdio>
#include <dirent.h>
#include <bits/stdc++.h>
#include <sys/stat.h> 
#include <sys/types.h> 

//TODO: needs error catching and stuff
bool mvUtil(string srcLoc, string destLoc) {
    ifstream in(srcLoc, std::ios::in | std::ios::binary);
    ofstream out(destLoc, std::ios::out | std::ios::binary);
    out << in.rdbuf();
    remove(srcLoc.c_str());
    return true;
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

bool mkdirUtil(string dirName) {
    const char* dirNameC = dirName.c_str();

    if (mkdir(dirNameC, 0777) == -1) {
        return false;
    }

    return true;
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