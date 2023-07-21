
#include "unit_system/amount.hpp"


using namespace sakurajin::unit_system;

amount::amount(): amount(0){}
amount::amount(unit_t<5> val): amount(val.value,val.multiplier){}
amount::amount(long double val): amount(val,1){}
amount::amount(long double val, long double mult ): unit_t<5>(val,mult){}
amount::amount(long double val, long double mult, long double offset ): unit_t<5>(val,mult,offset){}

std::ostream& ::sakurajin::unit_system::operator<<(std::ostream& os, const ::sakurajin::unit_system::amount& t){
    auto t1 = ::sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " amount";
}




amount literals::operator "" _mol(long double len){
    return amount{len,6.02214076e+23, 0.0};
}

amount literals::operator "" _mol(unsigned long long int len){
    return amount{static_cast<long double>(len),6.02214076e+23, 0.0};
}



amount literals::operator "" _things(long double len){
    return amount{len,1.0, 0.0};
}

amount literals::operator "" _things(unsigned long long int len){
    return amount{static_cast<long double>(len),1.0, 0.0};
}


