#include "time.hpp"

using namespace sakurajin::unit_system::base;

time::time(double val): unit_t<1>(val){}
time::time(double val, double mult): unit_t<1>(val,mult){}
