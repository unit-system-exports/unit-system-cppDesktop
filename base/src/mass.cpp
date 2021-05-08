#include "mass.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::prefix;

mass::mass(): mass(0){}
mass::mass(long double val): mass(val,1){}
mass::mass(long double val, long double mult): unit_t<3>(val,mult){}

mass sakurajin::unit_system::unit_cast(const mass& other, long double new_multiplier){
    auto v1 = sakurajin::unit_system::unit_cast(static_cast<unit_t<3>>(other), new_multiplier);
    return mass{v1.value,v1.multiplier};
}

std::ostream& ::sakurajin::unit_system::base::operator<<(std::ostream& os, const mass& s){
    auto s1 = sakurajin::unit_system::unit_cast(s,1);
    return os << s1.value << " meter";
}

mass literals::operator "" _kg(long double len){
    return mass{len, 1};
}

mass literals::operator "" _g(long double len){
    return mass{len, milli};
}

mass literals::operator "" _mg(long double len){
    return mass{len, micro};
}

mass literals::operator "" _ug(long double len){
    return mass{len, nano};
}

mass literals::operator "" _t(long double len){
    return mass{len, kilo};
}



mass literals::operator "" _kg(unsigned long long int len){
    return mass{static_cast<long double>(len), 1};
}

mass literals::operator "" _g(unsigned long long int len){
    return mass{static_cast<long double>(len), milli};
}

mass literals::operator "" _mg(unsigned long long int len){
    return mass{static_cast<long double>(len), micro};
}

mass literals::operator "" _ug(unsigned long long int len){
    return mass{static_cast<long double>(len), nano};
}

mass literals::operator "" _t(unsigned long long int len){
    return mass{static_cast<long double>(len), kilo};
}

