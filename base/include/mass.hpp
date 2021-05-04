#pragma once

#include "unit_t.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace base{
            class mass : public unit_t<3>{
            public:
                mass(long double val);
                mass(long double val, long double mult);
                
            };
            
        }
    }
}
 
