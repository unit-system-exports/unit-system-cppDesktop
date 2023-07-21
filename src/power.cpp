
#include "unit_system/power.hpp"


using namespace sakurajin::unit_system;

power::power(): power(0){}
power::power(unit_t<801> val): power(val.value,val.multiplier){}
power::power(long double val): power(val,1){}
power::power(long double val, long double mult ): unit_t<801>(val,mult){}
power::power(long double val, long double mult, long double offset ): unit_t<801>(val,mult,offset){}

std::ostream& ::sakurajin::unit_system::operator<<(std::ostream& os, const ::sakurajin::unit_system::power& t){
    auto t1 = ::sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " power";
}




power literals::operator "" _W(long double len){
    return power{len,1.0, 0.0};
}

power literals::operator "" _W(unsigned long long int len){
    return power{static_cast<long double>(len),1.0, 0.0};
}



power literals::operator "" _PW(long double len){
    return power{len,1000000000000000.0, 0.0};
}

power literals::operator "" _PW(unsigned long long int len){
    return power{static_cast<long double>(len),1000000000000000.0, 0.0};
}



power literals::operator "" _TW(long double len){
    return power{len,1000000000000.0, 0.0};
}

power literals::operator "" _TW(unsigned long long int len){
    return power{static_cast<long double>(len),1000000000000.0, 0.0};
}



power literals::operator "" _GW(long double len){
    return power{len,1000000000.0, 0.0};
}

power literals::operator "" _GW(unsigned long long int len){
    return power{static_cast<long double>(len),1000000000.0, 0.0};
}



power literals::operator "" _MW(long double len){
    return power{len,1000000.0, 0.0};
}

power literals::operator "" _MW(unsigned long long int len){
    return power{static_cast<long double>(len),1000000.0, 0.0};
}



power literals::operator "" _kW(long double len){
    return power{len,1000.0, 0.0};
}

power literals::operator "" _kW(unsigned long long int len){
    return power{static_cast<long double>(len),1000.0, 0.0};
}



power literals::operator "" _mW(long double len){
    return power{len,0.001, 0.0};
}

power literals::operator "" _mW(unsigned long long int len){
    return power{static_cast<long double>(len),0.001, 0.0};
}



power literals::operator "" _uW(long double len){
    return power{len,1e-06, 0.0};
}

power literals::operator "" _uW(unsigned long long int len){
    return power{static_cast<long double>(len),1e-06, 0.0};
}



power literals::operator "" _nW(long double len){
    return power{len,1e-09, 0.0};
}

power literals::operator "" _nW(unsigned long long int len){
    return power{static_cast<long double>(len),1e-09, 0.0};
}



power literals::operator "" _pW(long double len){
    return power{len,1e-12, 0.0};
}

power literals::operator "" _pW(unsigned long long int len){
    return power{static_cast<long double>(len),1e-12, 0.0};
}



power literals::operator "" _fW(long double len){
    return power{len,1e-15, 0.0};
}

power literals::operator "" _fW(unsigned long long int len){
    return power{static_cast<long double>(len),1e-15, 0.0};
}



power literals::operator "" _aW(long double len){
    return power{len,1e-18, 0.0};
}

power literals::operator "" _aW(unsigned long long int len){
    return power{static_cast<long double>(len),1e-18, 0.0};
}


