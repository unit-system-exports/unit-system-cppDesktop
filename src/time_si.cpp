#include "unit_system.hpp"

sakurajin::unit_system::time_si::time_si(): time_si{0.0}{}
sakurajin::unit_system::time_si::time_si(long double v): time_si{v,1,0}{}
sakurajin::unit_system::time_si::time_si(long double v, long double mult): time_si{v,mult,0}{}
sakurajin::unit_system::time_si::time_si(long double v, long double mult, long double off): multiplier{mult}, value{v}, offset{off}{}

//const functions
sakurajin::unit_system::time_si sakurajin::unit_system::time_si::operator*(long double scalar) const{
    sakurajin::unit_system::time_si retval{value*scalar, multiplier, offset};
    return retval;
}

sakurajin::unit_system::time_si operator*(long double scalar, const sakurajin::unit_system::time_si& val){
    return {val.value*scalar, val.multiplier, val.offset};
}

long double sakurajin::unit_system::time_si::operator/(const sakurajin::unit_system::time_si& other) const{
    auto otherVal = unit_cast(other, multiplier, offset);
    return value/otherVal.value;
}

sakurajin::unit_system::time_si sakurajin::unit_system::time_si::operator/(long double scalar) const{
    sakurajin::unit_system::time_si retval{value/scalar, multiplier, offset};
    return retval;
}

sakurajin::unit_system::time_si sakurajin::unit_system::time_si::operator+(const sakurajin::unit_system::time_si& other) const{
    auto retval = sakurajin::unit_system::unit_cast(other, multiplier,offset);
    retval.value += value;
    return retval;
}

sakurajin::unit_system::time_si sakurajin::unit_system::time_si::operator-(const sakurajin::unit_system::time_si& other) const{
    auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    retval.value = value - retval.value;
    return retval;
}

sakurajin::unit_system::time_si sakurajin::unit_system::time_si::operator-() const{
    return sakurajin::unit_system::time_si{-value,multiplier,offset};
}

sakurajin::unit_system::time_si::operator long double() const{
    auto retval = sakurajin::unit_system::unit_cast(*this, 1, 0);
    return retval.value;
}

sakurajin::unit_system::time_si sakurajin::unit_system::time_si::convert_multiplier(long double new_multiplier) const{
    return convert_copy(new_multiplier, offset);
}

sakurajin::unit_system::time_si sakurajin::unit_system::time_si::convert_offset(long double new_offset) const{
    return convert_copy(multiplier, new_offset);
}

sakurajin::unit_system::time_si sakurajin::unit_system::time_si::convert_copy(long double new_multiplier, long double new_offset) const{
    auto valBase0 = (value + offset) * multiplier;
    sakurajin::unit_system::time_si retval{valBase0/new_multiplier-new_offset, new_multiplier, new_offset};
    return retval;
}

