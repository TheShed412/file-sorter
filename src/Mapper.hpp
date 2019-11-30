#ifndef T_MAPPER
#define T_MAPPER

#include <string>
#include <map>

using namespace std;
//TODO: might need special destructors anmd stuff
template <class T, class U, class V, class X>
class Mapper{
    public:
        virtual map<V, X>  doMapping(T key, U value) = 0;
};

#endif