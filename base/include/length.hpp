#pragma once

#include "unit_t.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace base{
            class length : public unit_t<2>{
            public:
                length(double val);
                length(double val, double mult);
                
            };
            
        }
    }
}
 
