#include <catch2/catch.hpp>

#include "unit_t.hpp"
#include "test_helper.hpp"
#include "prefix.hpp"

#include <iostream>

using namespace sakurajin::unit_system;
using namespace sakurajin::unit_system::prefix;

TEST_CASE( "Checking if casting works", "[vector]" ) {
    
    const unit_t<0> v1{1000,1};
    const unit_t<0> v2{1,1000};
    const unit_t<0> v3{10,100};
    const unit_t<0> v4{1,1};
    const unit_t<0> v5{1,kilo};
    const unit_t<0> v6{-1,kilo};
    
    
    REQUIRE(v1 == v2);
    REQUIRE(v1 == v3);
    REQUIRE(v2 == v3);
    REQUIRE(v2 == v5);
    
    REQUIRE(v1 != v4);
    
    REQUIRE(abs(v5) == abs(v6));
    
};

TEST_CASE( "Checking if comparison works", "[vector]" ) {
    
    const unit_t<0> v1{1000,1};
    const unit_t<0> v2{1,1000};
    const unit_t<0> v3{10,100};
    const unit_t<0> v4{1,1};
    const unit_t<0> v5{1,kilo};
    
    REQUIRE(v4 < v5);
    REQUIRE(v5 > v4);
    REQUIRE(v4 <= v5);
    REQUIRE(v5 >= v4);
    
    REQUIRE(v1 <= v1);
    REQUIRE(v1 >= v1);
    
    #if __cplusplus >= 202002L
    REQUIRE( (v4 <=> v5) < 0)
    REQUIRE( (v5 <=> v4) > 0)
    REQUIRE( (v1 <=> v1) == 0)
    #endif
    
};

TEST_CASE( "Checking if operators works", "[vector]" ) {
    
    const unit_t<0> v1{1000,1};
    const unit_t<0> v2{1,1000};
    const unit_t<0> v3{10,100};
    const unit_t<0> v4{1,1};
    const unit_t<0> v5{999,1};
    
    auto _v4 = v4;
    REQUIRE(v2 != _v4);
    _v4 = v2;
    REQUIRE(v2 == _v4);
    
    auto v6 = v1 + v2;
    REQUIRE(isDoubleEqual(v6.value, 2000.0));
    REQUIRE(v6 == v1*2.0);
    REQUIRE(v1 == v6/2.0);
    
    auto v7 = v2 + v1;
    REQUIRE(isDoubleEqual(v7.value, 2.0));
    REQUIRE(v6 == v7);
    
    auto v8 = v1-v4;
    REQUIRE(v5 == v8);
    
};

