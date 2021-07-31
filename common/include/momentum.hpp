#pragma once

#include "unit_t.hpp"
#include "speed.hpp"
#include "mass.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace common{
            class momentum : public unit_t<3201>{
            public:
                momentum();
                momentum(unit_t<3201> val);
                explicit momentum(long double val);
                momentum(long double val, long double mult);
            };
            
            momentum operator*(const base::mass& m, const speed& v);
            momentum operator*(const speed& v, const base::mass& m);
            
            base::mass operator/(const momentum& p, const speed& v);
            speed operator/(const momentum& p, const base::mass& m);
            
            inline namespace literals{
                momentum operator "" _kgmps(long double val);
                momentum operator "" _kgmps(unsigned long long int val);
            }
            
        }
        
    }
}
