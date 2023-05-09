
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


