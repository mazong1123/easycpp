#ifndef EASYCPP_SYSTEM_STRING_H_
#define EASYCPP_SYSTEM_STRING_H_

#include <ostream>
#include <string>
#include <memory>
#include <vector>
#include "System\Object.h"
#include "System\TypeDef.h"

namespace EasyCpp
{
    namespace System
    {
        class String;

        typedef std::shared_ptr<String> StringPtr;

        class String : public Object
        {
        public:
            String();
            String(const std::string& str);
            String(const char* str);
            String(const String& rhs);
            String& operator=(const String& rhs);
            String& operator=(const char* rhs);
            bool operator==(const String& rhs);
            bool operator!=(const String& rhs);
            String& operator+=(const String& rhs);
            String operator+(const String& rhs);

            friend std::ostream& operator<<(std::ostream& os, const String& str);

            int IndexOf(const String& value) const;
            int IndexOf(const String& value, int startIndex) const;

            bool EndsWith(const String& value);

            static StringPtr Format(const String& format, const Params& args);
        private:
            std::string m_internalString;
        };
    }
}

#endif
