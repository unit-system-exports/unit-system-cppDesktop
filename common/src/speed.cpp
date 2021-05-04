#include "speed.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system;
using namespace prefix;

common::speed::speed ( long double val, long double mult ) : base::unit_t<201>(val,mult){}
common::speed::speed(long double val): base::unit_t<201>(val){}

common::speed common::operator/(const base::length& s, const base::time_si& t){
    auto s1 = base::unit_cast(s,1);
    auto t1 = base::unit_cast(t,1);
    return common::speed{s1.value/t1.value,1};
}

base::length common::operator*(const common::speed& v, const base::time_si& t){
    auto v1 = base::unit_cast(v,1);
    auto t1 = base::unit_cast(t,1);
    return base::length{v1.value*t1.value,1};
}

base::length common::operator*(const base::time_si& t, const common::speed& v){
    return v*t;
}

base::time_si operator/(const base::length& s, const common::speed& v){
    auto v1 = base::unit_cast(v,1);
    auto s1 = base::unit_cast(s,1);
    return base::time_si{s1.value/v1.value,1};
}

common::speed common::literals::operator "" _kmph(long double len){
    return common::speed{len,kilo/(60.0*60.0)};
}

common::speed common::literals::operator "" _mps(long double len){
    return common::speed{len,1};
}
