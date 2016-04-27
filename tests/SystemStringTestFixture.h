#ifndef SYSTEM_STRING_TEST_FIXTURE_H
#define SYSTEM_STRING_TEST_FIXTURE_H

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "System\String.h"

namespace EasyCppTest 
{
    // TestFixture is used as the preparation of test cases.
    // We should reset the status after each test case executed.
    // SetUp() will be called before each test case exectued; whereas TearDown()
    // will be called after each test case executed.
    class SystemStringTestFixture : public ::testing::Test 
    {
    protected:
        // Will be called before each test case executed.
        virtual void SetUp() 
        {
        }

        // Will be called after each test case executed.
        virtual void TearDown() 
        {
        }
    };
}

#endif