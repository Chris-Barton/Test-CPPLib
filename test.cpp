#include <catch2/catch_test_macros.hpp>
#include "TestMath.h"


TEST_CASE("First Fibonacci is 1", "[single-file]") {
    REQUIRE(TestMath::fib(1) == 1);
}
