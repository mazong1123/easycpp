#ifndef EASYCPP_SYSTEM_CONSOLE_H_
#define EASYCPP_SYSTEM_CONSOLE_H_

#include <memory>
#include "System\String.h"
#include "System\ConsoleKeyInfo.h"
#include "System\Object.h"

namespace EasyCpp
{
    namespace System
    {
        class Console : public Object
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

            static ConsoleKeyInfoPtr Readkey();

        private:
            Console() = delete;
            Console(const Console& rhs) = delete;
            ~Console();
        };
    }
}
#endif

