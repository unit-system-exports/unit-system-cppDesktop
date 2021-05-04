#include "time.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::prefix;

time::time(long double val): unit_t<1>(val){}
time::time(long double val, long double mult): unit_t<1>(val,mult){}

time operator "" _a(long double len){
    return time(len,365.25*24.0*60.0*60.0);
}

time operator "" _d(long double len){
    return time(len,24.0*60.0*60.0);
}

time operator "" _h(long double len){
    return time(len,60.0*60.0);
}

time operator "" _min(long double len){
    return time(len,60.0);
}

time operator "" _s(long double len){
    return time(len,1);
}

time operator "" _ms(long double len){
    return time(len,milli);
}

time operator "" _us(long double len){
    return time(len,micro);
}

time operator "" _ns(long double len){
    return time(len,nano);
}

time operator "" _fs(long double len){
    return time(len,femto);
}

