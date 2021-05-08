#include "temperature.hpp"

using namespace sakurajin::unit_system::base;

temperature::temperature(): temperature(0){}
temperature::temperature(unit_t<4> val): temperature(val.value, val.multiplier, val.offset){}
temperature::temperature(long double val): temperature(val,1){}
temperature::temperature(long double val, long double mult): temperature(val,mult,0){}
temperature::temperature(long double val, long double mult, long double offset): unit_t<4>(val,mult,offset){}
