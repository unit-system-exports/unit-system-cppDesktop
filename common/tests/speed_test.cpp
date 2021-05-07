#include <catch2/catch.hpp>

#include "prefix.hpp"
#include "test_helper.hpp"
#include "speed.hpp"

#include <iostream>

using namespace sakurajin::unit_system::prefix;
using namespace sakurajin::unit_system::common;
using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::base::literals;
using namespace sakurajin::unit_system;

TEST_CASE( "Checking if casting works", "[vector]" ) {
    
    const time_si t1{1,1};
    const auto t2 = 10.0_h;

    const length s1{10,1};
    const auto s2 = 250.0_km;
    
    const speed v1 = s1/t1;
    REQUIRE(v1 == 10.0_mps);
    
    const auto v2 = s2/t2;
    REQUIRE(v2 == 25.0_kmph);
    
    const auto v3 = unit_cast(3.6_kmph,1);
    REQUIRE(v3 == 1.0_mps);
    
    REQUIRE( v3*t1 == t1*v3 );
    
};
