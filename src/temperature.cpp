
#include "unit_system/temperature.hpp"


using namespace sakurajin::unit_system;

temperature::temperature(): temperature(0){}
temperature::temperature(unit_t<4> val): temperature(val.value,val.multiplier){}
temperature::temperature(long double val): temperature(val,1){}
temperature::temperature(long double val, long double mult ): unit_t<4>(val,mult){}
temperature::temperature(long double val, long double mult, long double offset ): unit_t<4>(val,mult,offset){}

std::ostream& ::sakurajin::unit_system::operator<<(std::ostream& os, const ::sakurajin::unit_system::temperature& t){
    auto t1 = ::sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " temperature";
}




temperature literals::operator "" _K(long double len){
    return temperature{len,1.0, 0.0};
}

temperature literals::operator "" _K(unsigned long long int len){
    return temperature{static_cast<long double>(len),1.0, 0.0};
}



temperature literals::operator "" _C(long double len){
    return temperature{len,1.0, 273.15};
}

temperature literals::operator "" _C(unsigned long long int len){
    return temperature{static_cast<long double>(len),1.0, 273.15};
}


