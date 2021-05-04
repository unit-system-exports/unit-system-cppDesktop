#include "luminous_intensity.hpp"

using namespace sakurajin::unit_system::base;

luminous_intensity::luminous_intensity(double val): unit_t<7>(val){}
luminous_intensity::luminous_intensity(double val, double mult): unit_t<7>(val,mult){}
