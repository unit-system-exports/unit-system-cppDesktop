#include "cmath"
#include "unit_system.hpp"

sakurajin::unit_system::area::area()
    : area{0.0} {}
sakurajin::unit_system::area::area(long double v)
    : area{v, 1, 0} {}
sakurajin::unit_system::area::area(long double v, long double mult)
    : area{v, mult, 0} {}
sakurajin::unit_system::area::area(long double v, long double mult, long double off)
    : multiplier{mult},
      value{v},
      offset{off} {}

// const functions
sakurajin::unit_system::area sakurajin::unit_system::area::operator*(long double scalar) const {
    return sakurajin::unit_system::area{value * scalar, multiplier, offset};
}

sakurajin::unit_system::area operator*(long double scalar, const sakurajin::unit_system::area& val) {
    return sakurajin::unit_system::area{val.value * scalar, val.multiplier, val.offset};
}

long double sakurajin::unit_system::area::operator/(const sakurajin::unit_system::area& other) const {
    return value / other.convert_like(*this).value;
}

sakurajin::unit_system::area sakurajin::unit_system::area::operator/(long double scalar) const {
    return sakurajin::unit_system::area{value / scalar, multiplier, offset};
}

sakurajin::unit_system::area sakurajin::unit_system::area::operator+(const sakurajin::unit_system::area& other) const {
    auto retval = convert_like(other);
    retval.value += other.value;
    return retval;
}

sakurajin::unit_system::area sakurajin::unit_system::area::operator-(const sakurajin::unit_system::area& other) const {
    auto retval = convert_like(other);
    retval.value -= other.value;
    return retval;
}

sakurajin::unit_system::area sakurajin::unit_system::area::operator-() const {
    return sakurajin::unit_system::area{-value, multiplier, offset};
}

sakurajin::unit_system::area::operator long double() const {
    return convert_copy(1, 0).value;
}

sakurajin::unit_system::area sakurajin::unit_system::area::convert_multiplier(long double new_multiplier) const {
    return convert_copy(new_multiplier, offset);
}

sakurajin::unit_system::area sakurajin::unit_system::area::convert_offset(long double new_offset) const {
    return convert_copy(multiplier, new_offset);
}

sakurajin::unit_system::area sakurajin::unit_system::area::convert_copy(long double new_multiplier, long double new_offset) const {
    auto                         valBase0 = value * multiplier + offset;
    sakurajin::unit_system::area retval{valBase0 / new_multiplier - new_offset, new_multiplier, new_offset};
    return retval;
}

sakurajin::unit_system::area sakurajin::unit_system::area::convert_like(const sakurajin::unit_system::area& other) const {
    return convert_copy(other.multiplier, other.offset);
}

