#include <gtest/gtest.h>

#include "unit_system.hpp"

#define EXPECT_UNIT_EQ(X,Y) EXPECT_DOUBLE_EQ((X).value, sakurajin::unit_system::unit_cast(Y, (X).multiplier, (X).offset).value)
