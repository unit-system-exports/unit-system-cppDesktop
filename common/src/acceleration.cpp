#include "acceleration.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system;
using namespace prefix;

common::acceleration::acceleration(): acceleration(0){};
common::acceleration::acceleration(unit_t<2011> val): acceleration(val.value,val.multiplier){};
common::acceleration::acceleration(long double val): acceleration(val,1){};
common::acceleration::acceleration(long double val, long double mult): unit_t<2011>(val,mult){};

common::acceleration common::operator/(const common::speed& v, const base::time_si& t){
    auto v1 = sakurajin::unit_system::unit_cast(v,v.multiplier,0);
    auto t1 = sakurajin::unit_system::unit_cast(t,t.multiplier,0);
    return common::acceleration{v1.value/t1.value,v1.multiplier/t1.multiplier};
}

common::speed common::operator*(const common::acceleration& a, const base::time_si& t){
    auto a1 = sakurajin::unit_system::unit_cast(a,a.multiplier,0);
    auto t1 = sakurajin::unit_system::unit_cast(t,t.multiplier,0);
    return common::speed{a1.value*t1.value,a1.multiplier*t1.multiplier};
}

common::speed common::operator*(const base::time_si& t, const common::acceleration& a){
    return a*t;
}

base::time_si operator/(const common::speed& v, const common::acceleration& a){
    auto a1 = sakurajin::unit_system::unit_cast(a,a.multiplier,0);
    auto v1 = sakurajin::unit_system::unit_cast(v,v.multiplier,0);
    return base::time_si{v1.value/a1.value,v1.multiplier/a1.multiplier};
}

common::acceleration common::literals::operator "" _mps2(long double len){
    return common::acceleration{len,1};
}

common::acceleration common::literals::operator "" _G(long double len){
    return common::acceleration{len,9.81};
}

common::acceleration common::literals::operator "" _mps2(unsigned long long int len){
    return common::acceleration{static_cast<long double>(len),1};
}

common::acceleration common::literals::operator "" _G(unsigned long long int len){
    return common::acceleration{static_cast<long double>(len),9.81};
}

std::ostream& common::operator<<(std::ostream& os, const common::acceleration& a){
    auto a1 = sakurajin::unit_system::unit_cast(a,1);
    return os << a1.value << " meter per second^2";
}
