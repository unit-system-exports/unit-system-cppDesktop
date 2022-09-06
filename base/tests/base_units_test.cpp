#include <gtest/gtest.h>

#include "base.hpp"
#include "prefix.hpp"

#include <iostream>

using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::prefix;
using namespace sakurajin::unit_system::base::literals;
using namespace sakurajin::unit_system::base::constants;

TEST( base_units_tests, time_test ) {
    
    const auto t1 = 1_ms;
    EXPECT_TRUE( t1*1000 == 1.0_s);
    
};

TEST( base_units_tests, length_test ) {
    
    const auto s1 = 1_mm;
    EXPECT_TRUE( s1*1000 == 1.0_m);

};

TEST( base_units_tests, mass_test ) {
    
    const auto m1 = 1_g;
    EXPECT_TRUE( m1*1000 == 1.0_kg);

};

TEST( base_units_tests, electric_current_test ) {
    
    const auto I1 = 1_A;
    EXPECT_TRUE( I1*1000 == 1.0_kA);

};

TEST( base_units_tests, lum_intensity_test ) {
    
    const auto J1 = 1_cd;
    EXPECT_TRUE( J1*1000 == 1000.0_cd);

};

TEST( base_units_tests, temparature_test ) {
    
    const auto T1 = 20_C;
    EXPECT_TRUE( T1 == 293.15_K);

};

TEST( base_units_tests, amount_test ) {
    
    const auto five = 5.0_things;
    EXPECT_DOUBLE_EQ(static_cast<long double>(five), 5.0);
    
    const auto a1 = 2_mol;
    EXPECT_DOUBLE_EQ(static_cast<long double>(a1), 2.0*avogadro_constant);
    
};


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
