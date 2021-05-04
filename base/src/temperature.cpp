#include "temperature.hpp"

using namespace sakurajin::unit_system::base;

temperature::temperature(long double val): unit_t<4>(val){}
temperature::temperature(long double val, long double mult): unit_t<4>(val,mult){}
