#pragma once

#include "unit_t.hpp"
#include "length.hpp"
#include "time.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace common{
            class speed : public unit_t<201>{
            public:
                speed();
                explicit speed(long double val);
                speed(long double val, long double mult);
            };
            
            speed operator/(const base::length& s, const base::time_si& t);
            
            base::length operator*(const speed& v, const base::time_si& t);
            base::length operator*(const base::time_si& t, const speed& v);
            
            base::time_si operator/(const base::length& s, const speed& v);
            
            std::ostream& operator<<(std::ostream& os, const speed& v);
            
            inline namespace literals{
                speed operator "" _kmph(long double val);
                speed operator "" _mps(long double val);
                
                speed operator "" _kmph(unsigned long long int val);
                speed operator "" _mps(unsigned long long int val);
            }
            
        }
        
        common::speed unit_cast(const common::speed& other, long double new_multiplier);
            
    }
}
 
