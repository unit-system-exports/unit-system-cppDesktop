#include "temperature.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::base::constants;
using namespace sakurajin::unit_system::prefix;

temperature::temperature(): temperature(0){}
temperature::temperature(unit_t<4> val): temperature(val.value, val.multiplier, val.offset){}
temperature::temperature(long double val): temperature(val,1){}
temperature::temperature(long double val, long double mult): temperature(val,mult,0){}
temperature::temperature(long double val, long double mult, long double offset): unit_t<4>(val,mult,offset){}

std::ostream& ::sakurajin::unit_system::base::operator<<(std::ostream& os, const temperature& J){
    auto J1 = sakurajin::unit_system::unit_cast(J,1,0);
    return os << J1.value << " Kelvin";
}

temperature literals::operator "" _K(long double len){
    return temperature{len, 1,0};
}

temperature literals::operator "" _C(long double len){
    return temperature{len, 1, waterFreezinPoint};
}


temperature literals::operator "" _K(unsigned long long int len){
    return temperature{static_cast<long double>(len), 1, 0};
}

temperature literals::operator "" _C(unsigned long long int len){
    return temperature{static_cast<long double>(len), 1, waterFreezinPoint};
}
