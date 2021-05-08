#include "electric_current.hpp"

using namespace sakurajin::unit_system::base;

electric_current::electric_current(): electric_current(0){}
electric_current::electric_current(long double val): electric_current(val,1){}
electric_current::electric_current(long double val, long double mult): unit_t<6>(val,mult){}
