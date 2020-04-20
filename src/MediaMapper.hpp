#ifndef T_MAPPER_Media
#define T_MAPPER_Media

#include <string>
#include <map>

#include "Mapper.hpp"
#include "MediaDate.hpp"

using namespace std;

/**
 * 
*/
class MediaMapper : public Mapper<string, string, MediaDate, string>{
    public:
        map<MediaDate, string> doMapping(string key, string value) override;
};

#endif