#include "ExecCMD.hpp"
#include <sstream>
#include <iterator> 

ExecCMD::ExecCMD(){}

ExecCMD::ExecCMD(vector<string> args) {
    this->args = args;
}

ExecCMD::ExecCMD(string args) {
    this->args = GetVectorFromString(args);
}

void ExecCMD::SetArgs(vector<string> args){
    this->args = args;
}

void ExecCMD::AddArgs(vector<string> args){

}

void ExecCMD::SetArgs(string args){
    this->args = GetVectorFromString(args);
}

void ExecCMD::AddArgs(string args){

}

vector<string> ExecCMD::GetArgs() {
    return vector<string>(args);
}

string ExecCMD::Exec() {
    char buffer[128];//TODO: make this a configuration from compilation
    string cmd = GetStringFromVector(this->args);
    std::string result = "";
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

string ExecCMD::GetStringFromVector(vector<string> args) {
    std::ostringstream vts;
    std::copy(args.begin(), args.end(), 
        std::ostream_iterator<string>(vts, " "));

    return vts.str();
}

vector<string> ExecCMD::GetVectorFromString(string strArgs){
    stringstream arg_stream(strArgs);

    vector<string> args;
    string temp;
    while(arg_stream >> temp) {
        args.push_back(temp);
    }

    return args;
}