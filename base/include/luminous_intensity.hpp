#pragma once

#include "unit_t.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace base{
            class luminous_intensity : public unit_t<7>{
            public:
                luminous_intensity();
                explicit luminous_intensity(long double val);
                luminous_intensity(long double val, long double mult);
                
            };
            
        }
    }
}
 
