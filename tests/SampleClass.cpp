#include "SampleClass.h"

namespace gtest_starter_sample 
{
    void SampleClass::SaveAdultUser(std::string userName, int age)
    {
        if (age < 18)
        {
            return;
        }

        bool isUserAlreadyExist = this->m_dao->isUserExist(userName);
        if (isUserAlreadyExist)
        {
            return;
        }

        this->m_dao->addUser(userName, age);
    }
}