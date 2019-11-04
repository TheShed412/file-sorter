#ifndef T_MAPPER
#define T_MAPPER
//TODO: might need special destructors anmd stuff
template <class T, class U>
class Mapper{
    public:
        virtual void map(T key, U value) = 0;
};

#endif