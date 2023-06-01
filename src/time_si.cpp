
#include "unit_system/time_si.hpp"


using namespace sakurajin::unit_system;

time_si::time_si(): time_si(0){}
time_si::time_si(unit_t<1> val): time_si(val.value,val.multiplier){}
time_si::time_si(long double val): time_si(val,1){}
time_si::time_si(long double val, long double mult ): unit_t<1>(val,mult){}
time_si::time_si(long double val, long double mult, long double offset ): unit_t<1>(val,mult,offset){}

std::ostream& ::sakurajin::unit_system::operator<<(std::ostream& os, const ::sakurajin::unit_system::time_si& t){
    auto t1 = ::sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " second";
}




time_si literals::operator "" _a(long double len){
    return time_si{len,31536000000.0, 0.0};
}

time_si literals::operator "" _a(unsigned long long int len){
    return time_si{static_cast<long double>(len),31536000000.0, 0.0};
}



time_si literals::operator "" _d(long double len){
    return time_si{len,86400000.0, 0.0};
}

time_si literals::operator "" _d(unsigned long long int len){
    return time_si{static_cast<long double>(len),86400000.0, 0.0};
}



time_si literals::operator "" _h(long double len){
    return time_si{len,3600.0, 0.0};
}

time_si literals::operator "" _h(unsigned long long int len){
    return time_si{static_cast<long double>(len),3600.0, 0.0};
}



time_si literals::operator "" _minute(long double len){
    return time_si{len,60.0, 0.0};
}

time_si literals::operator "" _minute(unsigned long long int len){
    return time_si{static_cast<long double>(len),60.0, 0.0};
}



time_si literals::operator "" _s(long double len){
    return time_si{len,1.0, 0.0};
}

time_si literals::operator "" _s(unsigned long long int len){
    return time_si{static_cast<long double>(len),1.0, 0.0};
}



time_si literals::operator "" _ms(long double len){
    return time_si{len,0.001, 0.0};
}

time_si literals::operator "" _ms(unsigned long long int len){
    return time_si{static_cast<long double>(len),0.001, 0.0};
}



time_si literals::operator "" _us(long double len){
    return time_si{len,1e-06, 0.0};
}

time_si literals::operator "" _us(unsigned long long int len){
    return time_si{static_cast<long double>(len),1e-06, 0.0};
}



time_si literals::operator "" _ns(long double len){
    return time_si{len,1e-09, 0.0};
}

time_si literals::operator "" _ns(unsigned long long int len){
    return time_si{static_cast<long double>(len),1e-09, 0.0};
}



time_si literals::operator "" _ps(long double len){
    return time_si{len,1e-12, 0.0};
}

time_si literals::operator "" _ps(unsigned long long int len){
    return time_si{static_cast<long double>(len),1e-12, 0.0};
}



time_si literals::operator "" _fs(long double len){
    return time_si{len,1e-15, 0.0};
}

time_si literals::operator "" _fs(unsigned long long int len){
    return time_si{static_cast<long double>(len),1e-15, 0.0};
}



time_si literals::operator "" _as(long double len){
    return time_si{len,1e-18, 0.0};
}

time_si literals::operator "" _as(unsigned long long int len){
    return time_si{static_cast<long double>(len),1e-18, 0.0};
}


