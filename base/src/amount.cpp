#include "amount.hpp"

using namespace sakurajin::unit_system::base;

amount::amount(): amount(0){};
amount::amount(unit_t<5> val): amount(val.value,val.multiplier){}
amount::amount(long double val): amount(val,1){}
amount::amount(long double val, long double mult): unit_t<5>(val,mult){}

amount sakurajin::unit_system::unit_cast(const amount& other, long double new_multiplier){
    auto v1 = sakurajin::unit_system::unit_cast(static_cast<unit_t<5>>(other), new_multiplier);
    return amount{v1.value,v1.multiplier};
}

amount::operator long double() const{
    return value * (multiplier*avogadro_constant);
}

std::ostream& operator<<(std::ostream& os, const amount& t){
    auto t1 = sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " seconds";
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
