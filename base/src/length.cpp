#include "length.hpp"

using namespace sakurajin::unit_system::base;

length::length(double val): unit_t<2>(val){}
length::length(double val, double mult): unit_t<2>(val,mult){}
