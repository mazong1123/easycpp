#include "System\Convert.h"

#include <stdexcept>
#include <sstream>

using std::stringstream;

namespace EasyCpp
{
    namespace System
    {
        Convert::Convert()
        {
        }

        Convert::~Convert()
        {
        }

        bool Convert::ToBoolean(int value)
        {
            return value != 0;
        }

        bool Convert::ToBoolean(long value)
        {
            return value != 0;
        }

        bool Convert::ToBoolean(double value)
        {
            return value != 0;
        }

        bool Convert::ToBoolean(float value)
        {
            return value != 0;
        }

        long Convert::ToInt64(const String& value, int fromBase)
        {
            if (fromBase != 2 && fromBase != 8 && fromBase != 10 && fromBase != 16)
            {
                throw std::invalid_argument("Invalid base.");
            }

            std::stringstream sstr(value.ToStdString());

            long result;
            sstr >> result;

            // TODO: base specific converting.

            return result;
        }
    }
}
