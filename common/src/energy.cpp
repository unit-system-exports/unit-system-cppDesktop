#include "energy.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system;
using namespace prefix;

//contructors
common::energy::energy(): energy(0){};
common::energy::energy(unit_t<8> val): energy(val.value,val.multiplier){}
common::energy::energy(long double val): energy(val,1){};
common::energy::energy(long double val, long double mult): unit_t<8>(val,mult){};

//force based energy
common::energy common::operator*(const common::force& F, const base::length& s){
    auto F1 = sakurajin::unit_system::unit_cast(F,F.multiplier,0);
    auto s1 = sakurajin::unit_system::unit_cast(s,s.multiplier,0);
    return common::energy{F1.value*s1.value,F1.multiplier*s1.multiplier};
}

common::energy common::operator*(const base::length& s, const common::force& F){
    return F*s;
}

common::force common::operator/(const common::energy& E, const base::length& s){
    auto E1 = sakurajin::unit_system::unit_cast(E,E.multiplier,0);
    auto s1 = sakurajin::unit_system::unit_cast(s,s.multiplier,0);
    return common::force{E1.value/s1.value,E1.multiplier/s1.multiplier};
}

base::length common::operator/(const common::energy& E, const common::force& F){
    auto E1 = sakurajin::unit_system::unit_cast(E,E.multiplier,0);
    auto F1 = sakurajin::unit_system::unit_cast(F,F.multiplier,0);
    return base::length{E1.value/F1.value,E1.multiplier/F1.multiplier};
}

//kinetic energy
common::energy common::operator*(const common::momentum& p, const common::speed& v){
    auto p1 = sakurajin::unit_system::unit_cast(p,p.multiplier,0);
    auto v1 = sakurajin::unit_system::unit_cast(v,v.multiplier,0);
    return common::energy{p1.value*v1.value,p1.multiplier*v1.multiplier};
}

common::energy common::operator*(const common::speed& v, const common::momentum& p){
    return p*v;
}

common::speed common::operator/(const common::energy& E, const common::momentum& p){
    auto E1 = sakurajin::unit_system::unit_cast(E,E.multiplier,0);
    auto p1 = sakurajin::unit_system::unit_cast(p,p.multiplier,0);
    return common::speed{E1.value/p1.value,E1.multiplier/p1.multiplier};
}

common::momentum common::operator/(const common::energy& E, const common::speed& v){
    auto E1 = sakurajin::unit_system::unit_cast(E,E.multiplier,0);
    auto v1 = sakurajin::unit_system::unit_cast(v,v.multiplier,0);
    return common::momentum{E1.value/v1.value,E1.multiplier/v1.multiplier};
}

//literals
common::energy common::literals::operator "" _J(long double len){
    return common::energy{len,1};
}

common::energy common::literals::operator "" _J(unsigned long long int len){
    return common::energy{static_cast<long double>(len), 1};
}
