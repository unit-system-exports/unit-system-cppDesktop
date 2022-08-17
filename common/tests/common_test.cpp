#include <gtest/gtest.h>

#include "prefix.hpp"
#include "common.hpp"

#include <iostream>

using namespace sakurajin::unit_system::prefix;
using namespace sakurajin::unit_system::common;
using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::base::literals;
using namespace sakurajin::unit_system;

//base units
const auto t1 = 10.0_s;
const auto s1 = 250.0_m;
const auto s2 = 10.0_m;
const auto m1 = 1_kg;

//common units
const auto v1 = 25_mps;
const auto v2 = 1_mps;
const auto a1 = 2.5_mps2;
const auto p1 = 25_kgmps;
const auto F1 = 2.5_N;
const auto E1 = 25_J;
const auto P1 = 2.5_W;

TEST( common_tests, speed_test) {
    
    const time_si _t1{1,1};
    const auto _t2 = 10.0_h;

    const length _s1{s2};
    const auto _s2 = 250.0_km;
    
    const speed _v1 = _s1/_t1;
    EXPECT_TRUE(_v1 == 10.0_mps);
    
    const auto _v2 = _s2/_t2;
    EXPECT_TRUE(_v2 == 25.0_kmph);
    
    const auto _v3 = unit_cast(3.6_kmph,1);
    EXPECT_TRUE(_v3 == 1.0_mps);
    
    EXPECT_TRUE( _v3*_t1 == _t1*_v3 );
    
};

TEST( common_tests, acceleration_test ) {
    
    const auto _a1 = v1/t1;
    EXPECT_TRUE(_a1 == a1);
    
    const auto _a2 = unit_cast(9.81_mps/1.0_s,1);
    EXPECT_TRUE(_a2 == 1.0_G);
    
    EXPECT_TRUE(_a2 * t1 == t1 * _a2);
    
};

TEST( common_tests, momentum_test ) {

    const auto _p1 = v1*m1;
    EXPECT_TRUE(_p1 == m1*v1);
    EXPECT_TRUE(_p1 == p1);
    
};

TEST( common_tests, force_test ) {
    
    const auto _F2 = 10_kg * 1_G;
    EXPECT_TRUE(_F2 == 98.1_N);
    
    EXPECT_TRUE(p1/10_s == F1);
    EXPECT_TRUE(m1*a1 == F1);
    
};

TEST( common_tests, energy_test ) {
    
    const auto _E2 = 10_kg * 1_G * 1_m;
    EXPECT_TRUE(_E2 == 98.1_J);
    
    EXPECT_TRUE(F1*s2 == E1);
    EXPECT_TRUE(p1*v2 == E1);
    
};


TEST( common_tests, power_test ) {
    
    const auto _P2 = 10_kg * 1_G * 1_mps;
    EXPECT_TRUE(_P2 == 98.1_W);
    
    EXPECT_TRUE(F1*v2 == P1);
    EXPECT_TRUE(E1/t1 == P1);
    
};

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
