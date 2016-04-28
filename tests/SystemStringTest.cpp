#include "SystemStringTestFixture.h"

using std::string;
using EasyCpp::System::String;

namespace EasyCppTest
{
    TEST_F(SystemStringTestFixture, SystemStringEndWithTrueTest)
    {
        // Prepare
        String testStr("abcdef");
        bool expected = true;

        // Act
        bool actual = testStr.EndsWith("def");

        // Assert
        EXPECT_EQ(expected, actual);
    }

    TEST_F(SystemStringTestFixture, SystemStringEndWithFalseTest)
    {
        // Prepare
        String testStr("abcdef1");
        bool expected = false;

        // Act
        bool actual = testStr.EndsWith("def");

        // Assert
        EXPECT_EQ(expected, actual);
    }

    TEST_F(SystemStringTestFixture, SystemStringOperatorEqualTrueTest)
    {
        // Prepare
        String testStr1("hello");
        String testStr2("hello");

        bool expected = true;

        // Act
        bool actual = testStr1 == testStr2;

        // Assert
        EXPECT_EQ(expected, actual);
    }

    TEST_F(SystemStringTestFixture, SystemStringOperatorEqualFalseTest)
    {
        // Prepare
        String testStr1("hello1");
        String testStr2("hello2");

        bool expected = false;

        // Act
        bool actual = testStr1 == testStr2;

        // Assert
        EXPECT_EQ(expected, actual);
    }

    TEST_F(SystemStringTestFixture, SystemStringIndexOfOneParamTest)
    {
        // Prepare
        String testStr("hello1");

        int expected = 1;

        // Act
        int actual = testStr.IndexOf("e");

        // Assert
        EXPECT_EQ(expected, actual);
    }

    TEST_F(SystemStringTestFixture, SystemStringIndexOfTwoParamsTest)
    {
        // Prepare
        String testStr("helelo1");

        int expected = 4;

        // Act
        int actual = testStr.IndexOf("l", 3);

        // Assert
        EXPECT_EQ(expected, actual);
    }

    TEST_F(SystemStringTestFixture, SystemStringToStdStringTest)
    {
        // Prepare
        String testStr("helelo1");

        std::string expected("helelo1");

        // Act
        std::string actual = testStr.ToStdString();

        // Assert
        EXPECT_EQ(expected, actual);
    }

    TEST_F(SystemStringTestFixture, SystemStringToStringTest)
    {
        // Prepare
        String testStr("helelo1");

        String expected("helelo1");

        // Act
        String actual = *testStr.ToString();

        // Assert
        EXPECT_EQ(expected, actual);
    }
}