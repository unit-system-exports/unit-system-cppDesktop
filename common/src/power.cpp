#include "power.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system;
using namespace prefix;

common::power::power(): power(0){};
common::power::power(unit_t<801> val): power(val.value,val.multiplier){};
common::power::power(long double val): power(val,1){};
common::power::power(long double val, long double mult): unit_t<801>(val,mult){};


//Energy / time = Power
common::energy common::operator*(const common::power& P, const base::time_si& t){
    auto F1 = sakurajin::unit_system::unit_cast(P,P.multiplier,0);
    auto v1 = sakurajin::unit_system::unit_cast(t,t.multiplier,0);
    return common::energy{F1.value*v1.value,F1.multiplier*v1.multiplier};
}

common::energy common::operator*(const base::time_si& t, const common::power& P){
    return P*t;
}

common::power common::operator/(const common::energy& E, const base::time_si& t){
    auto P1 = sakurajin::unit_system::unit_cast(E,E.multiplier,0);
    auto v1 = sakurajin::unit_system::unit_cast(t,t.multiplier,0);
    return common::power{P1.value/v1.value,P1.multiplier/v1.multiplier};
}

base::time_si common::operator/(const common::energy& E, const common::power& P){
    auto P1 = sakurajin::unit_system::unit_cast(E,E.multiplier,0);
    auto v1 = sakurajin::unit_system::unit_cast(P,P.multiplier,0);
    return base::time_si{P1.value/v1.value,P1.multiplier/v1.multiplier};
}

//Force * speed = Power
common::power common::operator*(const common::force& F, const common::speed& v) {
    auto F1 = sakurajin::unit_system::unit_cast(F,F.multiplier,0);
    auto v1 = sakurajin::unit_system::unit_cast(v,v.multiplier,0);
    return common::power{F1.value*v1.value,F1.multiplier*v1.multiplier};
}

common::power common::operator*(const common::speed& v, const common::force& f) {
    auto v1 = sakurajin::unit_system::unit_cast(v,v.multiplier,0);
    auto F1 = sakurajin::unit_system::unit_cast(f,f.multiplier,0);
    return common::power{v1.value*F1.value,v1.multiplier*F1.multiplier};
}

common::force common::operator/(const common::power& P, const common::speed& v) {
    auto P1 = sakurajin::unit_system::unit_cast(P,P.multiplier,0);
    auto v1 = sakurajin::unit_system::unit_cast(v,v.multiplier,0);
    return common::force{P1.value/v1.value,P1.multiplier/v1.multiplier};
}

common::speed common::operator/(const common::power& P, const common::force& F) {
    auto P1 = sakurajin::unit_system::unit_cast(P,P.multiplier,0);
    auto F1 = sakurajin::unit_system::unit_cast(F,F.multiplier,0);
    return common::speed{P1.value/F1.value,P1.multiplier/F1.multiplier};
}

//literals
common::power common::literals::operator "" _W(long double len){
    return common::power{len,1};
}

common::power common::literals::operator "" _W(unsigned long long int len){
    return common::power{static_cast<long double>(len), 1};
}

//output
std::ostream& common::operator<<(std::ostream& os, const common::power& p){
    auto p1 = sakurajin::unit_system::unit_cast(p,1);
    return os << p1.value << " Watts";
}
