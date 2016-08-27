#include <iostream>
#include <fstream>
#include <exception>
#include "io/file.h"

using std::ifstream;
using std::ofstream;

namespace easycpp
{
    namespace io
    {
        void File::Copy(const std::string& sourceFileName, const std::string& destFileName)
        {
            if (sourceFileName.empty())
            {
                throw std::invalid_argument("sourceFileName cannot be empty.");
            }

            if (destFileName.empty())
            {
                throw std::invalid_argument("destFileName cannot be empty.");
            }

            ifstream src(sourceFileName, std::ios::binary);
            if (!src.good())
            {
                throw std::runtime_error("Cannot open source file");
            }

            ofstream dst(destFileName, std::ios::binary);
            if (!dst.good())
            {
                throw std::runtime_error("Cannot open destination file");
            }

            dst << src.rdbuf();
        }

        bool File::Exists(const std::string& path)
        {
            if (path.empty())
            {
                return false;
            }

            ifstream file(path);
            return file.good();
        }
    }
}