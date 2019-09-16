#ifndef EXEC_CMD
#define EXEC_CMD

#include <vector>
#include <string>

using namespace std;

class ExecCMD {
    public:
        vector<string> args;

        ExecCMD();
        ExecCMD(vector<string> args);
        ExecCMD(string args);
        void SetArgs(vector<string> args);
        void AddArgs(vector<string> args);
        void SetArgs(string args);
        void AddArgs(string args);
        vector<string> GetArgs();
        string Exec();
    private:
        vector<string> GetVectorFromString(string strArgs);
        string GetStringFromVector(vector<string> args);
};

#endif