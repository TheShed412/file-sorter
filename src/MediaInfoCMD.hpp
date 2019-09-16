#ifndef MEDIA_CMD
#define MEDIA_CMD

#include "ExecCMD.hpp"

class MediaInfoCMD : public ExecCMD {

    public:
        MediaInfoCMD() : ExecCMD(){}
        MediaInfoCMD(vector<string> args) : ExecCMD(args){}
        MediaInfoCMD(string args) : ExecCMD(args){}

};

#endif