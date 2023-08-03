#include "unit_system.hpp"

sakurajin::unit_system::energy::energy()
    : energy{0.0} {}
sakurajin::unit_system::energy::energy(long double v)
    : energy{v, 1, 0} {}
sakurajin::unit_system::energy::energy(long double v, long double mult)
    : energy{v, mult, 0} {}
sakurajin::unit_system::energy::energy(long double v, long double mult, long double off)
    : multiplier{mult},
      value{v},
      offset{off} {}

// const functions
sakurajin::unit_system::energy sakurajin::unit_system::energy::operator*(long double scalar) const {
    sakurajin::unit_system::energy retval{value * scalar, multiplier, offset};
    return retval;
}

sakurajin::unit_system::energy operator*(long double scalar, const sakurajin::unit_system::energy& val) {
    return {val.value * scalar, val.multiplier, val.offset};
}

long double sakurajin::unit_system::energy::operator/(const sakurajin::unit_system::energy& other) const {
    auto otherVal = unit_cast(other, multiplier, offset);
    return value / otherVal.value;
}

sakurajin::unit_system::energy sakurajin::unit_system::energy::operator/(long double scalar) const {
    sakurajin::unit_system::energy retval{value / scalar, multiplier, offset};
    return retval;
}

sakurajin::unit_system::energy sakurajin::unit_system::energy::operator+(const sakurajin::unit_system::energy& other) const {
    auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    retval.value += value;
    return retval;
}

sakurajin::unit_system::energy sakurajin::unit_system::energy::operator-(const sakurajin::unit_system::energy& other) const {
    auto retval  = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    retval.value = value - retval.value;
    return retval;
}

sakurajin::unit_system::energy sakurajin::unit_system::energy::operator-() const {
    return sakurajin::unit_system::energy{-value, multiplier, offset};
}

sakurajin::unit_system::energy::operator long double() const {
    auto retval = sakurajin::unit_system::unit_cast(*this, 1, 0);
    return retval.value;
}

sakurajin::unit_system::energy sakurajin::unit_system::energy::convert_multiplier(long double new_multiplier) const {
    return convert_copy(new_multiplier, offset);
}

sakurajin::unit_system::energy sakurajin::unit_system::energy::convert_offset(long double new_offset) const {
    return convert_copy(multiplier, new_offset);
}

sakurajin::unit_system::energy sakurajin::unit_system::energy::convert_copy(long double new_multiplier, long double new_offset) const {
    auto                           valBase0 = value * multiplier + offset;
    sakurajin::unit_system::energy retval{valBase0 / new_multiplier - new_offset, new_multiplier, new_offset};
    return retval;
}

