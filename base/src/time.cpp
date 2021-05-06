#include "time.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::prefix;

time_si::time_si(long double val): unit_t<1>(val){}
time_si::time_si(long double val, long double mult): unit_t<1>(val,mult){}

time_si sakurajin::unit_system::unit_cast(const time_si& other, long double new_multiplier){
    auto v1 = sakurajin::unit_system::unit_cast(static_cast<unit_t<1>>(other), new_multiplier);
    return time_si{v1.value,v1.multiplier};
}

std::ostream& sakurajin::unit_system::base::operator<<(std::ostream& os, const time_si& t){
    auto t1 = sakurajin::unit_system::unit_cast(t,1,0);
    return os << t1.value << " seconds";
}

time_si literals::operator "" _a(long double len){
    return time_si(len,365.25*24.0*60.0*60.0);
}

time_si literals::operator "" _d(long double len){
    return time_si(len,24.0*60.0*60.0);
}

time_si literals::operator "" _h(long double len){
    return time_si(len,60.0*60.0);
}

time_si literals::operator "" _min(long double len){
    return time_si(len,60.0);
}

time_si literals::operator "" _s(long double len){
    return time_si(len,1);
}

time_si literals::operator "" _ms(long double len){
    return time_si(len,milli);
}

time_si literals::operator "" _us(long double len){
    return time_si(len,micro);
}

time_si literals::operator "" _ns(long double len){
    return time_si(len,nano);
}

time_si literals::operator "" _fs(long double len){
    return time_si(len,femto);
}



time_si literals::operator "" _a(unsigned long long int len){
    return time_si(len,365.25*24.0*60.0*60.0);
}

time_si literals::operator "" _d(unsigned long long int len){
    return time_si(len,24.0*60.0*60.0);
}

time_si literals::operator "" _h(unsigned long long int len){
    return time_si(len,60.0*60.0);
}

time_si literals::operator "" _min(unsigned long long int len){
    return time_si(len,60.0);
}

time_si literals::operator "" _s(unsigned long long int len){
    return time_si(len,1);
}

time_si literals::operator "" _ms(unsigned long long int len){
    return time_si(len,milli);
}

time_si literals::operator "" _us(unsigned long long int len){
    return time_si(len,micro);
}

time_si literals::operator "" _ns(unsigned long long int len){
    return time_si(len,nano);
}

time_si literals::operator "" _fs(unsigned long long int len){
    return time_si(len,femto);
}
