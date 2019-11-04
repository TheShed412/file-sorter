#ifndef T_MAPPER_Media
#define T_MAPPER_Media

#include <string>
#include "Mapper.hpp"

using namespace std;

class MediaMapper : public Mapper<string, string>{
    public:
        void map(string key, string value) override;
};

#endif