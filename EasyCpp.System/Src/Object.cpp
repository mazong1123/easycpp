#include "System\Object.h"

using std::string;

namespace EasyCpp
{
    namespace System
    {
        Object::Object()
        {
        }

        Object::Object(const Object& rhs)
        {
        }

        Object::~Object()
        {
        }

        string Object::ToStdString()
        {
            return "System.Object";
        }
    }
}