#include <cstdarg>
#include <ostream>
#include <stdexcept>
#include "System\String.h"

using std::ostream;
using std::shared_ptr;
using std::vector;

namespace EasyCpp
{
    namespace System
    {
        String::String()
            :m_internalString()
        {
        }

        String::String(const std::string& str)
            :m_internalString(str)
        {
        }

        String::String(const char* str)
            : m_internalString(str)
        {
        }

        String::String(const String& rhs)
        {
            this->m_internalString = rhs.m_internalString;
        }

        String& String::operator=(const String& rhs)
        {
            if (this == &rhs)
            {
                return *this;
            }

            this->m_internalString = rhs.m_internalString;

            return *this;
        }

        String& String::operator=(const char* rhs)
        {
            std::string s(rhs);

            this->m_internalString = s;

            return *this;
        }

        ostream& operator<<(ostream& os, const String& str)
        {
            os << str.m_internalString;
            return os;
        }

        bool String::operator==(const String& rhs)
        {
            return this->m_internalString == rhs.m_internalString;
        }

        bool String::operator!=(const String& rhs)
        {
            return !this->operator==(rhs);
        }

        String& String::operator+=(const String& rhs)
        {
            this->m_internalString += rhs.m_internalString;

            return *this;
        }

        String String::operator+(const String& rhs)
        {
            String newString(this->m_internalString + rhs.m_internalString);

            return newString;
        }

        int String::IndexOf(const String& value) const
        {
            return this->IndexOf(value, 0);
        }

        int String::IndexOf(const String& value, int startIndex) const
        {
            auto loc = this->m_internalString.find(value.m_internalString, startIndex);
            if (loc == std::string::npos)
            {
                return -1;
            }

            if (loc > INT_MAX)
            {
                throw std::overflow_error("The index is larger than INT_MAX");
            }

            int locInt = static_cast<int>(loc);

            return locInt;
        }

        bool String::EndsWith(const String& value)
        {
            if (value.m_internalString.size() > this->m_internalString.size())
            {
                return false;
            }

            return std::equal(value.m_internalString.rbegin(), value.m_internalString.rend(), this->m_internalString.rbegin());
        }

        StringPtr String::Format(const String& format, const Params& args)
        {
            // Find place holder indexes.
            vector<int> placeHolderIndexes;
            int startIndex = 0;
            do
            {
                startIndex = format.IndexOf("{", startIndex);
                if (startIndex < 0)
                {
                    break;
                }

                int endIndex = format.IndexOf("}", startIndex);
                if (endIndex < 0)
                {
                    break;
                }

                placeHolderIndexes.push_back(startIndex);

                startIndex = endIndex;
            } while (true);

            if (args.size() != placeHolderIndexes.size())
            {
                throw std::invalid_argument("Arguments count do not match the format string.");
            }

            // TODO:

            StringPtr formattedString(new String(format));

            return formattedString;
        }
    }
}