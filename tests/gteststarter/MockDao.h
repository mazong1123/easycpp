#ifndef MOCK_DAO_H
#define MOCK_DAO_H

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "Dao.h"

namespace gtest_starter_sample
{
    class MockDao: public Dao
    {
    public:
        // MOCK_METHOD1 means the target method has 1 parameter.
        // isUserExist accepts 1 std::string parameter, and return bool.
        MOCK_METHOD1(isUserExist, bool(std::string));

        // MOCK_METHOD2 means the target method has 2 parameter.
        // (gmock also supports MOCK_METHOD3, ... MOCK_METHOD10)
        // addUser accepts 2 parameter, first is std::string, second is int, and return void.
        MOCK_METHOD2(addUser, void(std::string, int));
    };
}

#endif