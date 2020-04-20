#ifndef SYS_UTL
#define SYS_UTL

#include <string>
#include <vector>

using namespace std;

bool mkdirUtil(string);
bool mvUtil(string, string);
string getenvUtil(string);
vector<string> lsUtil(string);
vector<string> getDirUtil(string);
vector<string> getFilesOfType(string dirName, string extension);

#endif