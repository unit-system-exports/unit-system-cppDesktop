#include "mass.hpp"

using namespace sakurajin::unit_system::base;

mass::mass(double val): unit_t<3>(val){}
mass::mass(double val, double mult): unit_t<3>(val,mult){}
