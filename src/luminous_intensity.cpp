
#include "unit_system/luminous_intensity.hpp"


using namespace sakurajin::unit_system;

luminous_intensity::luminous_intensity(): luminous_intensity(0){}
luminous_intensity::luminous_intensity(unit_t<7> val): luminous_intensity(val.value,val.multiplier){}
luminous_intensity::luminous_intensity(long double val): luminous_intensity(val,1){}
luminous_intensity::luminous_intensity(long double val, long double mult ): unit_t<7>(val,mult){}
luminous_intensity::luminous_intensity(long double val, long double mult, long double offset ): unit_t<7>(val,mult,offset){}

std::ostream& ::sakurajin::unit_system::operator<<(std::ostream& os, const ::sakurajin::unit_system::luminous_intensity& t){
    auto t1 = ::sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " candela";
}




luminous_intensity literals::operator "" _cd(long double len){
    return luminous_intensity{len,1.0, 0.0};
}

luminous_intensity literals::operator "" _cd(unsigned long long int len){
    return luminous_intensity{static_cast<long double>(len),1.0, 0.0};
}


