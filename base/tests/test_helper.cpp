#include "test_helper.hpp"
#include <cmath>
#include <algorithm>

bool isDoubleEqual(long double v1, long double v2){
    auto delta = v1-v2;
    return std::abs(delta) < 0.000001 * std::max(std::abs(v1), std::abs(v1));
}
