#include "length.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::prefix;

length::length(long double val): unit_t<2>(val){}
length::length(long double val, long double mult): unit_t<2>(val,mult){}

length literals::operator "" _km(long double len){
    return length{len, kilo};
}

length literals::operator "" _m(long double len){
    return length{len, 1};
}

length literals::operator "" _dm(long double len){
    return length{len,deci};
}

length literals::operator "" _cm(long double len){
    return length{len,centi};
}

length literals::operator "" _mm(long double len){
    return length{len,milli};
}

length literals::operator "" _um(long double len){
    return length{len,micro};
}

length literals::operator "" _nm(long double len){
    return length{len,nano};
}

