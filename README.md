# easycpp
A C++ library let you write C++ in C# way.

## The Goal
1. To clone the api of .NET Framework library.
2. Eniminate C++ magics. Let's write clean and elegant C++ code. Like what C# brought to us.

For example:

In C#, we have following code:
```csharp
    
class Program
{
    static void Main(string[] args)
    {
        Console.Write(2);

        Console.WriteLine();

        Console.Write(2.1);

        Console.Write("This is a string");
    }
}
    
```

Now with easycpp, we can write similar C++ code:
```cpp
#include "System\Console.h"

using EasyCpp::System::Console;
int main()
{
    Console::Write(2);

    Console::WriteLine();

    Console::Write(2.1);

    Console::Write("This is a string");

    return 0;
}
```

## Why?
I've used C# and C++ for decades. I know it's hard to write correct, elegant and efficient C++ code. Just want to change the C++ coding experience.
