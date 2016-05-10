#include <ostream>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <functional> 
#include <cctype>
#include <locale>

#include "System\String.h"
#include "System\Convert.h"

using std::ostream;
using std::shared_ptr;
using std::vector;
using std::string;
using std::replace;
using std::map;

namespace EasyCpp
{
    namespace System
    {
        String::String()
            :m_internalString()
        {
        }

        String::String(const std::string& str)
            : m_internalString(str)
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

        String::~String()
        {
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

        bool String::operator==(const String& rhs) const
        {
            return this->m_internalString == rhs.m_internalString;
        }

        bool String::operator!=(const String& rhs) const
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

        bool String::EndsWith(const String& value) const
        {
            if (value.m_internalString.size() > this->m_internalString.size())
            {
                return false;
            }

            return std::equal(value.m_internalString.rbegin(), value.m_internalString.rend(), this->m_internalString.rbegin());
        }

        StringPtr String::Trim() const
        {
            return this->TrimHelper(TrimBoth);
        }

        StringPtr String::TrimStart() const
        {
            return this->TrimHelper(TrimHead);
        }

        StringPtr String::TrimStart(const std::vector<char>& trimChars) const
        {
            if (trimChars.empty())
            {
                return this->TrimStart();
            }

            return this->TrimHelper(trimChars, TrimHead);
        }

        StringPtr String::TrimEnd() const
        {
            return this->TrimHelper(TrimTail);
        }

        StringPtr String::TrimEnd(const std::vector<char>& trimChars) const
        {
            if (trimChars.empty())
            {
                return this->TrimEnd();
            }

            return this->TrimHelper(trimChars, TrimTail);
        }

        int String::Length() const
        {
            return this->m_internalString.length();
        }

        StringPtr String::Replace(const String& oldValue, const String& newValue)
        {
            // Copy new String instance.
            StringPtr replacedString(new String(*this));

            size_t startPos = replacedString->m_internalString.find(oldValue.m_internalString, 0);
            while (startPos != std::string::npos)
            {
                replacedString->m_internalString.replace(startPos, oldValue.m_internalString.length(), newValue.m_internalString);
                
                // In case 'newValue' contains 'oldValue', like replacing 'x' with 'yx'
                startPos += newValue.m_internalString.length(); 

                startPos = replacedString->m_internalString.find(oldValue.m_internalString, startPos);
            }

            return replacedString;
        }

        string String::ToStdString() const
        {
            return this->m_internalString;
        }

        StringPtr String::ToString() const
        {
            // TODO: Need enhancement here. We don't want to construct a new String object.
            StringPtr str(new String(*this));
            return str;
        }

        StringPtr String::SubString(int startIndex, int length) const
        {
            // Bounds checking.
            if (startIndex < 0)
            {
                throw std::invalid_argument("startIndex ArgumentOutOfRange_StartIndex");
            }

            if (startIndex > (int)this->m_internalString.length())
            {
                throw std::invalid_argument("startIndex ArgumentOutOfRange_StartIndexLargerThanLength");
            }

            if (length < 0)
            {
                throw std::invalid_argument("startIndex ArgumentOutOfRange_NegativeLength");
            }

            if (startIndex > (int)this->m_internalString.length() - length)
            {
                throw std::invalid_argument("startIndex ArgumentOutOfRange_IndexLength");
            }

            StringPtr subStr(new String(this->m_internalString.substr(startIndex, length)));

            return subStr;
        }

        StringPtr String::Format(const String& format, const Params& args)
        {
            // Find place holder indexes.
            map<long, String> placeHolderIndexes;
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

                StringPtr placeHolderIndex = format.SubString(startIndex + 1, endIndex - startIndex - 1);
                long placeHolderIndexValue = Convert::ToInt64(*placeHolderIndex, 10);
                
                if (placeHolderIndexValue >= (long)args.size())
                {
                    throw std::invalid_argument("Format place holder indexes are out of range.");
                }

                StringPtr placeHolderString = format.SubString(startIndex, endIndex - startIndex + 1);

                placeHolderIndexes.insert(std::make_pair(placeHolderIndexValue, *placeHolderString));

                startIndex = endIndex;
            } while (true);

            if (args.size() != placeHolderIndexes.size())
            {
                throw std::invalid_argument("Arguments count do not match the format string.");
            }

            StringPtr formattedString(new String(format));

            for (size_t i = 0; i < args.size(); i++)
            {
                auto pit = placeHolderIndexes.find(i);

                string argStr = args[i]->ToStdString();

                formattedString = formattedString->Replace(pit->second, argStr);
            }

            return formattedString;
        }

        StringPtr String::TrimHelper(const std::vector<char>& trimChars, TrimType trimType) const
        {
            int len = this->Length();
            int end = len - 1;
            int start = 0;

            int trimCharsLen = (int)trimChars.size();

            if (trimType != TrimTail)
            {
                for (start = 0; start < len; start++)
                {
                    char ch = this->m_internalString[start];
                    bool isMatched = false;

                    for (int i = 0; i < trimCharsLen; i++)
                    {
                        if (trimChars[i] == ch)
                        {
                            isMatched = true;
                            break;
                        }
                    }

                    if (!isMatched)
                    {
                        // Current char does not match any trim chars.
                        // We should stop the process now. The start value
                        // indicates the start point of substring().
                        break;
                    }
                }
            }

            if (trimType != TrimHead)
            {
                for (end = len - 1; end >= start; end--)
                {
                    char ch = this->m_internalString[end];
                    bool isMatched = false;

                    for (int i = 0; i < trimCharsLen; i++)
                    {
                        if (trimChars[i] == ch)
                        {
                            isMatched = true;
                            break;
                        }
                    }
                    if (!isMatched)
                    { 
                        // Current char does not match any trim chars.
                        // We should stop the process now. The end value
                        // indicates the end point of substring().
                        break;
                    }
                }
            }

            StringPtr trimedStringPtr = StringPtr(new String(*this));

            return trimedStringPtr->SubString(start, end - start + 1);
        }

        StringPtr String::TrimHelper(TrimType trimType) const
        {
            StringPtr trimedStringPtr = StringPtr(new String(*this));

            switch (trimType)
            {
            case TrimHead:
                trimedStringPtr->m_internalString.erase(trimedStringPtr->m_internalString.begin(),
                    std::find_if(trimedStringPtr->m_internalString.begin(), trimedStringPtr->m_internalString.end(),
                        std::not1(std::ptr_fun<int, int>(std::isspace))));
                break;
            case TrimTail:
                trimedStringPtr->m_internalString.erase(std::find_if(trimedStringPtr->m_internalString.rbegin(), trimedStringPtr->m_internalString.rend(), 
                    std::not1(std::ptr_fun<int, int>(std::isspace))).base(), trimedStringPtr->m_internalString.end());
                break;
            default:
                trimedStringPtr->m_internalString.erase(trimedStringPtr->m_internalString.begin(),
                    std::find_if(trimedStringPtr->m_internalString.begin(), trimedStringPtr->m_internalString.end(),
                        std::not1(std::ptr_fun<int, int>(std::isspace))));

                trimedStringPtr->m_internalString.erase(std::find_if(trimedStringPtr->m_internalString.rbegin(), trimedStringPtr->m_internalString.rend(),
                    std::not1(std::ptr_fun<int, int>(std::isspace))).base(), trimedStringPtr->m_internalString.end());
                break;
            }

            return trimedStringPtr;
        }
    }
}