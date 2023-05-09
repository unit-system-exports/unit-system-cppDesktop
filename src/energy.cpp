
#include "unit_system/energy.hpp"


using namespace sakurajin::unit_system;

energy::energy(): energy(0){}
energy::energy(unit_t<8> val): energy(val.value,val.multiplier){}
energy::energy(long double val): energy(val,1){}
energy::energy(long double val, long double mult ): unit_t<8>(val,mult){}
energy::energy(long double val, long double mult, long double offset ): unit_t<8>(val,mult,offset){}

std::ostream& ::sakurajin::unit_system::operator<<(std::ostream& os, const ::sakurajin::unit_system::energy& t){
    auto t1 = ::sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " Joules";
}




energy literals::operator "" _MJ(long double len){
    return energy{len,1000000.0, 0.0};
}

energy literals::operator "" _MJ(unsigned long long int len){
    return energy{static_cast<long double>(len),1000000.0, 0.0};
}



energy literals::operator "" _kJ(long double len){
    return energy{len,1000.0, 0.0};
}

energy literals::operator "" _kJ(unsigned long long int len){
    return energy{static_cast<long double>(len),1000.0, 0.0};
}



energy literals::operator "" _J(long double len){
    return energy{len,1.0, 0.0};
}

energy literals::operator "" _J(unsigned long long int len){
    return energy{static_cast<long double>(len),1.0, 0.0};
}



energy literals::operator "" _Nm(long double len){
    return energy{len,1.0, 0.0};
}

energy literals::operator "" _Nm(unsigned long long int len){
    return energy{static_cast<long double>(len),1.0, 0.0};
}



energy literals::operator "" _kWh(long double len){
    return energy{len,3600000.0, 0.0};
}

energy literals::operator "" _kWh(unsigned long long int len){
    return energy{static_cast<long double>(len),3600000.0, 0.0};
}



energy literals::operator "" _Wh(long double len){
    return energy{len,3600.0, 0.0};
}

energy literals::operator "" _Wh(unsigned long long int len){
    return energy{static_cast<long double>(len),3600.0, 0.0};
}



energy literals::operator "" _GeV(long double len){
    return energy{len,1.602176565e-10, 0.0};
}

energy literals::operator "" _GeV(unsigned long long int len){
    return energy{static_cast<long double>(len),1.602176565e-10, 0.0};
}



energy literals::operator "" _MeV(long double len){
    return energy{len,1.602176565e-13, 0.0};
}

energy literals::operator "" _MeV(unsigned long long int len){
    return energy{static_cast<long double>(len),1.602176565e-13, 0.0};
}



energy literals::operator "" _keV(long double len){
    return energy{len,1.602176565e-16, 0.0};
}

energy literals::operator "" _keV(unsigned long long int len){
    return energy{static_cast<long double>(len),1.602176565e-16, 0.0};
}



energy literals::operator "" _eV(long double len){
    return energy{len,1.602176565e-19, 0.0};
}

energy literals::operator "" _eV(unsigned long long int len){
    return energy{static_cast<long double>(len),1.602176565e-19, 0.0};
}


