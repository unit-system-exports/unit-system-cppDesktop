#include "unit_system/power.hpp"

sakurajin::unit_system::power::power(): power{0.0}{}
sakurajin::unit_system::power::power(long double v): power{v,1,0}{}
sakurajin::unit_system::power::power(long double v, long double mult): power{v,mult,0}{}
sakurajin::unit_system::power::power(long double v, long double mult, long double off): multiplier{mult}, value{v}, offset{off}{}

//const functions
sakurajin::unit_system::power sakurajin::unit_system::power::operator*(long double scalar) const{
    sakurajin::unit_system::power retval{value*scalar, multiplier, offset};
    return retval;
}

sakurajin::unit_system::power operator*(long double scalar, const sakurajin::unit_system::power& val){
    return {val.value*scalar, val.multiplier, val.offset};
}

long double sakurajin::unit_system::power::operator/(const sakurajin::unit_system::power& other) const{
    auto otherVal = unit_cast(other, multiplier, offset);
    return value/otherVal.value;
}

sakurajin::unit_system::power sakurajin::unit_system::power::operator/(long double scalar) const{
    sakurajin::unit_system::power retval{value/scalar, multiplier, offset};
    return retval;
}

sakurajin::unit_system::power sakurajin::unit_system::power::operator+(const sakurajin::unit_system::power& other) const{
    auto retval = sakurajin::unit_system::unit_cast(other, multiplier,offset);
    retval.value += value;
    return retval;
}

sakurajin::unit_system::power sakurajin::unit_system::power::operator-(const sakurajin::unit_system::power& other) const{
    auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    retval.value = value - retval.value;
    return retval;
}

sakurajin::unit_system::power sakurajin::unit_system::power::operator-() const{
    return sakurajin::unit_system::power{-value,multiplier,offset};
}

sakurajin::unit_system::power::operator long double() const{
    auto retval = sakurajin::unit_system::unit_cast(*this, 1, 0);
    return retval.value;
}

//comparison operators
#if __cplusplus >= 202002L
    int sakurajin::unit_system::power::operator<=>(const sakurajin::unit_system::power& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        if(*this < retval){
            return -1;
        }

        if(*this > retval){
            return 1;
        }

        return 0;
    }
#else
    bool sakurajin::unit_system::power::operator<(const sakurajin::unit_system::power& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value < retval.value;
    }

    bool sakurajin::unit_system::power::operator>(const sakurajin::unit_system::power& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value > retval.value;
    }

    bool sakurajin::unit_system::power::operator<=(const sakurajin::unit_system::power& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value <= retval.value;
    }

    bool sakurajin::unit_system::power::operator>=(const sakurajin::unit_system::power& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value >= retval.value;
    }

    bool sakurajin::unit_system::power::operator==(const sakurajin::unit_system::power& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value == retval.value;
    }

    bool sakurajin::unit_system::power::operator!=(const sakurajin::unit_system::power& other) const{
        return ! (*this == other);
    }
#endif

//non const member functions
void sakurajin::unit_system::power::operator*=(long double scalar){
    value*=scalar;
}

void sakurajin::unit_system::power::operator/=(long double scalar){
    value/=scalar;
}

void sakurajin::unit_system::power::operator+=(const sakurajin::unit_system::power& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value += otherVal.value;
}

void sakurajin::unit_system::power::operator-=(const sakurajin::unit_system::power& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value -= otherVal.value;
}

void sakurajin::unit_system::power::operator=(const sakurajin::unit_system::power& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value = otherVal.value;
}

// external functions
std::ostream& sakurajin::unit_system::operator<<(std::ostream& os, const sakurajin::unit_system::power& t){
    auto t1 = sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " power";
}

sakurajin::unit_system::power sakurajin::unit_system::unit_cast(const sakurajin::unit_system::power& unit, long double new_multiplier, long double new_offset){
    auto valBase0 = (unit.value + unit.offset) * unit.multiplier;
    sakurajin::unit_system::power retval{valBase0/new_multiplier-new_offset, new_multiplier, new_offset};
    return retval;
}

