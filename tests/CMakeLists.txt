enable_testing()
set(TEST_TARGET test_${TARGET})
add_executable(${TEST_TARGET} test_main.cpp)
find_package(GTest CONFIG REQUIRED)
target_link_libraries(${TEST_TARGET} PRIVATE
    ${TARGET}
    GTest::gtest_main
    )
include(GoogleTest)
gtest_discover_tests(${TEST_TARGET})

