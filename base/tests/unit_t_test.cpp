#include <catch2/catch.hpp>

#include "unit_t.hpp"
#include "test_helper.hpp"
#include "prefix.hpp"

using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::prefix;

TEST_CASE( "Checking if casting works", "[vector]" ) {
    
    unit_t v1{1000,1};
    unit_t v2{1,1000};
    unit_t v3{10,100};
    unit_t v4{1,1};
    unit_t v5{1,kilo};
    
    REQUIRE(isUnit_tEqual(v1,v2));
    REQUIRE(isUnit_tEqual(v1,v3));
    REQUIRE(isUnit_tEqual(v2,v3));
    REQUIRE(isUnit_tEqual(v2,v5));
    
    REQUIRE(!isUnit_tEqual(v1,v4));
    
};

