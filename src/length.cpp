
#include "unit_system/length.hpp"


using namespace sakurajin::unit_system;

length::length(): length(0){}
length::length(unit_t<2> val): length(val.value,val.multiplier){}
length::length(long double val): length(val,1){}
length::length(long double val, long double mult ): unit_t<2>(val,mult){}
length::length(long double val, long double mult, long double offset ): unit_t<2>(val,mult,offset){}

std::ostream& ::sakurajin::unit_system::operator<<(std::ostream& os, const ::sakurajin::unit_system::length& t){
    auto t1 = ::sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " meter";
}




length literals::operator "" _km(long double len){
    return length{len,1000.0, 0.0};
}

length literals::operator "" _km(unsigned long long int len){
    return length{static_cast<long double>(len),1000.0, 0.0};
}



length literals::operator "" _m(long double len){
    return length{len,1.0, 0.0};
}

length literals::operator "" _m(unsigned long long int len){
    return length{static_cast<long double>(len),1.0, 0.0};
}



length literals::operator "" _dm(long double len){
    return length{len,0.1, 0.0};
}

length literals::operator "" _dm(unsigned long long int len){
    return length{static_cast<long double>(len),0.1, 0.0};
}



length literals::operator "" _cm(long double len){
    return length{len,0.01, 0.0};
}

length literals::operator "" _cm(unsigned long long int len){
    return length{static_cast<long double>(len),0.01, 0.0};
}



length literals::operator "" _mm(long double len){
    return length{len,0.001, 0.0};
}

length literals::operator "" _mm(unsigned long long int len){
    return length{static_cast<long double>(len),0.001, 0.0};
}



length literals::operator "" _um(long double len){
    return length{len,1e-06, 0.0};
}

length literals::operator "" _um(unsigned long long int len){
    return length{static_cast<long double>(len),1e-06, 0.0};
}



length literals::operator "" _nm(long double len){
    return length{len,1e-09, 0.0};
}

length literals::operator "" _nm(unsigned long long int len){
    return length{static_cast<long double>(len),1e-09, 0.0};
}


