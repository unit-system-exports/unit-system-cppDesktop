#include <catch2/catch.hpp>

#include "test_helper.hpp"
#include "base.hpp"

#include <iostream>

using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::prefix;
using namespace sakurajin::unit_system::base::literals;

TEST_CASE( "Checking if time works", "[vector]" ) {
    
    const auto t1 = 1_ms;
    REQUIRE( t1*1000 == 1.0_s);
    
};

TEST_CASE( "Checking if length works", "[vector]" ) {
    
    const auto s1 = 1_mm;
    REQUIRE( s1*1000 == 1.0_m);

};

TEST_CASE( "Checking if mass works", "[vector]" ) {
    
    const auto m1 = 1_g;
    REQUIRE( m1*1000 == 1.0_kg);

};

TEST_CASE( "Checking if amount works", "[vector]" ) {
    
    const auto five = 5.0_things;
    REQUIRE( isDoubleEqual(static_cast<long double>(five), 5.0));
    
    const auto a1 = 2_mol;
    REQUIRE( isDoubleEqual(static_cast<long double>(a1), 2.0*avogadro_constant) );
    
};


