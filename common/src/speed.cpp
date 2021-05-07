#include "speed.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system;
using namespace prefix;

common::speed::speed ( long double val, long double mult ) : unit_t<201>(val,mult){};
common::speed::speed(long double val): unit_t<201>(val){};

common::speed sakurajin::unit_system::unit_cast(const common::speed& other, long double new_multiplier){
    auto v1 = sakurajin::unit_system::unit_cast(static_cast<unit_t<201>>(other), new_multiplier);
    return common::speed{v1.value,v1.multiplier};
}

common::speed common::operator/(const base::length& s, const base::time_si& t){
    auto s1 = sakurajin::unit_system::unit_cast(s,1);
    auto t1 = sakurajin::unit_system::unit_cast(t,1);
    return common::speed{s1.value/t1.value,1};
}

base::length common::operator*(const common::speed& v, const base::time_si& t){
    auto v1 = sakurajin::unit_system::unit_cast(v,1);
    auto t1 = sakurajin::unit_system::unit_cast(t,1);
    return base::length{v1.value*t1.value,1};
}

base::length common::operator*(const base::time_si& t, const common::speed& v){
    return v*t;
}

base::time_si operator/(const base::length& s, const common::speed& v){
    auto v1 = sakurajin::unit_system::unit_cast(v,1);
    auto s1 = sakurajin::unit_system::unit_cast(s,1);
    return base::time_si{s1.value/v1.value,1};
}

common::speed common::literals::operator "" _kmph(long double len){
    return common::speed{len,kilo/(60.0*60.0)};
}

common::speed common::literals::operator "" _mps(long double len){
    return common::speed{len,1};
}

common::speed common::literals::operator "" _kmph(unsigned long long int len){
    return common::speed{static_cast<long double>(len),kilo/(60.0*60.0)};
}

common::speed common::literals::operator "" _mps(unsigned long long int len){
    return common::speed{static_cast<long double>(len),1};
}

std::ostream& common::operator<<(std::ostream& os, const common::speed& v){
    auto v1 = sakurajin::unit_system::unit_cast(v,1);
    return os << v1.value << " meter per second";
}
