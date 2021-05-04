#pragma once

#include "unit_t.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace base{
            class temperature : public unit_t<4>{
            public:
                temperature(double val);
                temperature(double val, double mult);
                
            };
            
        }
    }
}
 
