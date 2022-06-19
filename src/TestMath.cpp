#include "TestMath.h"

#include <fmt/format.h>

#include <cxxopts.hpp>
#include <range/v3/view.hpp>

namespace view = ranges::view;
int TestMath::fib(int x) {
    int a = 0, b = 1;

    for (int it : view::repeat(0) | view::take(x)) {
        (void)it;
        int tmp = a;
        a += b;
        b = tmp;
    }

    return a;
}