// comparison operators
#if __cplusplus >= 202002L
int sakurajin::unit_system::energy::operator<=>(const sakurajin::unit_system::energy& other) const {
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
bool sakurajin::unit_system::energy::operator<(const sakurajin::unit_system::energy& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value < retval.value;
}

bool sakurajin::unit_system::energy::operator>(const sakurajin::unit_system::energy& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value > retval.value;
}

bool sakurajin::unit_system::energy::operator<=(const sakurajin::unit_system::energy& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value <= retval.value;
}

bool sakurajin::unit_system::energy::operator>=(const sakurajin::unit_system::energy& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value >= retval.value;
}

bool sakurajin::unit_system::energy::operator==(const sakurajin::unit_system::energy& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value == retval.value;
}

bool sakurajin::unit_system::energy::operator!=(const sakurajin::unit_system::energy& other) const {
    return !(*this == other);
}
#endif

// non const member functions
void sakurajin::unit_system::energy::operator*=(long double scalar) {
    value *= scalar;
}

void sakurajin::unit_system::energy::operator/=(long double scalar) {
    value /= scalar;
}

void sakurajin::unit_system::energy::operator+=(const sakurajin::unit_system::energy& other) {
    const auto otherVal = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    value += otherVal.value;
}

void sakurajin::unit_system::energy::operator-=(const sakurajin::unit_system::energy& other) {
    const auto otherVal = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    value -= otherVal.value;
}

void sakurajin::unit_system::energy::operator=(const sakurajin::unit_system::energy& other) {
    const auto otherVal = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    value               = otherVal.value;
}


sakurajin::unit_system::length sakurajin::unit_system::energy::operator/(const sakurajin::unit_system::force& other) const {
    sakurajin::unit_system::energy _v1 = convert_offset(0);
    sakurajin::unit_system::force  _v2 = other.convert_offset(0);
    return sakurajin::unit_system::length{_v1.value / _v2.value, _v1.multiplier / _v2.multiplier};
}

sakurajin::unit_system::force sakurajin::unit_system::energy::operator/(const sakurajin::unit_system::length& other) const {
    sakurajin::unit_system::energy _v1 = convert_offset(0);
    sakurajin::unit_system::length _v2 = other.convert_offset(0);
    return sakurajin::unit_system::force{_v1.value / _v2.value, _v1.multiplier / _v2.multiplier};
}

sakurajin::unit_system::time_si sakurajin::unit_system::energy::operator/(const sakurajin::unit_system::power& other) const {
    sakurajin::unit_system::energy _v1 = convert_offset(0);
    sakurajin::unit_system::power  _v2 = other.convert_offset(0);
    return sakurajin::unit_system::time_si{_v1.value / _v2.value, _v1.multiplier / _v2.multiplier};
}

sakurajin::unit_system::power sakurajin::unit_system::energy::operator/(const sakurajin::unit_system::time_si& other) const {
    sakurajin::unit_system::energy  _v1 = convert_offset(0);
    sakurajin::unit_system::time_si _v2 = other.convert_offset(0);
    return sakurajin::unit_system::power{_v1.value / _v2.value, _v1.multiplier / _v2.multiplier};
}

sakurajin::unit_system::speed sakurajin::unit_system::energy::operator/(const sakurajin::unit_system::momentum& other) const {
    sakurajin::unit_system::energy   _v1 = convert_offset(0);
    sakurajin::unit_system::momentum _v2 = other.convert_offset(0);
    return sakurajin::unit_system::speed{_v1.value / _v2.value, _v1.multiplier / _v2.multiplier};
}

sakurajin::unit_system::momentum sakurajin::unit_system::energy::operator/(const sakurajin::unit_system::speed& other) const {
    sakurajin::unit_system::energy _v1 = convert_offset(0);
    sakurajin::unit_system::speed  _v2 = other.convert_offset(0);
    return sakurajin::unit_system::momentum{_v1.value / _v2.value, _v1.multiplier / _v2.multiplier};
}


// external functions


std::ostream& sakurajin::unit_system::operator<<(std::ostream& os, const sakurajin::unit_system::energy& t) {
    auto t1 = sakurajin::unit_system::unit_cast(t, 1);
    return os << t1.value << " Joules";
}

sakurajin::unit_system::energy
sakurajin::unit_system::unit_cast(const sakurajin::unit_system::energy& unit, long double new_multiplier, long double new_offset) {
    return unit.convert_copy(new_multiplier, new_offset);
}

sakurajin::unit_system::energy sakurajin::unit_system::clamp(const sakurajin::unit_system::energy& unit,
                                                             const sakurajin::unit_system::energy& lower,
                                                             const sakurajin::unit_system::energy& upper) {
    auto _lower = unit_cast(lower, unit.multiplier, unit.offset);
    auto _upper = unit_cast(upper, unit.multiplier, unit.offset);

    auto val = unit.value > _lower.value ? (unit.value < _upper.value ? unit.value : _upper.value) : _lower.value;
    return sakurajin::unit_system::energy{val, unit.multiplier, unit.offset};
}

sakurajin::unit_system::energy std::abs(const sakurajin::unit_system::energy& unit) {
    auto inv = -unit;
    return unit > inv ? unit : inv;
}

// literals


sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _J(long double len) {
    return sakurajin::unit_system::energy{len, 1.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _J(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _Nm(long double len) {
    return sakurajin::unit_system::energy{len, 1.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _Nm(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _eV(long double len) {
    return sakurajin::unit_system::energy{len, 1.602176634e-19, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _eV(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1.602176634e-19, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _Wh(long double len) {
    return sakurajin::unit_system::energy{len, 3600.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _Wh(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 3600.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _Ws(long double len) {
    return sakurajin::unit_system::energy{len, 1.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _Ws(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _PJ(long double len) {
    return sakurajin::unit_system::energy{len, 1000000000000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _PJ(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1000000000000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _TJ(long double len) {
    return sakurajin::unit_system::energy{len, 1000000000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _TJ(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1000000000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _GJ(long double len) {
    return sakurajin::unit_system::energy{len, 1000000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _GJ(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1000000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _MJ(long double len) {
    return sakurajin::unit_system::energy{len, 1000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _MJ(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _kJ(long double len) {
    return sakurajin::unit_system::energy{len, 1000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _kJ(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _mJ(long double len) {
    return sakurajin::unit_system::energy{len, 0.001, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _mJ(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 0.001, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _uJ(long double len) {
    return sakurajin::unit_system::energy{len, 1e-06, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _uJ(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1e-06, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _nJ(long double len) {
    return sakurajin::unit_system::energy{len, 1e-09, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _nJ(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1e-09, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _pJ(long double len) {
    return sakurajin::unit_system::energy{len, 1e-12, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _pJ(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1e-12, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _fJ(long double len) {
    return sakurajin::unit_system::energy{len, 1e-15, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _fJ(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1e-15, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _aJ(long double len) {
    return sakurajin::unit_system::energy{len, 1e-18, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _aJ(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1e-18, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _GNm(long double len) {
    return sakurajin::unit_system::energy{len, 1000000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _GNm(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1000000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _MNm(long double len) {
    return sakurajin::unit_system::energy{len, 1000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _MNm(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _kNm(long double len) {
    return sakurajin::unit_system::energy{len, 1000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _kNm(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _mNm(long double len) {
    return sakurajin::unit_system::energy{len, 0.001, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _mNm(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 0.001, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _uNm(long double len) {
    return sakurajin::unit_system::energy{len, 1e-06, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _uNm(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1e-06, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _PeV(long double len) {
    return sakurajin::unit_system::energy{len, 0.0001602176634, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _PeV(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 0.0001602176634, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _TeV(long double len) {
    return sakurajin::unit_system::energy{len, 1.602176634e-07, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _TeV(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1.602176634e-07, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _GeV(long double len) {
    return sakurajin::unit_system::energy{len, 1.6021766339999998e-10, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _GeV(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1.6021766339999998e-10, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _MeV(long double len) {
    return sakurajin::unit_system::energy{len, 1.6021766339999998e-13, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _MeV(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1.6021766339999998e-13, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _keV(long double len) {
    return sakurajin::unit_system::energy{len, 1.602176634e-16, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _keV(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1.602176634e-16, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _meV(long double len) {
    return sakurajin::unit_system::energy{len, 1.6021766339999998e-22, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _meV(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1.6021766339999998e-22, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _ueV(long double len) {
    return sakurajin::unit_system::energy{len, 1.602176634e-25, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _ueV(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 1.602176634e-25, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _PWh(long double len) {
    return sakurajin::unit_system::energy{len, 3.6e+18, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _PWh(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 3.6e+18, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _TWh(long double len) {
    return sakurajin::unit_system::energy{len, 3600000000000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _TWh(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 3600000000000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _GWh(long double len) {
    return sakurajin::unit_system::energy{len, 3600000000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _GWh(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 3600000000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _MWh(long double len) {
    return sakurajin::unit_system::energy{len, 3600000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _MWh(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 3600000000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _kWh(long double len) {
    return sakurajin::unit_system::energy{len, 3600000.0, 0.0};
}

sakurajin::unit_system::energy sakurajin::unit_system::literals::operator"" _kWh(unsigned long long int len) {
    return sakurajin::unit_system::energy{static_cast<long double>(len), 3600000.0, 0.0};
}
