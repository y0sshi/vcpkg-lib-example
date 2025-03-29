#pragma once

// Windows DLL export/import macro
#if defined(_MSC_VER) && defined(VCPKG_LIB_EXAMPLE_EXPORTS)
    #define VCPKG_LIB_EXAMPLE_API __declspec(dllexport)
#elif defined(_MSC_VER) && defined(VCPKG_LIB_EXAMPLE_IMPORTS)
    #define VCPKG_LIB_EXAMPLE_API __declspec(dllimport)
#else
    #define VCPKG_LIB_EXAMPLE_API
#endif

namespace vcpkg_lib_example {
    VCPKG_LIB_EXAMPLE_API int  add(int a, int b);
    VCPKG_LIB_EXAMPLE_API void print_hello();
};

