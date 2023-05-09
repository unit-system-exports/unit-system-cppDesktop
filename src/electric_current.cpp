
#include "unit_system/electric_current.hpp"


using namespace sakurajin::unit_system;

electric_current::electric_current(): electric_current(0){}
electric_current::electric_current(unit_t<6> val): electric_current(val.value,val.multiplier){}
electric_current::electric_current(long double val): electric_current(val,1){}
electric_current::electric_current(long double val, long double mult ): unit_t<6>(val,mult){}
electric_current::electric_current(long double val, long double mult, long double offset ): unit_t<6>(val,mult,offset){}

std::ostream& ::sakurajin::unit_system::operator<<(std::ostream& os, const ::sakurajin::unit_system::electric_current& t){
    auto t1 = ::sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " Ampere";
}




electric_current literals::operator "" _MA(long double len){
    return electric_current{len,1000000.0, 0.0};
}

electric_current literals::operator "" _MA(unsigned long long int len){
    return electric_current{static_cast<long double>(len),1000000.0, 0.0};
}



electric_current literals::operator "" _kA(long double len){
    return electric_current{len,1000.0, 0.0};
}

electric_current literals::operator "" _kA(unsigned long long int len){
    return electric_current{static_cast<long double>(len),1000.0, 0.0};
}



electric_current literals::operator "" _A(long double len){
    return electric_current{len,1.0, 0.0};
}

electric_current literals::operator "" _A(unsigned long long int len){
    return electric_current{static_cast<long double>(len),1.0, 0.0};
}



electric_current literals::operator "" _mA(long double len){
    return electric_current{len,0.001, 0.0};
}

electric_current literals::operator "" _mA(unsigned long long int len){
    return electric_current{static_cast<long double>(len),0.001, 0.0};
}



electric_current literals::operator "" _uA(long double len){
    return electric_current{len,1e-06, 0.0};
}

electric_current literals::operator "" _uA(unsigned long long int len){
    return electric_current{static_cast<long double>(len),1e-06, 0.0};
}



electric_current literals::operator "" _nA(long double len){
    return electric_current{len,1e-09, 0.0};
}

electric_current literals::operator "" _nA(unsigned long long int len){
    return electric_current{static_cast<long double>(len),1e-09, 0.0};
}


