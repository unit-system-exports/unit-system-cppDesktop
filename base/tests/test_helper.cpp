#include "test_helper.hpp"
#include <cmath>

bool isDoubleEqual(double v1, double v2){
    double delta = v1-v2;
    return std::abs(delta) < 0.001 * std::max(std::abs(v1), std::abs(v1));
}

bool isUnit_tEqual(const sakurajin::unit_system::base::unit_t& v1, const sakurajin::unit_system::base::unit_t& v2){
    auto v3 = sakurajin::unit_system::base::unit_cast(v1,v2.multiplier);
    auto v4 = sakurajin::unit_system::base::unit_cast(v2,v1.multiplier);
    
    return isDoubleEqual(v2.value,v3.value) && isDoubleEqual(v4.value,v1.value);
}
