#include <iostream>
#include "System/Console.h"

using std::cout;
using std::endl;
namespace EasyCpp
{
    namespace System
    {
        void Console::Write(int value)
        {
            cout << value << endl;
        }

        void Console::Write(long value)
        {
            cout << value << endl;
        }

        void Console::Write(double value)
        {
            cout << value << endl;
        }

        void Console::Write(String value)
        {
            cout << value << endl;
        }

        void Console::WriteLine()
        {
            cout << endl;
        }
    }
}