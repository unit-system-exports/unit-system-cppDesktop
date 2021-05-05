#include "acceleration.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system;
using namespace prefix;

common::acceleration::acceleration ( long double val, long double mult ) : base::unit_t<2011>(val,mult){};
common::acceleration::acceleration(long double val): base::unit_t<2011>(val){};

common::acceleration sakurajin::unit_system::common::unit_cast(const common::acceleration& other, long double new_multiplier){
    auto v1 = base::unit_cast(static_cast<base::unit_t<2011>>(other), new_multiplier);
    return common::acceleration{v1.value,v1.multiplier};
}

common::acceleration common::operator/(const common::speed& v, const base::time_si& t){
    auto v1 = base::unit_cast(v,1);
    auto t1 = base::unit_cast(t,1);
    return common::acceleration{v1.value/t1.value,1};
}

common::speed common::operator*(const common::acceleration& a, const base::time_si& t){
    auto a1 = base::unit_cast(a,1);
    auto t1 = base::unit_cast(t,1);
    return common::speed{a1.value*t1.value,1};
}

common::speed common::operator*(const base::time_si& t, const common::acceleration& a){
    return a*t;
}

base::time_si operator/(const common::speed& v, const common::acceleration& a){
    auto a1 = base::unit_cast(a,1);
    auto v1 = base::unit_cast(v,1);
    return base::time_si{v1.value/a1.value,1};
}

common::acceleration common::literals::operator "" _mps2(long double len){
    return common::acceleration{len,1};
}

common::acceleration common::literals::operator "" _g(long double len){
    return common::acceleration{len,9.81};
}

std::ostream& common::operator<<(std::ostream& os, const common::acceleration& v){
    auto v1 = base::unit_cast(v,1,0);
    return os << v1.value << " meter per second^2";
}
