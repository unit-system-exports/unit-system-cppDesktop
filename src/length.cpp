#include "unit_system/length.hpp"

sakurajin::unit_system::length::length(): length{0.0}{}
sakurajin::unit_system::length::length(long double v): length{v,1,0}{}
sakurajin::unit_system::length::length(long double v, long double mult): length{v,mult,0}{}
sakurajin::unit_system::length::length(long double v, long double mult, long double off): multiplier{mult}, value{v}, offset{off}{}

//const functions
sakurajin::unit_system::length sakurajin::unit_system::length::operator*(long double scalar) const{
    sakurajin::unit_system::length retval{value*scalar, multiplier, offset};
    return retval;
}

sakurajin::unit_system::length operator*(long double scalar, const sakurajin::unit_system::length& val){
    return {val.value*scalar, val.multiplier, val.offset};
}

long double sakurajin::unit_system::length::operator/(const sakurajin::unit_system::length& other) const{
    auto otherVal = unit_cast(other, multiplier, offset);
    return value/otherVal.value;
}

sakurajin::unit_system::length sakurajin::unit_system::length::operator/(long double scalar) const{
    sakurajin::unit_system::length retval{value/scalar, multiplier, offset};
    return retval;
}

sakurajin::unit_system::length sakurajin::unit_system::length::operator+(const sakurajin::unit_system::length& other) const{
    auto retval = sakurajin::unit_system::unit_cast(other, multiplier,offset);
    retval.value += value;
    return retval;
}

sakurajin::unit_system::length sakurajin::unit_system::length::operator-(const sakurajin::unit_system::length& other) const{
    auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    retval.value = value - retval.value;
    return retval;
}

sakurajin::unit_system::length sakurajin::unit_system::length::operator-() const{
    return sakurajin::unit_system::length{-value,multiplier,offset};
}

sakurajin::unit_system::length::operator long double() const{
    auto retval = sakurajin::unit_system::unit_cast(*this, 1, 0);
    return retval.value;
}

//comparison operators
#if __cplusplus >= 202002L
    int sakurajin::unit_system::length::operator<=>(const sakurajin::unit_system::length& other) const{
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
    bool sakurajin::unit_system::length::operator<(const sakurajin::unit_system::length& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value < retval.value;
    }

    bool sakurajin::unit_system::length::operator>(const sakurajin::unit_system::length& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value > retval.value;
    }

    bool sakurajin::unit_system::length::operator<=(const sakurajin::unit_system::length& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value <= retval.value;
    }

    bool sakurajin::unit_system::length::operator>=(const sakurajin::unit_system::length& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value >= retval.value;
    }

    bool sakurajin::unit_system::length::operator==(const sakurajin::unit_system::length& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value == retval.value;
    }

    bool sakurajin::unit_system::length::operator!=(const sakurajin::unit_system::length& other) const{
        return ! (*this == other);
    }
#endif

//non const member functions
void sakurajin::unit_system::length::operator*=(long double scalar){
    value*=scalar;
}

void sakurajin::unit_system::length::operator/=(long double scalar){
    value/=scalar;
}

void sakurajin::unit_system::length::operator+=(const sakurajin::unit_system::length& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value += otherVal.value;
}

void sakurajin::unit_system::length::operator-=(const sakurajin::unit_system::length& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value -= otherVal.value;
}

void sakurajin::unit_system::length::operator=(const sakurajin::unit_system::length& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value = otherVal.value;
}

// external functions
std::ostream& sakurajin::unit_system::operator<<(std::ostream& os, const sakurajin::unit_system::length& t){
    auto t1 = sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " length";
}

sakurajin::unit_system::length sakurajin::unit_system::unit_cast(const sakurajin::unit_system::length& unit, long double new_multiplier, long double new_offset){
    auto valBase0 = (unit.value + unit.offset) * unit.multiplier;
    sakurajin::unit_system::length retval{valBase0/new_multiplier-new_offset, new_multiplier, new_offset};
    return retval;
}

sakurajin::unit_system::length sakurajin::unit_system::clamp(const sakurajin::unit_system::length& unit, const sakurajin::unit_system::length& lower, const sakurajin::unit_system::length& upper){
    auto _lower = unit_cast(lower, unit.multiplier, unit.offset);
    auto _upper = unit_cast(upper, unit.multiplier, unit.offset);

    auto val = unit.value > _lower.value ? ( unit.value < _upper.value ? unit.value : _upper.value ) : _lower.value;
    return sakurajin::unit_system::length{val, unit.multiplier, unit.offset};
}

sakurajin::unit_system::length std::abs(const sakurajin::unit_system::length& unit){
    auto inv = -unit;
    return unit > inv ? unit : inv;
}

// literals



sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _m(long double len){
    return sakurajin::unit_system::length{len,1.0, 0.0};
}

sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _m(unsigned long long int len){
    return sakurajin::unit_system::length{static_cast<long double>(len),1.0, 0.0};
}



sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _km(long double len){
    return sakurajin::unit_system::length{len,1000.0, 0.0};
}

sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _km(unsigned long long int len){
    return sakurajin::unit_system::length{static_cast<long double>(len),1000.0, 0.0};
}



sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _dm(long double len){
    return sakurajin::unit_system::length{len,0.1, 0.0};
}

sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _dm(unsigned long long int len){
    return sakurajin::unit_system::length{static_cast<long double>(len),0.1, 0.0};
}



sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _cm(long double len){
    return sakurajin::unit_system::length{len,0.01, 0.0};
}

sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _cm(unsigned long long int len){
    return sakurajin::unit_system::length{static_cast<long double>(len),0.01, 0.0};
}



sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _mm(long double len){
    return sakurajin::unit_system::length{len,0.001, 0.0};
}

sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _mm(unsigned long long int len){
    return sakurajin::unit_system::length{static_cast<long double>(len),0.001, 0.0};
}



sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _um(long double len){
    return sakurajin::unit_system::length{len,1e-06, 0.0};
}

sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _um(unsigned long long int len){
    return sakurajin::unit_system::length{static_cast<long double>(len),1e-06, 0.0};
}



sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _nm(long double len){
    return sakurajin::unit_system::length{len,1e-09, 0.0};
}

sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _nm(unsigned long long int len){
    return sakurajin::unit_system::length{static_cast<long double>(len),1e-09, 0.0};
}



sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _pm(long double len){
    return sakurajin::unit_system::length{len,1e-12, 0.0};
}

sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _pm(unsigned long long int len){
    return sakurajin::unit_system::length{static_cast<long double>(len),1e-12, 0.0};
}



sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _fm(long double len){
    return sakurajin::unit_system::length{len,1e-15, 0.0};
}

sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _fm(unsigned long long int len){
    return sakurajin::unit_system::length{static_cast<long double>(len),1e-15, 0.0};
}



sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _am(long double len){
    return sakurajin::unit_system::length{len,1e-18, 0.0};
}

sakurajin::unit_system::length sakurajin::unit_system::literals::operator "" _am(unsigned long long int len){
    return sakurajin::unit_system::length{static_cast<long double>(len),1e-18, 0.0};
}


