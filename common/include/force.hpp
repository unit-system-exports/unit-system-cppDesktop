#pragma once

#include "unit_t.hpp"
#include "speed.hpp"
#include "momentum.hpp"
#include "acceleration.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace common{
            class force : public unit_t<32011>{
            public:
                force();
                force(unit_t<32011> val);
                explicit force(long double val);
                force(long double val, long double mult);
            };
            
            force operator/(const momentum& p, const base::time_si& t);
            
            momentum operator*(const force& F, const base::time_si& t);
            momentum operator*(const base::time_si& t, const force& F);
            
            base::time_si operator/(const momentum& p, const force& F);
            
            force operator*(const base::mass& m, const acceleration& a);
            force operator*(const acceleration& a, const base::mass& m);
            
            base::mass operator/(const force& p, const acceleration& a);
            acceleration operator/(const force& p, const base::mass& m);
            
            inline namespace literals{
                #ifndef ARDUINO
                    force operator "" _N(long double val);
                    force operator "" _N(unsigned long long int val);
                #else                    
                    force operator "" _Newton(long double val);
                    force operator "" _Newton(unsigned long long int val);
                #endif
            }
            
        }
        
    }
}
