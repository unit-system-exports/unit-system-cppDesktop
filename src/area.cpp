
#include "unit_system/area.hpp"


using namespace sakurajin::unit_system;

area::area(): area(0){}
area::area(unit_t<22> val): area(val.value,val.multiplier){}
area::area(long double val): area(val,1){}
area::area(long double val, long double mult ): unit_t<22>(val,mult){}
area::area(long double val, long double mult, long double offset ): unit_t<22>(val,mult,offset){}

std::ostream& ::sakurajin::unit_system::operator<<(std::ostream& os, const ::sakurajin::unit_system::area& t){
    auto t1 = ::sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " area";
}




area literals::operator "" _m2(long double len){
    return area{len,1.0, 0.0};
}

area literals::operator "" _m2(unsigned long long int len){
    return area{static_cast<long double>(len),1.0, 0.0};
}



area literals::operator "" _are(long double len){
    return area{len,100.0, 0.0};
}

area literals::operator "" _are(unsigned long long int len){
    return area{static_cast<long double>(len),100.0, 0.0};
}



area literals::operator "" _hectare(long double len){
    return area{len,10000.0, 0.0};
}

area literals::operator "" _hectare(unsigned long long int len){
    return area{static_cast<long double>(len),10000.0, 0.0};
}



area literals::operator "" _km2(long double len){
    return area{len,1000000.0, 0.0};
}

area literals::operator "" _km2(unsigned long long int len){
    return area{static_cast<long double>(len),1000000.0, 0.0};
}



area literals::operator "" _mm2(long double len){
    return area{len,1e-06, 0.0};
}

area literals::operator "" _mm2(unsigned long long int len){
    return area{static_cast<long double>(len),1e-06, 0.0};
}



area literals::operator "" _um2(long double len){
    return area{len,1e-12, 0.0};
}

area literals::operator "" _um2(unsigned long long int len){
    return area{static_cast<long double>(len),1e-12, 0.0};
}



area literals::operator "" _nm2(long double len){
    return area{len,1e-18, 0.0};
}

area literals::operator "" _nm2(unsigned long long int len){
    return area{static_cast<long double>(len),1e-18, 0.0};
}


