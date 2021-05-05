#include <catch2/catch.hpp>

#include "prefix.hpp"
#include "test_helper.hpp"
#include "acceleration.hpp"

#include <iostream>

using namespace sakurajin::unit_system::prefix;
using namespace sakurajin::unit_system::common;
using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::base::literals;

TEST_CASE( "Checking if casting works", "[vector]" ) {
    
    const auto t1 = 10.0_s;
    const auto s1 = 250.0_m;
    
    const speed v1 = s1/t1;
    REQUIRE(v1 == 25.0_mps);
    
    const auto a1 = v1/t1;
    REQUIRE(a1 == 2.5_mps2);
    
    const auto a2 = unit_cast(9.81_mps/1.0_s,1);
    REQUIRE(a2 == 1.0_g);
    
    REQUIRE(a2 * t1 == t1 * a2);
    
};

