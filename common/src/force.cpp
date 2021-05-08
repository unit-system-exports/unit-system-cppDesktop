#include "force.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system;
using namespace prefix;

common::force::force(): force(0){};
common::force::force(long double val): force(val,1){};
common::force::force(long double val, long double mult): unit_t<32011>(val,mult){};

common::force sakurajin::unit_system::unit_cast(const common::force& other, long double new_multiplier){
    auto v1 = sakurajin::unit_system::unit_cast(static_cast<unit_t<32011>>(other), new_multiplier);
    return common::force{v1.value,v1.multiplier};
}

common::force common::operator/(const common::momentum& p, const base::time_si& t){
    auto p1 = sakurajin::unit_system::unit_cast(p,1);
    auto t1 = sakurajin::unit_system::unit_cast(t,1);
    return common::force{p1.value/t1.value,1};
}

base::time_si common::operator/(const common::momentum& p, const common::force& F){
    auto p1 = sakurajin::unit_system::unit_cast(p,1);
    auto F1 = sakurajin::unit_system::unit_cast(F,1);
    return base::time_si{p1.value/F1.value,1};
}

common::momentum common::operator*(const common::force& F, const base::time_si& t){
    auto F1 = sakurajin::unit_system::unit_cast(F,1);
    auto t1 = sakurajin::unit_system::unit_cast(t,1);
    return common::momentum{F1.value*t1.value,1};
}

common::momentum common::operator*(const base::time_si& t, const common::force& F){
    return F*t;
}

common::force common::operator*(const base::mass& m, const common::acceleration& a){
    auto m1 = sakurajin::unit_system::unit_cast(m,1);
    auto a1 = sakurajin::unit_system::unit_cast(a,1);
    return common::force{a1.value*m1.value,1};
}

common::force common::operator*(const common::acceleration& a, const base::mass& m){
    return m*a;
}

base::mass common::operator/(const common::force& p, const common::acceleration& a){
    auto p1 = sakurajin::unit_system::unit_cast(p,1);
    auto a1 = sakurajin::unit_system::unit_cast(a,1);
    return base::mass{p1.value/a1.value,1};
}

common::acceleration common::operator/(const common::force& p, const base::mass& m){
    auto p1 = sakurajin::unit_system::unit_cast(p,1);
    auto m1 = sakurajin::unit_system::unit_cast(m,1);
    return common::acceleration{p1.value/m1.value,1};
}

common::force common::literals::operator "" _N(long double len){
    return common::force{len,1};
}

common::force common::literals::operator "" _N(unsigned long long int len){
    return common::force{static_cast<long double>(len), 1};
}

std::ostream& common::operator<<(std::ostream& os, const common::force& p){
    auto p1 = sakurajin::unit_system::unit_cast(p,1);
    return os << p1.value << " Newton";
}
