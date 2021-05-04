#include <catch2/catch.hpp>

#include "prefix.hpp"
#include "test_helper.hpp"
#include "speed.hpp"

#include <iostream>

using namespace sakurajin::unit_system::prefix;
using namespace sakurajin::unit_system::common;

TEST_CASE( "Checking if casting works", "[vector]" ) {
    
    const sakurajin::unit_system::base::time t1{1,1};
    const sakurajin::unit_system::base::length s1{10,1};
    
    const speed v1 = s1/t1;
    REQUIRE(isDoubleEqual(v1.value, 10.0));
    
};

