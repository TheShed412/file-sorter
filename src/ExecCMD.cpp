#include "ExecCMD.hpp"
#include <sstream>

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

vector<string> ExecCMD::GetVectorFromString(string strArgs){
    stringstream arg_stream(strArgs);

    vector<string> args;
    string temp;
    while(arg_stream >> temp) {
        args.push_back(temp);
    }

    return args;
}