// comparison operators
#if __cplusplus >= 202002L
int sakurajin::unit_system::area::operator<=>(const sakurajin::unit_system::area& other) const {
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
bool sakurajin::unit_system::area::operator<(const sakurajin::unit_system::area& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value < retval.value;
}

bool sakurajin::unit_system::area::operator>(const sakurajin::unit_system::area& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value > retval.value;
}

bool sakurajin::unit_system::area::operator<=(const sakurajin::unit_system::area& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value <= retval.value;
}

bool sakurajin::unit_system::area::operator>=(const sakurajin::unit_system::area& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value >= retval.value;
}

bool sakurajin::unit_system::area::operator==(const sakurajin::unit_system::area& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value == retval.value;
}

bool sakurajin::unit_system::area::operator!=(const sakurajin::unit_system::area& other) const {
    return !(*this == other);
}
#endif

// non const member functions
void sakurajin::unit_system::area::operator*=(long double scalar) {
    value *= scalar;
}

void sakurajin::unit_system::area::operator/=(long double scalar) {
    value /= scalar;
}

void sakurajin::unit_system::area::operator+=(const sakurajin::unit_system::area& other) {
    const auto otherVal = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    value += otherVal.value;
}

void sakurajin::unit_system::area::operator-=(const sakurajin::unit_system::area& other) {
    const auto otherVal = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    value -= otherVal.value;
}

void sakurajin::unit_system::area::operator=(const sakurajin::unit_system::area& other) {
    const auto otherVal = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    value               = otherVal.value;
}


sakurajin::unit_system::length sakurajin::unit_system::area::operator/(const sakurajin::unit_system::length& other) const {
    sakurajin::unit_system::area   _v1 = convert_offset(0);
    sakurajin::unit_system::length _v2 = other.convert_offset(0);
    return sakurajin::unit_system::length{_v1.value / _v2.value, _v1.multiplier / _v2.multiplier};
}


sakurajin::unit_system::length sakurajin::unit_system::area::sqrt() const {
    return sakurajin::unit_system::length{std::sqrt(value), std::sqrt(multiplier), offset};
}


// external functions

sakurajin::unit_system::area sakurajin::unit_system::operator*(long double scalar, const sakurajin::unit_system::area& value) {
    return value * scalar;
}


sakurajin::unit_system::length sakurajin::unit_system::sqrt(const area& unit) {
    return unit.sqrt();
}


sakurajin::unit_system::area
sakurajin::unit_system::unit_cast(const sakurajin::unit_system::area& unit, long double new_multiplier, long double new_offset) {
    return unit.convert_copy(new_multiplier, new_offset);
}

sakurajin::unit_system::area sakurajin::unit_system::clamp(const sakurajin::unit_system::area& unit,
                                                           const sakurajin::unit_system::area& lower,
                                                           const sakurajin::unit_system::area& upper) {
    auto _lower = unit_cast(lower, unit.multiplier, unit.offset);
    auto _upper = unit_cast(upper, unit.multiplier, unit.offset);

    auto val = unit.value > _lower.value ? (unit.value < _upper.value ? unit.value : _upper.value) : _lower.value;
    return sakurajin::unit_system::area{val, unit.multiplier, unit.offset};
}


sakurajin::unit_system::area std::abs(const sakurajin::unit_system::area& unit) {
    auto inv = -unit;
    return unit > inv ? unit : inv;
}

std::ostream& sakurajin::unit_system::operator<<(std::ostream& os, const sakurajin::unit_system::area& t) {
    auto t1 = sakurajin::unit_system::unit_cast(t, 1);
    return os << t1.value << " metre^2";
}


// literals


sakurajin::unit_system::area sakurajin::unit_system::literals::operator"" _m2(long double len) {
    return sakurajin::unit_system::area{len, 1.0, 0.0};
}

sakurajin::unit_system::area sakurajin::unit_system::literals::operator"" _m2(unsigned long long int len) {
    return sakurajin::unit_system::area{static_cast<long double>(len), 1.0, 0.0};
}

sakurajin::unit_system::area sakurajin::unit_system::literals::operator"" _are(long double len) {
    return sakurajin::unit_system::area{len, 100.0, 0.0};
}

sakurajin::unit_system::area sakurajin::unit_system::literals::operator"" _are(unsigned long long int len) {
    return sakurajin::unit_system::area{static_cast<long double>(len), 100.0, 0.0};
}

sakurajin::unit_system::area sakurajin::unit_system::literals::operator"" _hectare(long double len) {
    return sakurajin::unit_system::area{len, 10000.0, 0.0};
}

sakurajin::unit_system::area sakurajin::unit_system::literals::operator"" _hectare(unsigned long long int len) {
    return sakurajin::unit_system::area{static_cast<long double>(len), 10000.0, 0.0};
}

sakurajin::unit_system::area sakurajin::unit_system::literals::operator"" _km2(long double len) {
    return sakurajin::unit_system::area{len, 1000000.0, 0.0};
}

sakurajin::unit_system::area sakurajin::unit_system::literals::operator"" _km2(unsigned long long int len) {
    return sakurajin::unit_system::area{static_cast<long double>(len), 1000000.0, 0.0};
}

sakurajin::unit_system::area sakurajin::unit_system::literals::operator"" _mm2(long double len) {
    return sakurajin::unit_system::area{len, 1e-06, 0.0};
}

sakurajin::unit_system::area sakurajin::unit_system::literals::operator"" _mm2(unsigned long long int len) {
    return sakurajin::unit_system::area{static_cast<long double>(len), 1e-06, 0.0};
}

sakurajin::unit_system::area sakurajin::unit_system::literals::operator"" _um2(long double len) {
    return sakurajin::unit_system::area{len, 1e-12, 0.0};
}

sakurajin::unit_system::area sakurajin::unit_system::literals::operator"" _um2(unsigned long long int len) {
    return sakurajin::unit_system::area{static_cast<long double>(len), 1e-12, 0.0};
}

sakurajin::unit_system::area sakurajin::unit_system::literals::operator"" _nm2(long double len) {
    return sakurajin::unit_system::area{len, 1e-18, 0.0};
}

sakurajin::unit_system::area sakurajin::unit_system::literals::operator"" _nm2(unsigned long long int len) {
    return sakurajin::unit_system::area{static_cast<long double>(len), 1e-18, 0.0};
}
