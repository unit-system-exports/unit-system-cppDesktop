#include <catch2/catch.hpp>

#include "prefix.hpp"
#include "test_helper.hpp"
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

TEST_CASE( "Checking if speed works", "[vector]" ) {
    
    const time_si _t1{1,1};
    const auto _t2 = 10.0_h;

    const length _s1{s2};
    const auto _s2 = 250.0_km;
    
    const speed _v1 = _s1/_t1;
    REQUIRE(_v1 == 10.0_mps);
    
    const auto _v2 = _s2/_t2;
    REQUIRE(_v2 == 25.0_kmph);
    
    const auto _v3 = unit_cast(3.6_kmph,1);
    REQUIRE(_v3 == 1.0_mps);
    
    REQUIRE( _v3*_t1 == _t1*_v3 );
    
};

TEST_CASE( "Checking if acceleration works", "[vector]" ) {
    
    const auto _a1 = v1/t1;
    REQUIRE(_a1 == a1);
    
    const auto _a2 = unit_cast(9.81_mps/1.0_s,1);
    REQUIRE(_a2 == 1.0_G);
    
    REQUIRE(_a2 * t1 == t1 * _a2);
    
};

TEST_CASE( "Checking if momentum works", "[vector]" ) {

    const auto _p1 = v1*m1;
    REQUIRE(_p1 == m1*v1);
    REQUIRE(_p1 == p1);
    
};

TEST_CASE( "Checking if force works", "[vector]" ) {
    
    const auto _F2 = 10_kg * 1_G;
    REQUIRE(_F2 == 98.1_N);
    
    REQUIRE(p1/10_s == F1);
    REQUIRE(m1*a1 == F1);
    
};

TEST_CASE( "Checking if energy works", "[vector]" ) {
    
    const auto _E2 = 10_kg * 1_G * 1_m;
    REQUIRE(_E2 == 98.1_J);
    
    REQUIRE(F1*s2 == E1);
    REQUIRE(p1*v2 == E1);
    
};
