#include "SampleClassTestFixture.h"

using std::string;

namespace gtest_starter_sample 
{
    // Test when user's age is greater than 18, he/she should be saved to database.
    TEST_F(SampleClassTestFixture, SaveAdultUser_Age_GreaterThan_18) 
    {
        // Prepare
        MockDao* dao = SampleClassTestFixture::GetDao();
        SampleClass* sampleClass = SampleClassTestFixture::GetSampleClass();

        int userAge = 19;
        string userName = "user1";

        // Make isUserExist("user1") return false; - user1 does not exist in database.
        ON_CALL(*dao, isUserExist(userName)).WillByDefault(::testing::Return(false));

        // Expect
        // dao->addUser should be call 1 time. The passed userName is "user1" and userAge is 19.
        EXPECT_CALL(*dao, addUser(userName, userAge)).Times(1);
        
        // Act
        sampleClass->SaveAdultUser(userName, userAge);
    }

    // Test when user's age is less than 18, he/she should not be saved to database.
    TEST_F(SampleClassTestFixture, SaveAdultUser_Age_LessThan_18) 
    {
        // Prepare
        MockDao* dao = SampleClassTestFixture::GetDao();
        SampleClass* sampleClass = SampleClassTestFixture::GetSampleClass();

        // Age is under 18.
        int userAge = 17;
        string userName = "user1";

        // Make isUserExist("user1") return false; - user1 does not exist in database.
        ON_CALL(*dao, isUserExist(userName)).WillByDefault(::testing::Return(false));

        // Expect
        // dao->addUser should be never called.
        EXPECT_CALL(*dao, addUser(userName, userAge)).Times(0);
        
        // Act
        sampleClass->SaveAdultUser(userName, userAge);
    }

    // Test when user's age equals 18, he/she should be saved to database.
    TEST_F(SampleClassTestFixture, SaveAdultUser_Age_Equals_18) 
    {
        // Prepare
        MockDao* dao = SampleClassTestFixture::GetDao();
        SampleClass* sampleClass = SampleClassTestFixture::GetSampleClass();

        // Age is 18.
        int userAge = 18;
        string userName = "user1";

        // Make isUserExist("user1") return false; - user1 does not exist in database.
        ON_CALL(*dao, isUserExist(userName)).WillByDefault(::testing::Return(false));

        // Expect
        // dao->addUser should be call 1 time. The passed userName is "user1" and userAge is 18.
        EXPECT_CALL(*dao, addUser(userName, userAge)).Times(1);
        
        // Act
        sampleClass->SaveAdultUser(userName, userAge);
    }

    // Test when user's age is greater than 18, he/she already exists in database.
    TEST_F(SampleClassTestFixture, SaveAdultUser_Age_GreaterThan_18_BUT_ALREAD_EXIST) 
    {
        // Prepare
        MockDao* dao = SampleClassTestFixture::GetDao();
        SampleClass* sampleClass = SampleClassTestFixture::GetSampleClass();

        int userAge = 19;
        string userName = "user1";

        // Make isUserExist("user1") return true - user1 already exist.
        ON_CALL(*dao, isUserExist(userName)).WillByDefault(::testing::Return(true));

        // Expect
        // dao->addUser should be call 1 time. The passed userName is "user1" and userAge is 19.
        EXPECT_CALL(*dao, addUser(userName, userAge)).Times(0);
        
        // Act
        sampleClass->SaveAdultUser(userName, userAge);
    }
}