//comparison operators
#if __cplusplus >= 202002L
    int sakurajin::unit_system::time_si::operator<=>(const sakurajin::unit_system::time_si& other) const{
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
    bool sakurajin::unit_system::time_si::operator<(const sakurajin::unit_system::time_si& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value < retval.value;
    }

    bool sakurajin::unit_system::time_si::operator>(const sakurajin::unit_system::time_si& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value > retval.value;
    }

    bool sakurajin::unit_system::time_si::operator<=(const sakurajin::unit_system::time_si& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value <= retval.value;
    }

    bool sakurajin::unit_system::time_si::operator>=(const sakurajin::unit_system::time_si& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value >= retval.value;
    }

    bool sakurajin::unit_system::time_si::operator==(const sakurajin::unit_system::time_si& other) const{
        const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
        return value == retval.value;
    }

    bool sakurajin::unit_system::time_si::operator!=(const sakurajin::unit_system::time_si& other) const{
        return ! (*this == other);
    }
#endif

//non const member functions
void sakurajin::unit_system::time_si::operator*=(long double scalar){
    value*=scalar;
}

void sakurajin::unit_system::time_si::operator/=(long double scalar){
    value/=scalar;
}

void sakurajin::unit_system::time_si::operator+=(const sakurajin::unit_system::time_si& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value += otherVal.value;
}

void sakurajin::unit_system::time_si::operator-=(const sakurajin::unit_system::time_si& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value -= otherVal.value;
}

void sakurajin::unit_system::time_si::operator=(const sakurajin::unit_system::time_si& other){
    const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
    value = otherVal.value;
}


    
        
        sakurajin::unit_system::length sakurajin::unit_system::time_si::operator*(const speed& other) const{
            sakurajin::unit_system::speed _v1 = other.convert_offset(0);
            sakurajin::unit_system::time_si _v2 = convert_offset(0);
            return sakurajin::unit_system::length{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
        }
        
    
    

    
        
        sakurajin::unit_system::speed sakurajin::unit_system::time_si::operator*(const acceleration& other) const{
            sakurajin::unit_system::acceleration _v1 = other.convert_offset(0);
            sakurajin::unit_system::time_si _v2 = convert_offset(0);
            return sakurajin::unit_system::speed{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
        }
        
    
    

    
        
        sakurajin::unit_system::energy sakurajin::unit_system::time_si::operator*(const power& other) const{
            sakurajin::unit_system::power _v1 = other.convert_offset(0);
            sakurajin::unit_system::time_si _v2 = convert_offset(0);
            return sakurajin::unit_system::energy{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
        }
        
    
    

    
        
        sakurajin::unit_system::momentum sakurajin::unit_system::time_si::operator*(const force& other) const{
            sakurajin::unit_system::force _v1 = other.convert_offset(0);
            sakurajin::unit_system::time_si _v2 = convert_offset(0);
            return sakurajin::unit_system::momentum{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
        }
        
    
    


// external functions
std::ostream& sakurajin::unit_system::operator<<(std::ostream& os, const sakurajin::unit_system::time_si& t){
    auto t1 = sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " time_si";
}

sakurajin::unit_system::time_si sakurajin::unit_system::unit_cast(const sakurajin::unit_system::time_si& unit, long double new_multiplier, long double new_offset){
    return unit.convert_copy(new_multiplier, new_offset);
}

sakurajin::unit_system::time_si sakurajin::unit_system::clamp(const sakurajin::unit_system::time_si& unit, const sakurajin::unit_system::time_si& lower, const sakurajin::unit_system::time_si& upper){
    auto _lower = unit_cast(lower, unit.multiplier, unit.offset);
    auto _upper = unit_cast(upper, unit.multiplier, unit.offset);

    auto val = unit.value > _lower.value ? ( unit.value < _upper.value ? unit.value : _upper.value ) : _lower.value;
    return sakurajin::unit_system::time_si{val, unit.multiplier, unit.offset};
}

sakurajin::unit_system::time_si std::abs(const sakurajin::unit_system::time_si& unit){
    auto inv = -unit;
    return unit > inv ? unit : inv;
}

// literals



sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _a(long double len){
    return sakurajin::unit_system::time_si{len,31536000000.0, 0.0};
}

sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _a(unsigned long long int len){
    return sakurajin::unit_system::time_si{static_cast<long double>(len),31536000000.0, 0.0};
}



sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _d(long double len){
    return sakurajin::unit_system::time_si{len,86400000.0, 0.0};
}

sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _d(unsigned long long int len){
    return sakurajin::unit_system::time_si{static_cast<long double>(len),86400000.0, 0.0};
}



sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _h(long double len){
    return sakurajin::unit_system::time_si{len,3600.0, 0.0};
}

sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _h(unsigned long long int len){
    return sakurajin::unit_system::time_si{static_cast<long double>(len),3600.0, 0.0};
}



sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _minute(long double len){
    return sakurajin::unit_system::time_si{len,60.0, 0.0};
}

sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _minute(unsigned long long int len){
    return sakurajin::unit_system::time_si{static_cast<long double>(len),60.0, 0.0};
}



sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _s(long double len){
    return sakurajin::unit_system::time_si{len,1.0, 0.0};
}

sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _s(unsigned long long int len){
    return sakurajin::unit_system::time_si{static_cast<long double>(len),1.0, 0.0};
}



sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _ms(long double len){
    return sakurajin::unit_system::time_si{len,0.001, 0.0};
}

sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _ms(unsigned long long int len){
    return sakurajin::unit_system::time_si{static_cast<long double>(len),0.001, 0.0};
}



sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _us(long double len){
    return sakurajin::unit_system::time_si{len,1e-06, 0.0};
}

sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _us(unsigned long long int len){
    return sakurajin::unit_system::time_si{static_cast<long double>(len),1e-06, 0.0};
}



sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _ns(long double len){
    return sakurajin::unit_system::time_si{len,1e-09, 0.0};
}

sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _ns(unsigned long long int len){
    return sakurajin::unit_system::time_si{static_cast<long double>(len),1e-09, 0.0};
}



sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _ps(long double len){
    return sakurajin::unit_system::time_si{len,1e-12, 0.0};
}

sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _ps(unsigned long long int len){
    return sakurajin::unit_system::time_si{static_cast<long double>(len),1e-12, 0.0};
}



sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _fs(long double len){
    return sakurajin::unit_system::time_si{len,1e-15, 0.0};
}

sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _fs(unsigned long long int len){
    return sakurajin::unit_system::time_si{static_cast<long double>(len),1e-15, 0.0};
}



sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _as(long double len){
    return sakurajin::unit_system::time_si{len,1e-18, 0.0};
}

sakurajin::unit_system::time_si sakurajin::unit_system::literals::operator "" _as(unsigned long long int len){
    return sakurajin::unit_system::time_si{static_cast<long double>(len),1e-18, 0.0};
}


