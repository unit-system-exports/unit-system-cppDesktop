#include "temperature.hpp"

using namespace sakurajin::unit_system::base;

temperature::temperature(double val): unit_t<4>(val){}
temperature::temperature(double val, double mult): unit_t<4>(val,mult){}
