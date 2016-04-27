#ifndef SAMPLE_CLASS_TEST_FIXTURE_H
#define SAMPLE_CLASS_TEST_FIXTURE_H

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "SampleClass.h"
#include "MockDao.h"  

namespace gtest_starter_sample 
{
    // TestFixture is used as the preparation of test cases.
    // We should reset the status after each test case executed.
    // SetUp() will be called before each test case exectued; whereas TearDown()
    // will be called after each test case executed.
    class SampleClassTestFixture : public ::testing::Test 
    {
    public:
        SampleClass* GetSampleClass()
        {
            return this->m_sampleClass;
        }

        MockDao* GetDao()
        {
            return this->m_dao;
        }
    protected:
        // Will be called before each test case executed.
        virtual void SetUp() 
        {
            this->m_dao = new MockDao();
            this->m_sampleClass = new SampleClass(this->m_dao);
        }

        // Will be called after each test case executed.
        virtual void TearDown() 
        {
            if (this->m_sampleClass)
            {
                delete this->m_sampleClass;
                this->m_sampleClass = 0;
            }

            if (this->m_dao)
            {
                delete this->m_dao;
                this->m_dao = 0;
            }
        }

    private:
        SampleClass* m_sampleClass;
        MockDao* m_dao;
    };
}

#endif