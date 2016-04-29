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
            virtual ~String();
            String& operator=(const String& rhs);
            String& operator=(const char* rhs);
            bool operator==(const String& rhs) const;
            bool operator!=(const String& rhs) const;
            String& operator+=(const String& rhs);
            String operator+(const String& rhs);

            friend std::ostream& operator<<(std::ostream& os, const String& str);

            int IndexOf(const String& value) const;
            int IndexOf(const String& value, int startIndex) const;

            StringPtr SubString(int startIndex, int length) const;

            bool EndsWith(const String& value);

            //
            // Summary:
            //     Returns a new string in which all occurrences of a specified string in the current 
            //     instance are replaced with another specified string
            //
            // Parameters:
            //   oldValue:
            //     The string to be replaced.
            //
            //   newValue:
            //   The string to replace all occurrences of oldValue.
            //
            // Return Value:
            //   A string that is equivalent to the current string except that all instances of oldValue are replaced with newValue. 
            //   If oldValue is not found in the current instance, the method returns the current instance unchanged.
            StringPtr Replace(const String& oldValue, const String& newValue);

            virtual std::string ToStdString();
            virtual StringPtr ToString();

            static StringPtr Format(const String& format, const Params& args);
        private:
            std::string m_internalString;
        };
    }
}

#endif
