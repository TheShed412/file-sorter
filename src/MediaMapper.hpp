#ifndef T_MAPPER_Media
#define T_MAPPER_Media

#include <string>
#include <map>

#include "Mapper.hpp"

using namespace std;

/**
 * 
*/
class MediaMapper : public Mapper<string, string, string, string>{
    public:
        map<string, string> doMapping(string key, string value) override;
};

#endif