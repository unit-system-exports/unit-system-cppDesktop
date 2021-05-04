#pragma once

#include "unit_t.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace base{
            class electric_current : public unit_t<6>{
            public:
                electric_current(double val);
                electric_current(double val, double mult);
                
            };
            
        }
    }
}
 
