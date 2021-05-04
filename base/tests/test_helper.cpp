#include "test_helper.hpp"
#include <cmath>
#include <algorithm>

bool isDoubleEqual(double v1, double v2){
    double delta = v1-v2;
    return std::abs(delta) < 0.000001 * std::max(std::abs(v1), std::abs(v1));
}
