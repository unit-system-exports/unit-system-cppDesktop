#include "mass.hpp"

using namespace sakurajin::unit_system::base;

mass::mass(long double val): unit_t<3>(val){}
mass::mass(long double val, long double mult): unit_t<3>(val,mult){}
