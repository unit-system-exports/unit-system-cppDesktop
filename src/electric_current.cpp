#include "unit_system.hpp"

sakurajin::unit_system::electric_current::electric_current()
    : electric_current{0.0} {}
sakurajin::unit_system::electric_current::electric_current(long double v)
    : electric_current{v, 1, 0} {}
sakurajin::unit_system::electric_current::electric_current(long double v, long double mult)
    : electric_current{v, mult, 0} {}
sakurajin::unit_system::electric_current::electric_current(long double v, long double mult, long double off)
    : multiplier{mult},
      value{v},
      offset{off} {}

// const functions
sakurajin::unit_system::electric_current sakurajin::unit_system::electric_current::operator*(long double scalar) const {
    sakurajin::unit_system::electric_current retval{value * scalar, multiplier, offset};
    return retval;
}

sakurajin::unit_system::electric_current operator*(long double scalar, const sakurajin::unit_system::electric_current& val) {
    return {val.value * scalar, val.multiplier, val.offset};
}

long double sakurajin::unit_system::electric_current::operator/(const sakurajin::unit_system::electric_current& other) const {
    auto otherVal = unit_cast(other, multiplier, offset);
    return value / otherVal.value;
}

sakurajin::unit_system::electric_current sakurajin::unit_system::electric_current::operator/(long double scalar) const {
    sakurajin::unit_system::electric_current retval{value / scalar, multiplier, offset};
    return retval;
}

sakurajin::unit_system::electric_current
sakurajin::unit_system::electric_current::operator+(const sakurajin::unit_system::electric_current& other) const {
    auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    retval.value += value;
    return retval;
}

sakurajin::unit_system::electric_current
sakurajin::unit_system::electric_current::operator-(const sakurajin::unit_system::electric_current& other) const {
    auto retval  = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    retval.value = value - retval.value;
    return retval;
}

sakurajin::unit_system::electric_current sakurajin::unit_system::electric_current::operator-() const {
    return sakurajin::unit_system::electric_current{-value, multiplier, offset};
}

sakurajin::unit_system::electric_current::operator long double() const {
    auto retval = sakurajin::unit_system::unit_cast(*this, 1, 0);
    return retval.value;
}

sakurajin::unit_system::electric_current sakurajin::unit_system::electric_current::convert_multiplier(long double new_multiplier) const {
    return convert_copy(new_multiplier, offset);
}

sakurajin::unit_system::electric_current sakurajin::unit_system::electric_current::convert_offset(long double new_offset) const {
    return convert_copy(multiplier, new_offset);
}

sakurajin::unit_system::electric_current sakurajin::unit_system::electric_current::convert_copy(long double new_multiplier,
                                                                                                long double new_offset) const {
    auto                                     valBase0 = value * multiplier + offset;
    sakurajin::unit_system::electric_current retval{valBase0 / new_multiplier - new_offset, new_multiplier, new_offset};
    return retval;
}

// comparison operators
#if __cplusplus >= 202002L
int sakurajin::unit_system::electric_current::operator<=>(const sakurajin::unit_system::electric_current& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    if (*this < retval) {
        return -1;
    }

    if (*this > retval) {
        return 1;
    }

    return 0;
}
#else
bool sakurajin::unit_system::electric_current::operator<(const sakurajin::unit_system::electric_current& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value < retval.value;
}

bool sakurajin::unit_system::electric_current::operator>(const sakurajin::unit_system::electric_current& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value > retval.value;
}

bool sakurajin::unit_system::electric_current::operator<=(const sakurajin::unit_system::electric_current& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value <= retval.value;
}

bool sakurajin::unit_system::electric_current::operator>=(const sakurajin::unit_system::electric_current& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value >= retval.value;
}

bool sakurajin::unit_system::electric_current::operator==(const sakurajin::unit_system::electric_current& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value == retval.value;
}

bool sakurajin::unit_system::electric_current::operator!=(const sakurajin::unit_system::electric_current& other) const {
    return !(*this == other);
}
#endif

// non const member functions
void sakurajin::unit_system::electric_current::operator*=(long double scalar) {
    value *= scalar;
}

void sakurajin::unit_system::electric_current::operator/=(long double scalar) {
    value /= scalar;
}

void sakurajin::unit_system::electric_current::operator+=(const sakurajin::unit_system::electric_current& other) {
    const auto otherVal = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    value += otherVal.value;
}

void sakurajin::unit_system::electric_current::operator-=(const sakurajin::unit_system::electric_current& other) {
    const auto otherVal = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    value -= otherVal.value;
}

void sakurajin::unit_system::electric_current::operator=(const sakurajin::unit_system::electric_current& other) {
    const auto otherVal = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    value               = otherVal.value;
}


