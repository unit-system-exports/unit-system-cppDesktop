#include "time.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::prefix;

time_si::time_si(): time_si(0){}
time_si::time_si(unit_t<1> val): time_si(val.value, val.multiplier){}
time_si::time_si(long double val): time_si(val,1){}
time_si::time_si(long double val, long double mult): unit_t<1>(val,mult){}

time_si literals::operator "" _a(long double len){
    return time_si(len,365.25*24.0*60.0*60.0);
}

time_si literals::operator "" _d(long double len){
    return time_si(len,24.0*60.0*60.0);
}

time_si literals::operator "" _h(long double len){
    return time_si(len,60.0*60.0);
}

time_si literals::operator "" _s(long double len){
    return time_si(len,1);
}

time_si literals::operator "" _ms(long double len){
    return time_si(len,milli);
}

time_si literals::operator "" _us(long double len){
    return time_si(len,micro);
}

time_si literals::operator "" _ns(long double len){
    return time_si(len,nano);
}

time_si literals::operator "" _fs(long double len){
    return time_si(len,femto);
}



time_si literals::operator "" _a(unsigned long long int len){
    return time_si(len,365.25*24.0*60.0*60.0);
}

time_si literals::operator "" _d(unsigned long long int len){
    return time_si(len,24.0*60.0*60.0);
}

time_si literals::operator "" _h(unsigned long long int len){
    return time_si(len,60.0*60.0);
}

time_si literals::operator "" _s(unsigned long long int len){
    return time_si(len,1);
}

time_si literals::operator "" _ms(unsigned long long int len){
    return time_si(len,milli);
}

time_si literals::operator "" _us(unsigned long long int len){
    return time_si(len,micro);
}

time_si literals::operator "" _ns(unsigned long long int len){
    return time_si(len,nano);
}

time_si literals::operator "" _fs(unsigned long long int len){
    return time_si(len,femto);
}


#ifndef ARDUINO
    time_si literals::operator "" _min(long double len){
        return time_si(len,60.0);
    }

    time_si literals::operator "" _min(unsigned long long int len){
        return time_si(len,60.0);
    }
#else
    time_si literals::operator "" _minute(long double len){
        return time_si(len,60.0);
    }

    time_si literals::operator "" _minute(unsigned long long int len){
        return time_si(len,60.0);
    }
#endif


