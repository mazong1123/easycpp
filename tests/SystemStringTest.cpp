#include "SystemStringTestFixture.h"

using std::string;
using EasyCpp::System::String;
using EasyCpp::System::StringPtr;

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

    TEST_F(SystemStringTestFixture, SystemStringReplaceSingleSuccessTest)
    {
        // Prepare
        String testStr("helelo1");

        String expected("heleaa");

        // Act
        String actual = *testStr.Replace("lo1", "aa");

        // Assert
        EXPECT_EQ(expected, actual);
    }

    TEST_F(SystemStringTestFixture, SystemStringReplaceMultipleSuccessTest)
    {
        // Prepare
        String testStr("helelo1");

        String expected("hbbbbo1");

        // Act
        String actual = *testStr.Replace("el", "bb");

        // Assert
        EXPECT_EQ(expected, actual);
    }

    TEST_F(SystemStringTestFixture, SystemStringFormatMultipleArgsSuccessTest)
    {
        // Prepare
        String formatStr("Hello, {0} and {1}");

        String expected("Hello, world and easy cpp");

        EasyCpp::System::Params params;
        params.push_back(StringPtr(new String("world")));
        params.push_back(StringPtr(new String("easy cpp")));

        // Act
        String actual = *String::Format(formatStr, params);

        // Assert
        EXPECT_EQ(expected, actual);
    }

    TEST_F(SystemStringTestFixture, SystemStringSubStringNormalArgsSuccessTest)
    {
        // Prepare
        String testStr("Hello, easy cpp");

        String expected("Hello");

        // Act
        String actual = *testStr.SubString(0, 5);

        // Assert
        EXPECT_EQ(expected, actual);
    }

    TEST_F(SystemStringTestFixture, SystemStringTrimSuccessTest)
    {
        // Prepare
        String testStr("   Hello, easy cpp   ");

        String expected("Hello, easy cpp");

        // Act
        String actual = *testStr.Trim();

        // Assert
        EXPECT_EQ(expected, actual);
    }

    TEST_F(SystemStringTestFixture, SystemStringTrimStartSuccessTest)
    {
        // Prepare
        String testStr("   Hello, easy cpp   ");

        String expected("Hello, easy cpp   ");

        // Act
        String actual = *testStr.TrimStart();

        // Assert
        EXPECT_EQ(expected, actual);
    }

    TEST_F(SystemStringTestFixture, SystemStringTrimEndSuccessTest)
    {
        // Prepare
        String testStr("   Hello, easy cpp   ");

        String expected("   Hello, easy cpp");

        // Act
        String actual = *testStr.TrimEnd();

        // Assert
        EXPECT_EQ(expected, actual);
    }
}