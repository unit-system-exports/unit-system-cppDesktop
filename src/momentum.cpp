
#include "unit_system/momentum.hpp"


using namespace sakurajin::unit_system;

momentum::momentum(): momentum(0){}
momentum::momentum(unit_t<3201> val): momentum(val.value,val.multiplier){}
momentum::momentum(long double val): momentum(val,1){}
momentum::momentum(long double val, long double mult ): unit_t<3201>(val,mult){}
momentum::momentum(long double val, long double mult, long double offset ): unit_t<3201>(val,mult,offset){}

std::ostream& ::sakurajin::unit_system::operator<<(std::ostream& os, const ::sakurajin::unit_system::momentum& t){
    auto t1 = ::sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " kilogram-meter per second";
}




momentum literals::operator "" _kgmps(long double len){
    return momentum{len,1.0, 0.0};
}

momentum literals::operator "" _kgmps(unsigned long long int len){
    return momentum{static_cast<long double>(len),1.0, 0.0};
}


