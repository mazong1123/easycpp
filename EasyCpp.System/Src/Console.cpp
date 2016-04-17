#include <iostream>
#include <cstdio>
#ifdef _WIN32
#include <conio.h>
#endif

#include "System/Console.h"

using std::cout;
using std::endl;
using std::shared_ptr;
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

        shared_ptr<ConsoleKeyInfo> Console::Readkey()
        {
            int keyValue = -1;
#ifdef _WIN32
            keyValue = _getch();
#else
            keyValue = getchar();
#endif
            // TODO:
            shared_ptr<ConsoleKeyInfo> consoleKeyInfoPtr(new ConsoleKeyInfo());

            return consoleKeyInfoPtr;
        }
    }
}