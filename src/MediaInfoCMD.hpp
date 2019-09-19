#ifndef MEDIA_CMD
#define MEDIA_CMD

#include "ExecCMD.hpp"
#include <map>
#include <string>

class MediaInfoCMD : public ExecCMD {
    
    private:
    bool executed = false;
    map<string, string> general;
    map<string, string> video;
    map<string, string> audio;
    map<string, string> text;
    vector<string> splitBlocks(string stringBlocks, string delimeter);
    string clearWhiteSpace(string str);
    vector<string> clearWhiteSpaceInVector(vector<string> blocks);
    map<string, vector<string>> makeTypeMap(vector<string> mediaBlocks);
    vector<string> clearWhiteSpace(vector<string> str);

    /**
     * I'll want to make the parsing happen in the exec
     * Call super exec first, then parse for maps
    */
    public:
        MediaInfoCMD() : ExecCMD(){}
        MediaInfoCMD(vector<string> args) : ExecCMD(args){}
        MediaInfoCMD(string args) : ExecCMD(args){}
        string Exec();
        map<string, string> GetGeneralInfo();
        map<string, string> GetVideoInfo();
        map<string, string> GetAudioInfo();
        map<string, string> GetTextInfo();
         

};

#endif