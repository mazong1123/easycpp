#ifndef EASYCPP_SYSTEM_CONVERT_H_
#define EASYCPP_SYSTEM_CONVERT_H_

#include "System\String.h"

namespace EasyCpp
{
    namespace System
    {
        class Convert
        {
        public:
            static bool ToBoolean(int value);
            static bool ToBoolean(long value);
            static bool ToBoolean(double value);
            static bool ToBoolean(float value);
            static long ToInt64(const String& value, int fromBase);

        private:
            Convert();
            Convert(const Convert& rhs) = delete;
            ~Convert();
        };
    }
}

#endif
