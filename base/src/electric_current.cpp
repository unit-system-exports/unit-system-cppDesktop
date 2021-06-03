#include "electric_current.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::prefix;

electric_current::electric_current(): electric_current(0){}
electric_current::electric_current(unit_t<6> val): electric_current(val.value,val.multiplier){}
electric_current::electric_current(long double val): electric_current(val,1){}
electric_current::electric_current(long double val, long double mult): unit_t<6>(val,mult){}

std::ostream& ::sakurajin::unit_system::base::operator<<(std::ostream& os, const electric_current& I){
    auto I1 = ::sakurajin::unit_system::unit_cast(I,1);
    return os << I1.value << " Ampere";
}

electric_current literals::operator "" _MA(long double len){
    return electric_current{len, mega};
}

electric_current literals::operator "" _kA(long double len){
    return electric_current{len, kilo};
}

electric_current literals::operator "" _A(long double len){
    return electric_current{len, 1};
}

electric_current literals::operator "" _mA(long double len){
    return electric_current{len,milli};
}

electric_current literals::operator "" _uA(long double len){
    return electric_current{len,micro};
}

electric_current literals::operator "" _nA(long double len){
    return electric_current{len,nano};
}



electric_current literals::operator "" _MA(unsigned long long int len){
    return electric_current{static_cast<long double>(len), mega};
}

electric_current literals::operator "" _kA(unsigned long long int len){
    return electric_current{static_cast<long double>(len), kilo};
}

electric_current literals::operator "" _A(unsigned long long int len){
    return electric_current{static_cast<long double>(len), 1};
}

electric_current literals::operator "" _mA(unsigned long long int len){
    return electric_current{static_cast<long double>(len),milli};
}

electric_current literals::operator "" _uA(unsigned long long int len){
    return electric_current{static_cast<long double>(len),micro};
}

electric_current literals::operator "" _nA(unsigned long long int len){
    return electric_current{static_cast<long double>(len),nano};
}
