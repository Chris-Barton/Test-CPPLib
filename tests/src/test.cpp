#include <gtest/gtest.h>

#include "TestMath.h"
namespace {

TEST(Fib, TEST1) { ASSERT_EQ(TestMath::fib(1), 1); }
}  // namespace
