#include "momentum.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system;
using namespace prefix;

common::momentum::momentum(): momentum(0){};
common::momentum::momentum(unit_t<3201> val): momentum(val.value,val.multiplier){};
common::momentum::momentum(long double val): momentum(val,1){};
common::momentum::momentum(long double val, long double mult): unit_t<3201>(val,mult){};

common::momentum common::operator*(const base::mass& m, const common::speed& v){
    auto m1 = sakurajin::unit_system::unit_cast(m,m.multiplier,0);
    auto v1 = sakurajin::unit_system::unit_cast(v,v.multiplier,0);
    return common::momentum{v1.value*m1.value,v1.multiplier*m1.multiplier};
}

common::momentum common::operator*(const common::speed& v, const base::mass& m){
    return m*v;
}

base::mass common::operator/(const common::momentum& p, const common::speed& v){
    auto p1 = sakurajin::unit_system::unit_cast(p,p.multiplier,0);
    auto v1 = sakurajin::unit_system::unit_cast(v,v.multiplier,0);
    return base::mass{p1.value/v1.value,p1.multiplier/v1.multiplier};
}

common::speed common::operator/(const common::momentum& p, const base::mass& m){
    auto p1 = sakurajin::unit_system::unit_cast(p,p.multiplier,0);
    auto m1 = sakurajin::unit_system::unit_cast(m,m.multiplier,0);
    return common::speed{p1.value/m1.value,p1.multiplier/m1.multiplier};
}

common::momentum common::literals::operator "" _kgmps(long double len){
    return common::momentum{len,1};
}

common::momentum common::literals::operator "" _kgmps(unsigned long long int len){
    return common::momentum{static_cast<long double>(len), 1};
}

std::ostream& common::operator<<(std::ostream& os, const common::momentum& p){
    auto p1 = sakurajin::unit_system::unit_cast(p,1);
    return os << p1.value << " kilogram * meter per second";
}
