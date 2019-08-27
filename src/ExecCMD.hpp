#ifndef EXEC_CMD
#define EXEC_CMD

#include <vector>
#include <string>

using namespace std;

class ExecCMD {
    public:
        vector<string> args;
        ExecCMD(vector<string> args);
        ExecCMD(string args);
        void SetArgs(vector<string> args);
        void AddArgs(vector<string> args);
        void SetArgs(string args);
        void AddArgs(string args);
        string Exec();
};

#endif