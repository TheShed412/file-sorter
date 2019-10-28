#include "SystemUtils.hpp"
#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>
#include <sys/stat.h> 
#include <sys/types.h> 

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