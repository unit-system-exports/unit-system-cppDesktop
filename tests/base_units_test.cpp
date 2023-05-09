#include "test_functions.hpp"

#include <iostream>

using namespace sakurajin::unit_system;
using namespace sakurajin::unit_system::literals;
using namespace sakurajin::unit_system::constants;

TEST( base_units_tests, time_test ) {
    
    const auto t1 = 1_ms;
    EXPECT_UNIT_EQ(t1*1000, 1.0_s);
}

TEST( base_units_tests, length_test ) {
    
    const auto s1 = 1_mm;
    EXPECT_UNIT_EQ( s1*1000, 1.0_m);

}

TEST( base_units_tests, mass_test ) {
    
    const auto m1 = 1_g;
    EXPECT_UNIT_EQ( m1*1000, 1.0_kg);

}

TEST( base_units_tests, electric_current_test ) {
    
    const auto I1 = 1_A;
    EXPECT_UNIT_EQ( I1*1000, 1.0_kA);

}

TEST( base_units_tests, lum_intensity_test ) {
    
    const auto J1 = 1_cd;
    EXPECT_UNIT_EQ( J1*1000, 1000.0_cd);

}

TEST( base_units_tests, temparature_test ) {
    
    const auto T1 = 20.0_C;
    EXPECT_UNIT_EQ( 293.15_K, T1);

}

TEST( base_units_tests, amount_test ) {
    
    const auto five = 5.0_things;
    EXPECT_DOUBLE_EQ(static_cast<long double>(five), (5.0));
    
    const auto a1 = 2_mol;
    EXPECT_DOUBLE_EQ(static_cast<long double>(a1), 2.0*avogadro_constant);
    
}


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
