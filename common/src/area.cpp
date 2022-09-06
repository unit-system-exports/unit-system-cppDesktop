#include "area.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system;
using namespace prefix;

common::area::area(): area(0){};
common::area::area(unit_t<22> val): area(val.value,val.multiplier){};
common::area::area(long double val): area(val,1){};
common::area::area(long double val, long double mult): unit_t<22>(val,mult){};

base::length common::operator/(const common::area& a, const base::length& l){
    auto a1 = sakurajin::unit_system::unit_cast(a,a.multiplier,0);
    auto l1 = sakurajin::unit_system::unit_cast(l,l.multiplier,0);
    return base::length{a1.value/l1.value,a1.multiplier/l1.multiplier};
}
            
common::area common::operator*(const base::length& l1, const base::length& l2){
    auto _l1 = sakurajin::unit_system::unit_cast(l1,l1.multiplier,0);
    auto _l2 = sakurajin::unit_system::unit_cast(l2,l2.multiplier,0);

    return common::area{_l1.value*_l2.value,_l1.multiplier*_l2.multiplier};
}

common::area common::square(const base::length& l){
    return l*l;
}


common::area common::literals::operator "" _km2(long double len){
    return common::area{len, kilo*kilo};
}

common::area common::literals::operator "" _m2(long double len){
    return common::area{len,1};
}

common::area common::literals::operator "" _mm2(long double len){
    return common::area{len, milli*milli};
}


common::area common::literals::operator "" _km2(unsigned long long int len){
    return common::area{static_cast<long double>(len), kilo*kilo};
}

common::area common::literals::operator "" _m2(unsigned long long int len){
    return common::area{static_cast<long double>(len),1};
}

common::area common::literals::operator "" _mm2(unsigned long long int len){
    return common::area{static_cast<long double>(len), milli*milli};
}
