#include <gtest/gtest.h>

#include "unit_t.hpp"
#include "prefix.hpp"

#include <iostream>

using namespace sakurajin::unit_system;
using namespace sakurajin::unit_system::prefix;

TEST( unit_t_tests, cast_tests ) {
    
    const unit_t<0> v1{1000,1};
    const unit_t<0> v2{1,1000};
    const unit_t<0> v3{10,100};
    const unit_t<0> v4{1,1};
    const unit_t<0> v5{1,kilo};
    const unit_t<0> v6{-1,kilo};
    
    
    EXPECT_TRUE(v1 == v2);
    EXPECT_TRUE(v1 == v3);
    EXPECT_TRUE(v2 == v3);
    EXPECT_TRUE(v2 == v5);
    
    EXPECT_TRUE(v1 != v4);
    
    EXPECT_TRUE(abs(v5) == abs(v6));
    
};

TEST( unit_t_tests, compare_tests) {
    
    const unit_t<0> v1{1000,1};
    const unit_t<0> v2{1,1000};
    const unit_t<0> v3{10,100};
    const unit_t<0> v4{1,1};
    const unit_t<0> v5{1,kilo};
    
    EXPECT_TRUE(v4 < v5);
    EXPECT_TRUE(v5 > v4);
    EXPECT_TRUE(v4 <= v5);
    EXPECT_TRUE(v5 >= v4);
    
    EXPECT_TRUE(v1 <= v1);
    EXPECT_TRUE(v1 >= v1);
    
    #if __cplusplus >= 202002L
    EXPECT_TRUE( (v4 <=> v5) < 0)
    EXPECT_TRUE( (v5 <=> v4) > 0)
    EXPECT_TRUE( (v1 <=> v1) == 0)
    #endif
    
};

TEST( unit_t_tests, operator_tests ) {
    
    const unit_t<0> v1{1000,1};
    const unit_t<0> v2{1,1000};
    const unit_t<0> v3{10,100};
    const unit_t<0> v4{1,1};
    const unit_t<0> v5{999,1};
    
    auto _v4 = v4;
    EXPECT_TRUE(v2 != _v4);
    _v4 = v2;
    EXPECT_TRUE(v2 == _v4);
    
    auto v6 = v1 + v2;
    EXPECT_DOUBLE_EQ(v6.value, 2000.0);
    EXPECT_TRUE(v6 == v1*2.0);
    EXPECT_TRUE(v1 == v6/2.0);
    
    auto v7 = v2 + v1;
    EXPECT_DOUBLE_EQ(v7.value, 2.0);
    EXPECT_TRUE(v6 == v7);
    
    auto v8 = v1-v4;
    EXPECT_TRUE(v5 == v8);

    EXPECT_DOUBLE_EQ(v1/v2, 1.0);
    
};

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

