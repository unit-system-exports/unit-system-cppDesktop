#pragma once

#include "unit_t.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace base{
            class amount : public unit_t<5>{
            public:
                amount(double val);
                amount(double val, double mult);
                
            };
            
        }
    }
}
 
