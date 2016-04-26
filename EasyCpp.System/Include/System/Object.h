#ifndef EASYCPP_SYSTEM_OBJECT_H_
#define EASYCPP_SYSTEM_OBJECT_H_

#include <memory>

namespace EasyCpp
{
    namespace System
    {
        class Object;

        typedef std::shared_ptr<Object> ObjectPtr;

        class Object
        {
        public:
            Object();
            Object(const Object& rhs);
            virtual ~Object();
        };
    }
}

#endif
