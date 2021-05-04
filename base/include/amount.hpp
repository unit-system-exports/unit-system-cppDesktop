#pragma once

#include "unit_t.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace base{
            class amount : public unit_t<5>{
            public:
                amount(long double val);
                amount(long double val, long double mult);
                
            };
            
        }
    }
}
 
