#ifndef EASYCPP_SYSTEM_STRING_H_
#define EASYCPP_SYSTEM_STRING_H_

#include <ostream>
#include <string>

namespace EasyCpp
{
    namespace System
    {
        class String
        {
        public:
            String();
            String(const std::string& str);
            String(const char* str);
            String(const String& rhs);
            String& operator=(const String& rhs);
            bool operator==(const String& rhs);
            bool operator!=(const String& rhs);
            String& operator+=(const String& rhs);
            String operator+(const String& rhs);

            friend std::ostream& operator<<(std::ostream& os, const String& str);

            int IndexOf(const String& value);
            int IndexOf(const String& value, int startIndex);

            bool EndsWith(const String& value);
        private:
            std::string m_internalString;
        };
    }
}

#endif
