#include "luminous_intensity.hpp"

using namespace sakurajin::unit_system::base;

luminous_intensity::luminous_intensity(): luminous_intensity(0){}
luminous_intensity::luminous_intensity(unit_t<7> val): luminous_intensity(val.value,val.multiplier){}
luminous_intensity::luminous_intensity(long double val): luminous_intensity(val,1){}
luminous_intensity::luminous_intensity(long double val, long double mult): unit_t<7>(val,mult){}
