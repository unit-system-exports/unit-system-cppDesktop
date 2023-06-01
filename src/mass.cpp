
#include "unit_system/mass.hpp"


using namespace sakurajin::unit_system;

mass::mass(): mass(0){}
mass::mass(unit_t<3> val): mass(val.value,val.multiplier){}
mass::mass(long double val): mass(val,1){}
mass::mass(long double val, long double mult ): unit_t<3>(val,mult){}
mass::mass(long double val, long double mult, long double offset ): unit_t<3>(val,mult,offset){}

std::ostream& ::sakurajin::unit_system::operator<<(std::ostream& os, const ::sakurajin::unit_system::mass& t){
    auto t1 = ::sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " kilogram";
}




mass literals::operator "" _t(long double len){
    return mass{len,1000.0, 0.0};
}

mass literals::operator "" _t(unsigned long long int len){
    return mass{static_cast<long double>(len),1000.0, 0.0};
}



mass literals::operator "" _kg(long double len){
    return mass{len,1.0, 0.0};
}

mass literals::operator "" _kg(unsigned long long int len){
    return mass{static_cast<long double>(len),1.0, 0.0};
}



mass literals::operator "" _g(long double len){
    return mass{len,0.001, 0.0};
}

mass literals::operator "" _g(unsigned long long int len){
    return mass{static_cast<long double>(len),0.001, 0.0};
}



mass literals::operator "" _mg(long double len){
    return mass{len,1e-06, 0.0};
}

mass literals::operator "" _mg(unsigned long long int len){
    return mass{static_cast<long double>(len),1e-06, 0.0};
}



mass literals::operator "" _ug(long double len){
    return mass{len,1e-09, 0.0};
}

mass literals::operator "" _ug(unsigned long long int len){
    return mass{static_cast<long double>(len),1e-09, 0.0};
}



mass literals::operator "" _ng(long double len){
    return mass{len,1.0000000000000002e-12, 0.0};
}

mass literals::operator "" _ng(unsigned long long int len){
    return mass{static_cast<long double>(len),1.0000000000000002e-12, 0.0};
}



mass literals::operator "" _pg(long double len){
    return mass{len,1e-15, 0.0};
}

mass literals::operator "" _pg(unsigned long long int len){
    return mass{static_cast<long double>(len),1e-15, 0.0};
}



mass literals::operator "" _fg(long double len){
    return mass{len,1e-18, 0.0};
}

mass literals::operator "" _fg(unsigned long long int len){
    return mass{static_cast<long double>(len),1e-18, 0.0};
}



mass literals::operator "" _ag(long double len){
    return mass{len,1.0000000000000001e-21, 0.0};
}

mass literals::operator "" _ag(unsigned long long int len){
    return mass{static_cast<long double>(len),1.0000000000000001e-21, 0.0};
}


