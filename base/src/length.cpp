#include "length.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::prefix;

length::length(long double val): unit_t<2>(val){}
length::length(long double val, long double mult): unit_t<2>(val,mult){}

length operator "" _km(long double len){
    return length{len, kilo};
}

length operator "" _m(long double len){
    return length{len, 1};
}

length operator "" _dm(long double len){
    return length{len,deci};
}

length operator "" _cm(long double len){
    return length{len,centi};
}

length operator "" _mm(long double len){
    return length{len,milli};
}

length operator "" _um(long double len){
    return length{len,micro};
}

length operator "" _nm(long double len){
    return length{len,nano};
}

