#include "unit_system/momentum.hpp"


#include "unit_system/speed.hpp"

#include "unit_system/energy.hpp"

#include "unit_system/force.hpp"

#include "unit_system/time_si.hpp"

#include "unit_system/mass.hpp"



sakurajin::unit_system::momentum::momentum(): momentum{0.0}{}
sakurajin::unit_system::momentum::momentum(long double v): momentum{v,1,0}{}
sakurajin::unit_system::momentum::momentum(long double v, long double mult): momentum{v,mult,0}{}
sakurajin::unit_system::momentum::momentum(long double v, long double mult, long double off): multiplier{mult}, value{v}, offset{off}{}

//const functions
sakurajin::unit_system::momentum sakurajin::unit_system::momentum::operator*(long double scalar) const{
    sakurajin::unit_system::momentum retval{value*scalar, multiplier, offset};
    return retval;
}

sakurajin::unit_system::momentum operator*(long double scalar, const sakurajin::unit_system::momentum& val){
    return {val.value*scalar, val.multiplier, val.offset};
}

long double sakurajin::unit_system::momentum::operator/(const sakurajin::unit_system::momentum& other) const{
    auto otherVal = unit_cast(other, multiplier, offset);
    return value/otherVal.value;
}

sakurajin::unit_system::momentum sakurajin::unit_system::momentum::operator/(long double scalar) const{
    sakurajin::unit_system::momentum retval{value/scalar, multiplier, offset};
    return retval;
}

sakurajin::unit_system::momentum sakurajin::unit_system::momentum::operator+(const sakurajin::unit_system::momentum& other) const{
    auto retval = sakurajin::unit_system::unit_cast(other, multiplier,offset);
    retval.value += value;
    return retval;
}

sakurajin::unit_system::momentum sakurajin::unit_system::momentum::operator-(const sakurajin::unit_system::momentum& other) const{
    auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    retval.value = value - retval.value;
    return retval;
}

sakurajin::unit_system::momentum sakurajin::unit_system::momentum::operator-() const{
    return sakurajin::unit_system::momentum{-value,multiplier,offset};
}

sakurajin::unit_system::momentum::operator long double() const{
    auto retval = sakurajin::unit_system::unit_cast(*this, 1, 0);
    return retval.value;
}

sakurajin::unit_system::momentum sakurajin::unit_system::momentum::convert_multiplier(long double new_multiplier) const{
    return convert_copy(new_multiplier, offset);
}

sakurajin::unit_system::momentum sakurajin::unit_system::momentum::convert_offset(long double new_offset) const{
    return convert_copy(multiplier, new_offset);
}

sakurajin::unit_system::momentum sakurajin::unit_system::momentum::convert_copy(long double new_multiplier, long double new_offset) const{
    auto valBase0 = (value + offset) * multiplier;
    sakurajin::unit_system::momentum retval{valBase0/new_multiplier-new_offset, new_multiplier, new_offset};
    return retval;
}

//comparison operators
#if __cplusplus >= 202002L
    int sakurajin::unit_system::momentum::operator<=>(const sakurajin::unit_system::momentum& other) const{
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
    bool sakurajin::unit_system::momentum::operator<(const sakurajin::unit_system::momentum& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value < retval.value;
    }

    bool sakurajin::unit_system::momentum::operator>(const sakurajin::unit_system::momentum& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value > retval.value;
    }

    bool sakurajin::unit_system::momentum::operator<=(const sakurajin::unit_system::momentum& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value <= retval.value;
    }

    bool sakurajin::unit_system::momentum::operator>=(const sakurajin::unit_system::momentum& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value >= retval.value;
    }

    bool sakurajin::unit_system::momentum::operator==(const sakurajin::unit_system::momentum& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value == retval.value;
    }

    bool sakurajin::unit_system::momentum::operator!=(const sakurajin::unit_system::momentum& other) const{
        return ! (*this == other);
    }
#endif

//non const member functions
void sakurajin::unit_system::momentum::operator*=(long double scalar){
    value*=scalar;
}

void sakurajin::unit_system::momentum::operator/=(long double scalar){
    value/=scalar;
}

void sakurajin::unit_system::momentum::operator+=(const sakurajin::unit_system::momentum& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value += otherVal.value;
}

void sakurajin::unit_system::momentum::operator-=(const sakurajin::unit_system::momentum& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value -= otherVal.value;
}

void sakurajin::unit_system::momentum::operator=(const sakurajin::unit_system::momentum& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value = otherVal.value;
}


    
        
    
    
        sakurajin::unit_system::energy sakurajin::unit_system::momentum::operator*(const speed& other) const{
            sakurajin::unit_system::momentum _v1 = convert_offset(0);
            sakurajin::unit_system::speed _v2 = other.convert_offset(0);
            return sakurajin::unit_system::energy{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
        }
    

    
        
        sakurajin::unit_system::time_si sakurajin::unit_system::momentum::operator/(const force& other) const{
            sakurajin::unit_system::momentum _v1 = convert_offset(0);
            sakurajin::unit_system::force _v2 = other.convert_offset(0);
            return sakurajin::unit_system::time_si{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
        }
        
    
    
        sakurajin::unit_system::force sakurajin::unit_system::momentum::operator/(const time_si& other) const{
            sakurajin::unit_system::momentum _v1 = convert_offset(0);
            sakurajin::unit_system::time_si _v2 = other.convert_offset(0);
            return sakurajin::unit_system::force{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
        }
    

    
        
        sakurajin::unit_system::speed sakurajin::unit_system::momentum::operator/(const mass& other) const{
            sakurajin::unit_system::momentum _v1 = convert_offset(0);
            sakurajin::unit_system::mass _v2 = other.convert_offset(0);
            return sakurajin::unit_system::speed{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
        }
        
    
    
        sakurajin::unit_system::mass sakurajin::unit_system::momentum::operator/(const speed& other) const{
            sakurajin::unit_system::momentum _v1 = convert_offset(0);
            sakurajin::unit_system::speed _v2 = other.convert_offset(0);
            return sakurajin::unit_system::mass{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
        }
    


// external functions
std::ostream& sakurajin::unit_system::operator<<(std::ostream& os, const sakurajin::unit_system::momentum& t){
    auto t1 = sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " momentum";
}

sakurajin::unit_system::momentum sakurajin::unit_system::unit_cast(const sakurajin::unit_system::momentum& unit, long double new_multiplier, long double new_offset){
    return unit.convert_copy(new_multiplier, new_offset);
}

sakurajin::unit_system::momentum sakurajin::unit_system::clamp(const sakurajin::unit_system::momentum& unit, const sakurajin::unit_system::momentum& lower, const sakurajin::unit_system::momentum& upper){
    auto _lower = unit_cast(lower, unit.multiplier, unit.offset);
    auto _upper = unit_cast(upper, unit.multiplier, unit.offset);

    auto val = unit.value > _lower.value ? ( unit.value < _upper.value ? unit.value : _upper.value ) : _lower.value;
    return sakurajin::unit_system::momentum{val, unit.multiplier, unit.offset};
}

sakurajin::unit_system::momentum std::abs(const sakurajin::unit_system::momentum& unit){
    auto inv = -unit;
    return unit > inv ? unit : inv;
}

// literals



sakurajin::unit_system::momentum sakurajin::unit_system::literals::operator "" _kgmps(long double len){
    return sakurajin::unit_system::momentum{len,1.0, 0.0};
}

sakurajin::unit_system::momentum sakurajin::unit_system::literals::operator "" _kgmps(unsigned long long int len){
    return sakurajin::unit_system::momentum{static_cast<long double>(len),1.0, 0.0};
}


