#include <catch2/catch.hpp>

#include "prefix.hpp"
#include "test_helper.hpp"
#include "force.hpp"

#include <iostream>

using namespace sakurajin::unit_system::prefix;
using namespace sakurajin::unit_system::common;
using namespace sakurajin::unit_system::common::literals;
using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::base::literals;
using namespace sakurajin::unit_system;

TEST_CASE( "Checking if casting works", "[vector]" ) {
    
    const auto t1 = 10.0_s;
    const auto s1 = 250.0_m;
    const auto m1 = 1_kg;
    
    const speed v1 = s1/t1;
    REQUIRE(v1 == 25.0_mps);

    const auto p1 = v1*m1;
    REQUIRE(p1 == m1*v1);
    REQUIRE(p1 == 25_kgmps);
    
    const auto F1 = 10_kg * 1_G;
    REQUIRE(F1 == 98.1_N);
    
    REQUIRE(p1/10_s == 2.5_N);
    
};
