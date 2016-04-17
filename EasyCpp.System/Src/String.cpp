#include <ostream>
#include "System\String.h"

using std::ostream;

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

        int String::IndexOf(const String& value)
        {
            // TODO:
            return -1;
        }
    }
}