#ifndef EASYCPP_SYSTEM_TYPEDEF_H_
#define EASYCPP_SYSTEM_TYPEDEF_H_

#include <vector>
#include <memory>
#include "System\Object.h"
namespace EasyCpp
{
    namespace System
    {
        typedef std::vector<std::shared_ptr<Object>> Params;
    }
}

#endif
