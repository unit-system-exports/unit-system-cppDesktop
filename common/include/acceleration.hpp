#pragma once

#include "unit_t.hpp"
#include "length.hpp"
#include "time.hpp"
#include "speed.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace common{
            class acceleration : public base::unit_t<2011>{
            public:
                acceleration(long double val);
                acceleration(long double val, long double mult);
            };
            
            acceleration operator/(const speed& v, const base::time_si& t);
            
            speed operator*(const acceleration& a, const base::time_si& t);
            speed operator*(const base::time_si& t, const acceleration& a);
            
            base::time_si operator/(const speed& v, const acceleration& a);
            
            std::ostream& operator<<(std::ostream& os, const acceleration& v);
            
            inline namespace literals{
                acceleration operator "" _mps2(long double val);
                acceleration operator "" _g(long double val);
            }
            
        }
        
        common::acceleration unit_cast(const common::acceleration& other, long double new_multiplier);
        
    }
}
