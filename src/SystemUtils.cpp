#include "SystemUtils.hpp"
#include <cstdlib>
#include <iostream>
#include <dirent.h>
#include <bits/stdc++.h>
#include <sys/stat.h> 
#include <sys/types.h> 


vector<string> lsUtil(string dirName) {
    vector<string> dirents;

    struct dirent *entry;
    DIR *dir = opendir(dirName.c_str());
    
    if (dir == NULL) {
        return dirents;
    }
    while ((entry = readdir(dir)) != NULL) {
        cout << entry->d_name << endl;
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