#include "speed.hpp"

using namespace sakurajin::unit_system;


common::speed::speed ( long double val, long double mult ) : base::unit_t<201>(val,mult){}
common::speed::speed(long double val): base::unit_t<201>(val){}

common::speed common::operator/(const base::length& s, const base::time& t){
    auto s1 = base::unit_cast(s,1);
    auto t1 = base::unit_cast(t,1);
    return common::speed(s1.value/t1.value,1);
}
