#include "amount.hpp"

using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::base::constants;

amount::amount(): amount(0){};
amount::amount(unit_t<5> val): amount(val.value,val.multiplier){}
amount::amount(long double val): amount(val,1){}
amount::amount(long double val, long double mult): unit_t<5>(val,mult){}

amount::operator long double() const{
    return value * (multiplier*avogadro_constant);
}

amount literals::operator "" _mol(long double len){
    return amount(len);
}

amount literals::operator "" _things(long double len){
    return amount(len, 1/avogadro_constant);
}


amount literals::operator "" _mol(unsigned long long int len){
    return amount(len);
}

amount literals::operator "" _things(unsigned long long int len){
    return amount(len, 1/avogadro_constant);
}
