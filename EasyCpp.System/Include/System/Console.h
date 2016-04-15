#ifndef EASYCPP_SYSTEM_CONSOLE_H_
#define EASYCPP_SYSTEM_CONSOLE_H_

#include "System\String.h"

namespace EasyCpp
{
    namespace System
    {
        class Console
        {
        public:
            //
            // Summary:
            //     Writes the text representation of the specified 32-bit signed integer value to
            //     the standard output stream.
            //
            // Parameters:
            //   value:
            //     The value to write.
            //
            static void Write(int value);

            //
            // Summary:
            //     Writes the text representation of the specified 64-bit signed integer value to
            //     the standard output stream.
            //
            // Parameters:
            //   value:
            //     The value to write.
            //
            static void Write(long value);

            //
            // Summary:
            //     Writes the text representation of the specified double-precision floating-point
            //     value, followed by the current line terminator, to the standard output stream.
            //
            // Parameters:
            //   value:
            //     The value to write.
            //
            static void Write(double value);

            static void Write(String value);

            static void WriteLine();
        };
    }
}
#endif