sakurajin::unit_system::power sakurajin::unit_system::clamp(const sakurajin::unit_system::power& unit, const sakurajin::unit_system::power& lower, const sakurajin::unit_system::power& upper){
    auto _lower = unit_cast(lower, unit.multiplier, unit.offset);
    auto _upper = unit_cast(upper, unit.multiplier, unit.offset);

    auto val = unit.value > _lower.value ? ( unit.value < _upper.value ? unit.value : _upper.value ) : _lower.value;
    return sakurajin::unit_system::power{val, unit.multiplier, unit.offset};
}

sakurajin::unit_system::power std::abs(const sakurajin::unit_system::power& unit){
    auto inv = -unit;
    return unit > inv ? unit : inv;
}

// literals



sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _W(long double len){
    return sakurajin::unit_system::power{len,1.0, 0.0};
}

sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _W(unsigned long long int len){
    return sakurajin::unit_system::power{static_cast<long double>(len),1.0, 0.0};
}



sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _PW(long double len){
    return sakurajin::unit_system::power{len,1000000000000000.0, 0.0};
}

sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _PW(unsigned long long int len){
    return sakurajin::unit_system::power{static_cast<long double>(len),1000000000000000.0, 0.0};
}



sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _TW(long double len){
    return sakurajin::unit_system::power{len,1000000000000.0, 0.0};
}

sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _TW(unsigned long long int len){
    return sakurajin::unit_system::power{static_cast<long double>(len),1000000000000.0, 0.0};
}



sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _GW(long double len){
    return sakurajin::unit_system::power{len,1000000000.0, 0.0};
}

sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _GW(unsigned long long int len){
    return sakurajin::unit_system::power{static_cast<long double>(len),1000000000.0, 0.0};
}



sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _MW(long double len){
    return sakurajin::unit_system::power{len,1000000.0, 0.0};
}

sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _MW(unsigned long long int len){
    return sakurajin::unit_system::power{static_cast<long double>(len),1000000.0, 0.0};
}



sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _kW(long double len){
    return sakurajin::unit_system::power{len,1000.0, 0.0};
}

sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _kW(unsigned long long int len){
    return sakurajin::unit_system::power{static_cast<long double>(len),1000.0, 0.0};
}



sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _mW(long double len){
    return sakurajin::unit_system::power{len,0.001, 0.0};
}

sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _mW(unsigned long long int len){
    return sakurajin::unit_system::power{static_cast<long double>(len),0.001, 0.0};
}



sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _uW(long double len){
    return sakurajin::unit_system::power{len,1e-06, 0.0};
}

sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _uW(unsigned long long int len){
    return sakurajin::unit_system::power{static_cast<long double>(len),1e-06, 0.0};
}



sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _nW(long double len){
    return sakurajin::unit_system::power{len,1e-09, 0.0};
}

sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _nW(unsigned long long int len){
    return sakurajin::unit_system::power{static_cast<long double>(len),1e-09, 0.0};
}



sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _pW(long double len){
    return sakurajin::unit_system::power{len,1e-12, 0.0};
}

sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _pW(unsigned long long int len){
    return sakurajin::unit_system::power{static_cast<long double>(len),1e-12, 0.0};
}



sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _fW(long double len){
    return sakurajin::unit_system::power{len,1e-15, 0.0};
}

sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _fW(unsigned long long int len){
    return sakurajin::unit_system::power{static_cast<long double>(len),1e-15, 0.0};
}



sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _aW(long double len){
    return sakurajin::unit_system::power{len,1e-18, 0.0};
}

sakurajin::unit_system::power sakurajin::unit_system::literals::operator "" _aW(unsigned long long int len){
    return sakurajin::unit_system::power{static_cast<long double>(len),1e-18, 0.0};
}


