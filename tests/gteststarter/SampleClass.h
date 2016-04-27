#include <string>
#ifndef SAMPLE_CLASS_H
#define SAMPLE_CLASS_H

#include "Dao.h"

namespace gtest_starter_sample 
{
    // A demonstrate class. 
    // Let's say Dao never implemented, but we still need to test SampleClass.
    // See SampleClassTest.cpp to learn how to test SampleClass even if Dao is not implemented.
    class SampleClass
    {
    public:
        SampleClass(Dao* dao)
        {
            this->m_dao = dao;
        }

        virtual ~SampleClass()
        {
        }

        void SaveAdultUser(std::string userName, int age);
    private:
        Dao* m_dao;
    };
}

#endif