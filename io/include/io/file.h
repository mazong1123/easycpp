#ifndef EASYCPP_IO_FILE_H_
#define EASYCPP_IO_FILE_H_

#include <string>

namespace easycpp
{
    namespace io
    {
        class File
        {
        public:
            static void Copy(const std::string& sourceFileName, const std::string& destFileName);
            static bool Exists(const std::string& path);
        private:
            File()
            {
            }

            File(const File&)
            {
            }

            virtual ~File()
            {
            }
        };
    }
}

#endif