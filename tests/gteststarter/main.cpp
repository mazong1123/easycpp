#include <iostream>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

int main(int argc, char** argv)
{
    testing::InitGoogleMock(&argc, argv);

    int testExitCode = RUN_ALL_TESTS();

    // Wait for any input.
	std::getchar();

    return testExitCode;
}