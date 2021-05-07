#include "length.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::prefix;

length::length(long double val): unit_t<2>(val){}
length::length(long double val, long double mult): unit_t<2>(val,mult){}

length sakurajin::unit_system::unit_cast(const length& other, long double new_multiplier){
    auto v1 = sakurajin::unit_system::unit_cast(static_cast<unit_t<2>>(other), new_multiplier);
    return length{v1.value,v1.multiplier};
}

std::ostream& ::sakurajin::unit_system::base::operator<<(std::ostream& os, const length& s){
    auto s1 = sakurajin::unit_system::unit_cast(s,1);
    return os << s1.value << " meter";
}

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



length literals::operator "" _km(unsigned long long int len){
    return length{static_cast<long double>(len), kilo};
}

length literals::operator "" _m(unsigned long long int len){
    return length{static_cast<long double>(len), 1};
}

length literals::operator "" _dm(unsigned long long int len){
    return length{static_cast<long double>(len),deci};
}

length literals::operator "" _cm(unsigned long long int len){
    return length{static_cast<long double>(len),centi};
}

length literals::operator "" _mm(unsigned long long int len){
    return length{static_cast<long double>(len),milli};
}

length literals::operator "" _um(unsigned long long int len){
    return length{static_cast<long double>(len),micro};
}

length literals::operator "" _nm(unsigned long long int len){
    return length{static_cast<long double>(len),nano};
}