// external functions


std::ostream& sakurajin::unit_system::operator<<(std::ostream& os, const sakurajin::unit_system::electric_current& t) {
    auto t1 = sakurajin::unit_system::unit_cast(t, 1);
    return os << t1.value << " Ampere";
}

sakurajin::unit_system::electric_current sakurajin::unit_system::unit_cast(const sakurajin::unit_system::electric_current& unit,
                                                                           long double                                     new_multiplier,
                                                                           long double                                     new_offset) {
    return unit.convert_copy(new_multiplier, new_offset);
}

sakurajin::unit_system::electric_current sakurajin::unit_system::clamp(const sakurajin::unit_system::electric_current& unit,
                                                                       const sakurajin::unit_system::electric_current& lower,
                                                                       const sakurajin::unit_system::electric_current& upper) {
    auto _lower = unit_cast(lower, unit.multiplier, unit.offset);
    auto _upper = unit_cast(upper, unit.multiplier, unit.offset);

    auto val = unit.value > _lower.value ? (unit.value < _upper.value ? unit.value : _upper.value) : _lower.value;
    return sakurajin::unit_system::electric_current{val, unit.multiplier, unit.offset};
}

sakurajin::unit_system::electric_current std::abs(const sakurajin::unit_system::electric_current& unit) {
    auto inv = -unit;
    return unit > inv ? unit : inv;
}

// literals


sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _A(long double len) {
    return sakurajin::unit_system::electric_current{len, 1.0, 0.0};
}

sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _A(unsigned long long int len) {
    return sakurajin::unit_system::electric_current{static_cast<long double>(len), 1.0, 0.0};
}


sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _PA(long double len) {
    return sakurajin::unit_system::electric_current{len, 1000000000000000.0, 0.0};
}

sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _PA(unsigned long long int len) {
    return sakurajin::unit_system::electric_current{static_cast<long double>(len), 1000000000000000.0, 0.0};
}


sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _TA(long double len) {
    return sakurajin::unit_system::electric_current{len, 1000000000000.0, 0.0};
}

sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _TA(unsigned long long int len) {
    return sakurajin::unit_system::electric_current{static_cast<long double>(len), 1000000000000.0, 0.0};
}


sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _GA(long double len) {
    return sakurajin::unit_system::electric_current{len, 1000000000.0, 0.0};
}

sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _GA(unsigned long long int len) {
    return sakurajin::unit_system::electric_current{static_cast<long double>(len), 1000000000.0, 0.0};
}


sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _MA(long double len) {
    return sakurajin::unit_system::electric_current{len, 1000000.0, 0.0};
}

sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _MA(unsigned long long int len) {
    return sakurajin::unit_system::electric_current{static_cast<long double>(len), 1000000.0, 0.0};
}


sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _kA(long double len) {
    return sakurajin::unit_system::electric_current{len, 1000.0, 0.0};
}

sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _kA(unsigned long long int len) {
    return sakurajin::unit_system::electric_current{static_cast<long double>(len), 1000.0, 0.0};
}


sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _mA(long double len) {
    return sakurajin::unit_system::electric_current{len, 0.001, 0.0};
}

sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _mA(unsigned long long int len) {
    return sakurajin::unit_system::electric_current{static_cast<long double>(len), 0.001, 0.0};
}


sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _uA(long double len) {
    return sakurajin::unit_system::electric_current{len, 1e-06, 0.0};
}

sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _uA(unsigned long long int len) {
    return sakurajin::unit_system::electric_current{static_cast<long double>(len), 1e-06, 0.0};
}


sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _nA(long double len) {
    return sakurajin::unit_system::electric_current{len, 1e-09, 0.0};
}

sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _nA(unsigned long long int len) {
    return sakurajin::unit_system::electric_current{static_cast<long double>(len), 1e-09, 0.0};
}


sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _pA(long double len) {
    return sakurajin::unit_system::electric_current{len, 1e-12, 0.0};
}

sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _pA(unsigned long long int len) {
    return sakurajin::unit_system::electric_current{static_cast<long double>(len), 1e-12, 0.0};
}


sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _fA(long double len) {
    return sakurajin::unit_system::electric_current{len, 1e-15, 0.0};
}

sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _fA(unsigned long long int len) {
    return sakurajin::unit_system::electric_current{static_cast<long double>(len), 1e-15, 0.0};
}


sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _aA(long double len) {
    return sakurajin::unit_system::electric_current{len, 1e-18, 0.0};
}

sakurajin::unit_system::electric_current sakurajin::unit_system::literals::operator"" _aA(unsigned long long int len) {
    return sakurajin::unit_system::electric_current{static_cast<long double>(len), 1e-18, 0.0};
}
