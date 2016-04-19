#include "System\Console.h"

using EasyCpp::System::Console;
using EasyCpp::System::String;
int main()
{
    Console::Write(2);

    Console::WriteLine();

    Console::Write(2.1);

    Console::Write("This is a string");

    String s1 = "hehe";
    String s2 = "hehe";
    if (s1 == s2)
    {
        Console::Write("s1 equals s2.");
    }

    Console::Write(s1.IndexOf("e"));
    Console::Write(s2.IndexOf("e", 2));
    Console::Write(s2.IndexOf("i", 2));

    String s3 = "abcdef";
    Console::Write(s3.EndsWith("def"));
    Console::Write(s3.EndsWith("def1"));

    auto keyInfo = Console::Readkey();

    return 0;
}