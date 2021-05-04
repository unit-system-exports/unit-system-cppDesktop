#include "unit_t.hpp"

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
    auto retval = sakurajin::unit_system::base::unit_cast(other,multiplier);
    retval.value += value;
    return retval;
}

sakurajin::unit_system::base::unit_t sakurajin::unit_system::base::unit_t::operator-(const sakurajin::unit_system::base::unit_t& other) const{
    auto retval = sakurajin::unit_system::base::unit_cast(other,multiplier);
    retval.value -= value;
    return retval;
}

//non const member functions
void sakurajin::unit_system::base::unit_t::operator*=(double scalar){
    value*=scalar;
}

void sakurajin::unit_system::base::unit_t::operator/=(double scalar){
    value/=scalar;
}

void sakurajin::unit_system::base::unit_t::operator+=(const sakurajin::unit_system::base::unit_t& other){
    auto otherVal = sakurajin::unit_system::base::unit_cast(other,multiplier);
    value += otherVal.value;
}

void sakurajin::unit_system::base::unit_t::operator-=(const sakurajin::unit_system::base::unit_t& other){
    auto otherVal = sakurajin::unit_system::base::unit_cast(other,multiplier);
    value -= otherVal.value;
}

void sakurajin::unit_system::base::unit_t::operator=(const sakurajin::unit_system::base::unit_t& other){
    auto otherVal = sakurajin::unit_system::base::unit_cast(other,multiplier);
    value = otherVal.value;
}
