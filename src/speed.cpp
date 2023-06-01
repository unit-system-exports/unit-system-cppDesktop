
#include "unit_system/speed.hpp"


using namespace sakurajin::unit_system;

speed::speed(): speed(0){}
speed::speed(unit_t<201> val): speed(val.value,val.multiplier){}
speed::speed(long double val): speed(val,1){}
speed::speed(long double val, long double mult ): unit_t<201>(val,mult){}
speed::speed(long double val, long double mult, long double offset ): unit_t<201>(val,mult,offset){}

std::ostream& ::sakurajin::unit_system::operator<<(std::ostream& os, const ::sakurajin::unit_system::speed& t){
    auto t1 = ::sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " metre per second";
}




speed literals::operator "" _mps(long double len){
    return speed{len,1.0, 0.0};
}

speed literals::operator "" _mps(unsigned long long int len){
    return speed{static_cast<long double>(len),1.0, 0.0};
}



speed literals::operator "" _kmph(long double len){
    return speed{len,0.2777777777777778, 0.0};
}

speed literals::operator "" _kmph(unsigned long long int len){
    return speed{static_cast<long double>(len),0.2777777777777778, 0.0};
}


