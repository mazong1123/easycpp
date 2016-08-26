#ifndef EASYCPP_IOTEST_FILE_TESTSUITE_H_
#define EASYCPP_IOTEST_FILE_TESTSUITE_H_

#include "gtest/gtest.h"

namespace easycpp
{
    namespace unittest
    {
        class FileTestSuite : public ::testing::Test
        {
        protected:
            virtual void SetUp();
            virtual void TearDown();
        };
    }
}

#endif