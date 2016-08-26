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
            void copy(const std::string sourceFileName, const std::string destFileName);
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