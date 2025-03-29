#include <gtest/gtest.h>
#include <vcpkg-lib-example/core.hpp>

TEST(SampleTest, SimplePass) {
    EXPECT_EQ(1, 1);
}

TEST(AddFunction, BasicTest) {
    EXPECT_EQ(vcpkg_lib_example::add(2, 3),  5);
    EXPECT_EQ(vcpkg_lib_example::add(-1, 1), 0);
}

TEST(PrintHelloTest, OutputsCorrectMessage) {
    testing:: internal::CaptureStdout();  // start capture stdout
    vcpkg_lib_example::print_hello();
    std::string captured_stdout = testing::internal::GetCapturedStdout();  // stop capture stdout and get string
    EXPECT_EQ(captured_stdout, "Hello, from vcpkg-lib-example !! (depend on fmt)\n");
}

