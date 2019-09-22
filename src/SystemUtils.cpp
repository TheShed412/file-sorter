#include "SystemUtils.hpp"
#include <cstdlib>

bool mkdirUtil(string dirName) {
    return false;
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