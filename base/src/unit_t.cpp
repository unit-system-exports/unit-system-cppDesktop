#include "unit_t.hpp"

#include <cmath>
#include <algorithm>

//the simple unit cast
sakurajin::unit_system::base::unit_t sakurajin::unit_system::base::unit_cast(const sakurajin::unit_system::base::unit_t& unit, double new_multiplier){
    sakurajin::unit_system::base::unit_t retval{unit.value * (unit.multiplier / new_multiplier), new_multiplier};
    return retval;
}

//All of the constructors
sakurajin::unit_system::base::unit_t::unit_t(double v): value{v}{};
sakurajin::unit_system::base::unit_t::unit_t(double v, double mult): multiplier{mult}, value{v}{};

//const member functions
sakurajin::unit_system::base::unit_t sakurajin::unit_system::base::unit_t::operator*(double scalar) const{
    sakurajin::unit_system::base::unit_t retval{value*scalar, multiplier};
    return retval;
}

sakurajin::unit_system::base::unit_t sakurajin::unit_system::base::unit_t::operator/(double scalar) const{
    sakurajin::unit_system::base::unit_t retval{value/scalar, multiplier};
    return retval;
}

sakurajin::unit_system::base::unit_t sakurajin::unit_system::base::unit_t::operator+(const sakurajin::unit_system::base::unit_t& other) const{
    auto retval = other.multiplier == multiplier ? other : sakurajin::unit_system::base::unit_cast(other,multiplier);
    retval.value += value;
    return retval;
}

sakurajin::unit_system::base::unit_t sakurajin::unit_system::base::unit_t::operator-(const sakurajin::unit_system::base::unit_t& other) const{
    auto retval = other.multiplier == multiplier ? other : sakurajin::unit_system::base::unit_cast(other,multiplier);
    retval.value = value - retval.value;
    return retval;
}

//comparison operators
bool sakurajin::unit_system::base::unit_t::operator<(const sakurajin::unit_system::base::unit_t& other) const{
    const auto retval = other.multiplier == multiplier ? other : sakurajin::unit_system::base::unit_cast(other,multiplier);
    return value < retval.value;
}

bool sakurajin::unit_system::base::unit_t::operator>(const sakurajin::unit_system::base::unit_t& other) const{
    const auto retval = other.multiplier == multiplier ? other : sakurajin::unit_system::base::unit_cast(other,multiplier);
    return value > retval.value;
}

bool sakurajin::unit_system::base::unit_t::operator<=(const sakurajin::unit_system::base::unit_t& other) const{
    const auto retval = other.multiplier == multiplier ? other : sakurajin::unit_system::base::unit_cast(other,multiplier);
    return value <= retval.value;
}

bool sakurajin::unit_system::base::unit_t::operator>=(const sakurajin::unit_system::base::unit_t& other) const{
    const auto retval = other.multiplier == multiplier ? other : sakurajin::unit_system::base::unit_cast(other,multiplier);
    return value >= retval.value;
}

bool sakurajin::unit_system::base::unit_t::operator==(const sakurajin::unit_system::base::unit_t& other) const{
    const auto retval = other.multiplier == multiplier ? other : sakurajin::unit_system::base::unit_cast(other,multiplier);
    auto delta = value-retval.value;
    auto epsilon = 0.000001 * std::max(std::abs(value), std::abs(retval.value));
    return std::abs(delta) < epsilon;
}

bool sakurajin::unit_system::base::unit_t::operator!=(const sakurajin::unit_system::base::unit_t& other) const{
    return ! (*this == other);
}

#if __cplusplus >= 202002L
int sakurajin::unit_system::base::unit_t::operator<=>(const sakurajin::unit_system::base::unit_t& other) const{
    const auto retval = other.multiplier == multiplier ? other : sakurajin::unit_system::base::unit_cast(other,multiplier);
    if(*this < retval){
        return -1;
    }
    
    if(*this > retval){
        return 1;
    }
    
    return 0;
}
#endif

//non const member functions
void sakurajin::unit_system::base::unit_t::operator*=(double scalar){
    value*=scalar;
}

void sakurajin::unit_system::base::unit_t::operator/=(double scalar){
    value/=scalar;
}

void sakurajin::unit_system::base::unit_t::operator+=(const sakurajin::unit_system::base::unit_t& other){
    const auto otherVal = other.multiplier == multiplier ? other : sakurajin::unit_system::base::unit_cast(other,multiplier);
    value += otherVal.value;
}

void sakurajin::unit_system::base::unit_t::operator-=(const sakurajin::unit_system::base::unit_t& other){
    const auto otherVal = other.multiplier == multiplier ? other : sakurajin::unit_system::base::unit_cast(other,multiplier);
    value -= otherVal.value;
}

void sakurajin::unit_system::base::unit_t::operator=(const sakurajin::unit_system::base::unit_t& other){
    const auto otherVal = other.multiplier == multiplier ? other : sakurajin::unit_system::base::unit_cast(other,multiplier);
    value = otherVal.value;
}
