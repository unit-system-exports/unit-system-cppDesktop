#include "electric_current.hpp"

using namespace sakurajin::unit_system::base;

electric_current::electric_current(double val): unit_t<6>(val){}
electric_current::electric_current(double val, double mult): unit_t<6>(val,mult){}
