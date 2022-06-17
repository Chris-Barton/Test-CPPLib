#include <gtest/gtest.h>
#include "TestMath.h"
namespace {

    TEST(Fib, TEST1)
    {
        ASSERT_TRUE(TestMath::fib(1) == 1);
    }
}