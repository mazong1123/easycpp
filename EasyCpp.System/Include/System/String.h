// ==++==
// 
//   From Jim Ma (mazong1123@gmail.com).
// 
// ==--==
/*============================================================
**
** Class:  String
**
**
** Purpose: Your favorite String class. Same interfaces as 
** .NET Framework System.String.
**
**
===========================================================*/

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

            //
            // Summary:
            //     Reports the zero-based index of the first occurrence of the specified string in this instance.
            //
            // Parameters:
            //   value:
            //     The string to seek.
            //
            // Return Value:
            //   The zero-based index position of value if that string is found, or -1 if it is not. If value is empty, the return value is 0.
            //
            int IndexOf(const String& value) const;

            //
            // Summary:
            //     Reports the zero-based index of the first occurrence of the specified string in this instance.
            //
            // Parameters:
            //   value:
            //     The string to seek.
            //   startIndex:
            //     The search starting position.
            //
            // Return Value:
            //   The zero-based index position of value if that string is found, or -1 if it is not. If value is empty, the return value is 0.
            //
            int IndexOf(const String& value, int startIndex) const;

            StringPtr SubString(int startIndex, int length) const;

            bool EndsWith(const String& value) const;

            StringPtr Trim() const;

            StringPtr TrimStart() const;

            StringPtr TrimStart(const std::vector<char>& trimChars) const;

            StringPtr TrimEnd() const;

            StringPtr TrimEnd(const std::vector<char>& trimChars) const;

            int Length() const;

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

            virtual std::string ToStdString() const;
            virtual StringPtr ToString() const;

            static StringPtr Format(const String& format, const Params& args);
        private:
            enum TrimType
            {
                TrimHead = 0,
                TrimTail = 1,
                TrimBoth = 2
            };

            StringPtr TrimHelper(const std::vector<char>& trimChars, TrimType trimType) const;

            StringPtr TrimHelper(TrimType trimType) const;

            std::string m_internalString;
        };
    }
}

#endif
