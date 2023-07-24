#include "unit_system/force.hpp"

sakurajin::unit_system::force::force(): force{0.0}{}
sakurajin::unit_system::force::force(long double v): force{v,1,0}{}
sakurajin::unit_system::force::force(long double v, long double mult): force{v,mult,0}{}
sakurajin::unit_system::force::force(long double v, long double mult, long double off): multiplier{mult}, value{v}, offset{off}{}

//const functions
sakurajin::unit_system::force sakurajin::unit_system::force::operator*(long double scalar) const{
    sakurajin::unit_system::force retval{value*scalar, multiplier, offset};
    return retval;
}

sakurajin::unit_system::force operator*(long double scalar, const sakurajin::unit_system::force& val){
    return {val.value*scalar, val.multiplier, val.offset};
}

long double sakurajin::unit_system::force::operator/(const sakurajin::unit_system::force& other) const{
    auto otherVal = unit_cast(other, multiplier, offset);
    return value/otherVal.value;
}

sakurajin::unit_system::force sakurajin::unit_system::force::operator/(long double scalar) const{
    sakurajin::unit_system::force retval{value/scalar, multiplier, offset};
    return retval;
}

sakurajin::unit_system::force sakurajin::unit_system::force::operator+(const sakurajin::unit_system::force& other) const{
    auto retval = sakurajin::unit_system::unit_cast(other, multiplier,offset);
    retval.value += value;
    return retval;
}

sakurajin::unit_system::force sakurajin::unit_system::force::operator-(const sakurajin::unit_system::force& other) const{
    auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    retval.value = value - retval.value;
    return retval;
}

sakurajin::unit_system::force sakurajin::unit_system::force::operator-() const{
    return sakurajin::unit_system::force{-value,multiplier,offset};
}

sakurajin::unit_system::force::operator long double() const{
    auto retval = sakurajin::unit_system::unit_cast(*this, 1, 0);
    return retval.value;
}

//comparison operators
#if __cplusplus >= 202002L
    int sakurajin::unit_system::force::operator<=>(const sakurajin::unit_system::force& other) const{
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
    bool sakurajin::unit_system::force::operator<(const sakurajin::unit_system::force& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value < retval.value;
    }

    bool sakurajin::unit_system::force::operator>(const sakurajin::unit_system::force& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value > retval.value;
    }

    bool sakurajin::unit_system::force::operator<=(const sakurajin::unit_system::force& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value <= retval.value;
    }

    bool sakurajin::unit_system::force::operator>=(const sakurajin::unit_system::force& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value >= retval.value;
    }

    bool sakurajin::unit_system::force::operator==(const sakurajin::unit_system::force& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value == retval.value;
    }

    bool sakurajin::unit_system::force::operator!=(const sakurajin::unit_system::force& other) const{
        return ! (*this == other);
    }
#endif

//non const member functions
void sakurajin::unit_system::force::operator*=(long double scalar){
    value*=scalar;
}

void sakurajin::unit_system::force::operator/=(long double scalar){
    value/=scalar;
}

void sakurajin::unit_system::force::operator+=(const sakurajin::unit_system::force& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value += otherVal.value;
}

void sakurajin::unit_system::force::operator-=(const sakurajin::unit_system::force& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value -= otherVal.value;
}

void sakurajin::unit_system::force::operator=(const sakurajin::unit_system::force& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value = otherVal.value;
}

// external functions
std::ostream& sakurajin::unit_system::operator<<(std::ostream& os, const sakurajin::unit_system::force& t){
    auto t1 = sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " force";
}

sakurajin::unit_system::force sakurajin::unit_system::unit_cast(const sakurajin::unit_system::force& unit, long double new_multiplier, long double new_offset){
    auto valBase0 = (unit.value + unit.offset) * unit.multiplier;
    sakurajin::unit_system::force retval{valBase0/new_multiplier-new_offset, new_multiplier, new_offset};
    return retval;
}

sakurajin::unit_system::force sakurajin::unit_system::clamp(const sakurajin::unit_system::force& unit, const sakurajin::unit_system::force& lower, const sakurajin::unit_system::force& upper){
    auto _lower = unit_cast(lower, unit.multiplier, unit.offset);
    auto _upper = unit_cast(upper, unit.multiplier, unit.offset);

    auto val = unit.value > _lower.value ? ( unit.value < _upper.value ? unit.value : _upper.value ) : _lower.value;
    return sakurajin::unit_system::force{val, unit.multiplier, unit.offset};
}

sakurajin::unit_system::force std::abs(const sakurajin::unit_system::force& unit){
    auto inv = -unit;
    return unit > inv ? unit : inv;
}

// literals



sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _N(long double len){
    return sakurajin::unit_system::force{len,1.0, 0.0};
}

sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _N(unsigned long long int len){
    return sakurajin::unit_system::force{static_cast<long double>(len),1.0, 0.0};
}



sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _PN(long double len){
    return sakurajin::unit_system::force{len,1000000000000000.0, 0.0};
}

sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _PN(unsigned long long int len){
    return sakurajin::unit_system::force{static_cast<long double>(len),1000000000000000.0, 0.0};
}



sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _TN(long double len){
    return sakurajin::unit_system::force{len,1000000000000.0, 0.0};
}

sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _TN(unsigned long long int len){
    return sakurajin::unit_system::force{static_cast<long double>(len),1000000000000.0, 0.0};
}



sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _GN(long double len){
    return sakurajin::unit_system::force{len,1000000000.0, 0.0};
}

sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _GN(unsigned long long int len){
    return sakurajin::unit_system::force{static_cast<long double>(len),1000000000.0, 0.0};
}



sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _MN(long double len){
    return sakurajin::unit_system::force{len,1000000.0, 0.0};
}

sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _MN(unsigned long long int len){
    return sakurajin::unit_system::force{static_cast<long double>(len),1000000.0, 0.0};
}



sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _kN(long double len){
    return sakurajin::unit_system::force{len,1000.0, 0.0};
}

sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _kN(unsigned long long int len){
    return sakurajin::unit_system::force{static_cast<long double>(len),1000.0, 0.0};
}



sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _mN(long double len){
    return sakurajin::unit_system::force{len,0.001, 0.0};
}

sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _mN(unsigned long long int len){
    return sakurajin::unit_system::force{static_cast<long double>(len),0.001, 0.0};
}



sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _uN(long double len){
    return sakurajin::unit_system::force{len,1e-06, 0.0};
}

sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _uN(unsigned long long int len){
    return sakurajin::unit_system::force{static_cast<long double>(len),1e-06, 0.0};
}



sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _nN(long double len){
    return sakurajin::unit_system::force{len,1e-09, 0.0};
}

sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _nN(unsigned long long int len){
    return sakurajin::unit_system::force{static_cast<long double>(len),1e-09, 0.0};
}



sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _pN(long double len){
    return sakurajin::unit_system::force{len,1e-12, 0.0};
}

sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _pN(unsigned long long int len){
    return sakurajin::unit_system::force{static_cast<long double>(len),1e-12, 0.0};
}



sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _fN(long double len){
    return sakurajin::unit_system::force{len,1e-15, 0.0};
}

sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _fN(unsigned long long int len){
    return sakurajin::unit_system::force{static_cast<long double>(len),1e-15, 0.0};
}



sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _aN(long double len){
    return sakurajin::unit_system::force{len,1e-18, 0.0};
}

sakurajin::unit_system::force sakurajin::unit_system::literals::operator "" _aN(unsigned long long int len){
    return sakurajin::unit_system::force{static_cast<long double>(len),1e-18, 0.0};
}


