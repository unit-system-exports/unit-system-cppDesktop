#pragma once

#include "unit_t.hpp"
#include "length.hpp"
#include "time.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace common{
            class speed : public base::unit_t<201>{
            public:
                speed(double val);
                speed(double val, double mult);
            };
            
            speed operator/(const base::length& s, const base::time& t);
            
        }
    }
}
 
