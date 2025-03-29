#include <fmt/core.h>
#include <vcpkg-lib-example/core.hpp>

namespace vcpkg_lib_example {
    int add(int a, int b) {
        return a + b;
    }
    void print_hello() {
        fmt::print("{}\n", "Hello, from vcpkg-lib-example !! (depend on fmt)");
    }
};

