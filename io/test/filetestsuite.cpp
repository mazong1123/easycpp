#include <iostream>
#include <exception>

#include "io/file.h"
#include "filetestsuite.h"

using std::string;
using easycpp::io::File;

namespace easycpp
{
    namespace unittest
    {
        void FileTestSuite::SetUp()
        {
        }

        void FileTestSuite::TearDown()
        {
        }

        TEST_F(FileTestSuite, FileCopySourceFileNameEmptyThrowException)
        {
            // Prepare
            string sourceFileName("");
            string destFileName("/home/test");

            // Act and assert
            EXPECT_THROW(File::Copy(sourceFileName, destFileName), std::invalid_argument);
        }

        TEST_F(FileTestSuite, FileCopyDestFileNameEmptyThrowException)
        {
            // Prepare
            string sourceFileName("/home/test");
            string destFileName("");

            // Act and assert
            EXPECT_THROW(File::Copy(sourceFileName, destFileName), std::invalid_argument);
        }

        TEST_F(FileTestSuite, FileCopyBothFileNamesEmptyThrowException)
        {
            // Prepare
            string sourceFileName("");
            string destFileName("");

            // Act and assert
            EXPECT_THROW(File::Copy(sourceFileName, destFileName), std::invalid_argument);
        }

        TEST_F(FileTestSuite, FileCopySourceFileNoExists)
        {
            // Prepare
            string sourceFileName("notexistfile");
            string destFileName("notexistfile");

            // Act and assert
            EXPECT_THROW(File::Copy(sourceFileName, destFileName), std::runtime_error);
        }

        TEST_F(FileTestSuite, FileExistsSuccess)
        {
            // Prepare
            string filePath("../../../io/test/testdata/srcfile");
            bool expectedResult = true;

            // Act
            bool actualResult = File::Exists(filePath);

            // Assert
            EXPECT_EQ(expectedResult, actualResult);
        }
    }
}