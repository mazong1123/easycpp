#include <exception>

#include "Dao.h"

namespace gtest_starter_sample
{
    // isUserExist is not implemented. See MockDao to learn how to mock it.
    bool Dao::isUserExist(std::string userName)
    {
        throw std::runtime_error("Not implemented.");
    }

    // addUser is not implemented. See MockDao to learn how to mock it.
    void Dao::addUser(std::string userName, int age)
    {
        throw std::runtime_error("Not implemented.");
    }
}