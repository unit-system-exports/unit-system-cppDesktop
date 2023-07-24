#include "unit_system/speed.hpp"

sakurajin::unit_system::speed::speed(): speed{0.0}{}
sakurajin::unit_system::speed::speed(long double v): speed{v,1,0}{}
sakurajin::unit_system::speed::speed(long double v, long double mult): speed{v,mult,0}{}
sakurajin::unit_system::speed::speed(long double v, long double mult, long double off): multiplier{mult}, value{v}, offset{off}{}

//const functions
sakurajin::unit_system::speed sakurajin::unit_system::speed::operator*(long double scalar) const{
    sakurajin::unit_system::speed retval{value*scalar, multiplier, offset};
    return retval;
}

sakurajin::unit_system::speed operator*(long double scalar, const sakurajin::unit_system::speed& val){
    return {val.value*scalar, val.multiplier, val.offset};
}

long double sakurajin::unit_system::speed::operator/(const sakurajin::unit_system::speed& other) const{
    auto otherVal = unit_cast(other, multiplier, offset);
    return value/otherVal.value;
}

sakurajin::unit_system::speed sakurajin::unit_system::speed::operator/(long double scalar) const{
    sakurajin::unit_system::speed retval{value/scalar, multiplier, offset};
    return retval;
}

sakurajin::unit_system::speed sakurajin::unit_system::speed::operator+(const sakurajin::unit_system::speed& other) const{
    auto retval = sakurajin::unit_system::unit_cast(other, multiplier,offset);
    retval.value += value;
    return retval;
}

sakurajin::unit_system::speed sakurajin::unit_system::speed::operator-(const sakurajin::unit_system::speed& other) const{
    auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    retval.value = value - retval.value;
    return retval;
}

sakurajin::unit_system::speed sakurajin::unit_system::speed::operator-() const{
    return sakurajin::unit_system::speed{-value,multiplier,offset};
}

sakurajin::unit_system::speed::operator long double() const{
    auto retval = sakurajin::unit_system::unit_cast(*this, 1, 0);
    return retval.value;
}

//comparison operators
#if __cplusplus >= 202002L
    int sakurajin::unit_system::speed::operator<=>(const sakurajin::unit_system::speed& other) const{
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
    bool sakurajin::unit_system::speed::operator<(const sakurajin::unit_system::speed& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value < retval.value;
    }

    bool sakurajin::unit_system::speed::operator>(const sakurajin::unit_system::speed& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value > retval.value;
    }

    bool sakurajin::unit_system::speed::operator<=(const sakurajin::unit_system::speed& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value <= retval.value;
    }

    bool sakurajin::unit_system::speed::operator>=(const sakurajin::unit_system::speed& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value >= retval.value;
    }

    bool sakurajin::unit_system::speed::operator==(const sakurajin::unit_system::speed& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value == retval.value;
    }

    bool sakurajin::unit_system::speed::operator!=(const sakurajin::unit_system::speed& other) const{
        return ! (*this == other);
    }
#endif

//non const member functions
void sakurajin::unit_system::speed::operator*=(long double scalar){
    value*=scalar;
}

void sakurajin::unit_system::speed::operator/=(long double scalar){
    value/=scalar;
}

void sakurajin::unit_system::speed::operator+=(const sakurajin::unit_system::speed& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value += otherVal.value;
}

void sakurajin::unit_system::speed::operator-=(const sakurajin::unit_system::speed& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value -= otherVal.value;
}

void sakurajin::unit_system::speed::operator=(const sakurajin::unit_system::speed& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value = otherVal.value;
}

// external functions
std::ostream& sakurajin::unit_system::operator<<(std::ostream& os, const sakurajin::unit_system::speed& t){
    auto t1 = sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " speed";
}

sakurajin::unit_system::speed sakurajin::unit_system::unit_cast(const sakurajin::unit_system::speed& unit, long double new_multiplier, long double new_offset){
    auto valBase0 = (unit.value + unit.offset) * unit.multiplier;
    sakurajin::unit_system::speed retval{valBase0/new_multiplier-new_offset, new_multiplier, new_offset};
    return retval;
}

sakurajin::unit_system::speed sakurajin::unit_system::clamp(const sakurajin::unit_system::speed& unit, const sakurajin::unit_system::speed& lower, const sakurajin::unit_system::speed& upper){
    auto _lower = unit_cast(lower, unit.multiplier, unit.offset);
    auto _upper = unit_cast(upper, unit.multiplier, unit.offset);

    auto val = unit.value > _lower.value ? ( unit.value < _upper.value ? unit.value : _upper.value ) : _lower.value;
    return sakurajin::unit_system::speed{val, unit.multiplier, unit.offset};
}

sakurajin::unit_system::speed std::abs(const sakurajin::unit_system::speed& unit){
    auto inv = -unit;
    return unit > inv ? unit : inv;
}

// literals



sakurajin::unit_system::speed sakurajin::unit_system::literals::operator "" _mps(long double len){
    return sakurajin::unit_system::speed{len,1.0, 0.0};
}

sakurajin::unit_system::speed sakurajin::unit_system::literals::operator "" _mps(unsigned long long int len){
    return sakurajin::unit_system::speed{static_cast<long double>(len),1.0, 0.0};
}



sakurajin::unit_system::speed sakurajin::unit_system::literals::operator "" _kmph(long double len){
    return sakurajin::unit_system::speed{len,0.2777777777777778, 0.0};
}

sakurajin::unit_system::speed sakurajin::unit_system::literals::operator "" _kmph(unsigned long long int len){
    return sakurajin::unit_system::speed{static_cast<long double>(len),0.2777777777777778, 0.0};
}


