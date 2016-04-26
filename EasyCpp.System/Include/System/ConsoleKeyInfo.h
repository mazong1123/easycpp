#ifndef EASYCPP_SYSTEM_CONSOLEKEYINFO_H_
#define EASYCPP_SYSTEM_CONSOLEKEYINFO_H_

#include "System\Object.h"

namespace EasyCpp
{
    namespace System
    {
        class ConsoleKeyInfo;

        typedef std::shared_ptr<ConsoleKeyInfo> ConsoleKeyInfoPtr;

        class ConsoleKeyInfo : public Object
        {
        public:
            ConsoleKeyInfo();

        private:
            ConsoleKeyInfo(ConsoleKeyInfo&) = delete;
        };
    }
}

#endif