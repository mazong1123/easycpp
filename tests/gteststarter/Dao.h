#ifndef DAO_H
#define DAO_H

#include <string>

namespace gtest_starter_sample
{
    class Dao
    {
    public:
        Dao()
        {
        }

        ~Dao()
        {
        }

        // Must be virtual for mocking.
        virtual bool isUserExist(std::string userName);

        // Must be virtual for mocking.
        virtual void addUser(std::string userName, int age);
    };
}

#endif