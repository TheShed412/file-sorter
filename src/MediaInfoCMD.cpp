#include "MediaInfoCMD.hpp"
#include <iostream>
#include <sstream>
#include <iterator> 

string MediaInfoCMD::Exec() {
    string result = ExecCMD::Exec();

    vector<string> mediaBlocks = splitBlocks(result, "\n\n");

    executed = true;
    return result;
}

vector<string> MediaInfoCMD::splitBlocks(string stringBlocks, string delimeter) {
    vector<string> splittedString;
    int startIndex = 0;
    int  endIndex = 0;
    while( (endIndex = stringBlocks.find(delimeter, startIndex)) < stringBlocks.size() )
    {
        string val = stringBlocks.substr(startIndex, endIndex - startIndex);
        splittedString.push_back(val);
        startIndex = endIndex + delimeter.size();
    }
    if(startIndex < stringBlocks.size())
    {
        string val = stringBlocks.substr(startIndex);
        splittedString.push_back(val);
    }
    return splittedString;
}