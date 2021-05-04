#include "amount.hpp"

using namespace sakurajin::unit_system::base;

amount::amount(long double val): unit_t<5>(val){}
amount::amount(long double val, long double mult): unit_t<5>(val,mult){}
