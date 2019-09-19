#include "MediaInfoCMD.hpp"
#include <iostream>
#include <sstream>
#include <iterator>
#include <locale>
#include <functional>
#include <algorithm>

string MediaInfoCMD::Exec() {
    string result = ExecCMD::Exec();

    vector<string> mediaBlocks = splitBlocks(result, "\n\n");
    //vector<string> mediaLines = splitBlocks(mediaBlocks, "\n");
    vector<string> clearedWhiteSpace = clearWhiteSpaceInVector(mediaBlocks);

    cout << "::::::::::: BLOCKS ::::::::::::::" << endl;
    for(string str : clearedWhiteSpace) {
        cout << "::::::::::: BLOCK ::::::::::::::" << endl;
        cout << str << endl;
        cout << "::::::::::: BLOCK ::::::::::::::" << endl;
    }
    cout << "::::::::::: BLOCKS ::::::::::::::" << endl;

    executed = true;
    return result;
}

vector<string> MediaInfoCMD::clearWhiteSpaceInVector(vector<string> blocks){
    vector<string> clearedWhiteSpace;

    for(string str : blocks) {
        clearedWhiteSpace.push_back(clearWhiteSpace(str));
    }

    return clearedWhiteSpace;
}

string MediaInfoCMD::clearWhiteSpace(string str) {
    string localStr(str);

    localStr.erase(remove_if(
        localStr.begin(),
        localStr.end(),
        bind(isspace<char>,
            placeholders::_1,
            locale::classic())
    ), localStr.end());

    return localStr;
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