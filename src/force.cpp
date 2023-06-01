
#include "unit_system/force.hpp"


using namespace sakurajin::unit_system;

force::force(): force(0){}
force::force(unit_t<32011> val): force(val.value,val.multiplier){}
force::force(long double val): force(val,1){}
force::force(long double val, long double mult ): unit_t<32011>(val,mult){}
force::force(long double val, long double mult, long double offset ): unit_t<32011>(val,mult,offset){}

std::ostream& ::sakurajin::unit_system::operator<<(std::ostream& os, const ::sakurajin::unit_system::force& t){
    auto t1 = ::sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " Newton";
}




force literals::operator "" _N(long double len){
    return force{len,1.0, 0.0};
}

force literals::operator "" _N(unsigned long long int len){
    return force{static_cast<long double>(len),1.0, 0.0};
}



force literals::operator "" _PN(long double len){
    return force{len,1000000000000000.0, 0.0};
}

force literals::operator "" _PN(unsigned long long int len){
    return force{static_cast<long double>(len),1000000000000000.0, 0.0};
}



force literals::operator "" _TN(long double len){
    return force{len,1000000000000.0, 0.0};
}

force literals::operator "" _TN(unsigned long long int len){
    return force{static_cast<long double>(len),1000000000000.0, 0.0};
}



force literals::operator "" _GN(long double len){
    return force{len,1000000000.0, 0.0};
}

force literals::operator "" _GN(unsigned long long int len){
    return force{static_cast<long double>(len),1000000000.0, 0.0};
}



force literals::operator "" _MN(long double len){
    return force{len,1000000.0, 0.0};
}

force literals::operator "" _MN(unsigned long long int len){
    return force{static_cast<long double>(len),1000000.0, 0.0};
}



force literals::operator "" _kN(long double len){
    return force{len,1000.0, 0.0};
}

force literals::operator "" _kN(unsigned long long int len){
    return force{static_cast<long double>(len),1000.0, 0.0};
}



force literals::operator "" _mN(long double len){
    return force{len,0.001, 0.0};
}

force literals::operator "" _mN(unsigned long long int len){
    return force{static_cast<long double>(len),0.001, 0.0};
}



force literals::operator "" _uN(long double len){
    return force{len,1e-06, 0.0};
}

force literals::operator "" _uN(unsigned long long int len){
    return force{static_cast<long double>(len),1e-06, 0.0};
}



force literals::operator "" _nN(long double len){
    return force{len,1e-09, 0.0};
}

force literals::operator "" _nN(unsigned long long int len){
    return force{static_cast<long double>(len),1e-09, 0.0};
}



force literals::operator "" _pN(long double len){
    return force{len,1e-12, 0.0};
}

force literals::operator "" _pN(unsigned long long int len){
    return force{static_cast<long double>(len),1e-12, 0.0};
}



force literals::operator "" _fN(long double len){
    return force{len,1e-15, 0.0};
}

force literals::operator "" _fN(unsigned long long int len){
    return force{static_cast<long double>(len),1e-15, 0.0};
}



force literals::operator "" _aN(long double len){
    return force{len,1e-18, 0.0};
}

force literals::operator "" _aN(unsigned long long int len){
    return force{static_cast<long double>(len),1e-18, 0.0};
}


