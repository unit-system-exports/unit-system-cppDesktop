#include "amount.hpp"

using namespace sakurajin::unit_system::base;

amount::amount(double val): unit_t<5>(val){}
amount::amount(double val, double mult): unit_t<5>(val,mult){}
