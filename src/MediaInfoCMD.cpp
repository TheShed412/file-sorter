#include "MediaInfoCMD.hpp"
#include <iostream>
#include <sstream>
#include <iterator>
#include <locale>
#include <functional>
#include <algorithm>
#include <map>

string MediaInfoCMD::Exec() {
    string result = ExecCMD::Exec();

    vector<string> mediaBlocks = splitBlocks(result, "\n\n");
    map<string, vector<string>> typeMap = makeTypeMap(mediaBlocks);
    // typeMap is mapping type to a list of attributes
    /**
     * make each vector a map of attributes
    */
    general = makeAttributeMap(typeMap["General"]);
    video = makeAttributeMap(typeMap["Video"]);
    audio = makeAttributeMap(typeMap["Audio"]);
    text = makeAttributeMap(typeMap["Text"]);

    executed = true;
    return result;
}

map<string, string> MediaInfoCMD::makeAttributeMap(vector<string> attributeVector) {
    map<string, string> attributeMap;

    for(string attributeString : attributeVector) {
        vector<string> attributes = splitBlocks(attributeString, ";");
        attributeMap[attributes.at(0)] = attributes.at(1);
    }

    return attributeMap;
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

vector<string> MediaInfoCMD::clearWhiteSpace(vector<string> strs) {
    vector<string> clearedWhiteSpace;

    for(string str : strs) {
        cout << "BEFORE WHITE SPAC: " << str << endl;
        string noWhiteSpace = clearWhiteSpace(str);
        clearedWhiteSpace.push_back(noWhiteSpace);
    }

    return clearedWhiteSpace;
}

vector<string> MediaInfoCMD::makeValue(vector<string> strs) {
    vector<string> clearedWhiteSpace;

    for(string str : strs) {
        string value = str.substr(str.find(": ") + 2);
        string key = rtrim(splitBlocks(str, ":").at(0));
        clearedWhiteSpace.push_back(key + ";" + value);
    }

    return clearedWhiteSpace;
}

string MediaInfoCMD::rtrim(std::string s) {
    string localStr(s);
    localStr.erase(std::find_if(localStr.rbegin(), localStr.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), localStr.end());
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

map<string, vector<string>> MediaInfoCMD::makeTypeMap(vector<string> mediaBlocks) {
    map<string, vector<string>> typeMap;

    for(string block : mediaBlocks) {
        vector<string> blockLines = splitBlocks(block, "\n");
        string key = blockLines.front();
        blockLines.erase(blockLines.begin());
        typeMap[key] = makeValue(blockLines);
    }
    cout << "MADE MAP" << endl;
    return typeMap;
}

map<string, string> MediaInfoCMD::GetGeneralInfo() {
    return general;
}

map<string, string> MediaInfoCMD::GetVideoInfo(){
    return video;
}

map<string, string> MediaInfoCMD::GetAudioInfo(){
    return audio;
}

map<string, string> MediaInfoCMD::GetTextInfo(){
    return text;
}