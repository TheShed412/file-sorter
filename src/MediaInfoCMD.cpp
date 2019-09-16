#include "MediaInfoCMD.hpp"
#include <iostream>

string MediaInfoCMD::Exec() {
    string result = ExecCMD::Exec();

    executed = true;
    return result;
}