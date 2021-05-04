#include "time.hpp"

using namespace sakurajin::unit_system::base;

time::time(long double val): unit_t<1>(val){}
time::time(long double val, long double mult): unit_t<1>(val,mult){}
