#pragma once

#include "unit_t.hpp"
#include "speed.hpp"
#include "momentum.hpp"
#include "acceleration.hpp"
#include "force.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace common{
            class energy : public unit_t<8>{
            public:
                energy();
                energy(unit_t<8> val);
                explicit energy(long double val);
                energy(long double val, long double mult);
            };
            
            //force based energy (E = F * s)
            energy operator*(const force& F, const base::length& s);
            energy operator*(const base::length& s, const force& F);
            
            force operator/(const energy& E, const base::length& s);
            base::length operator/(const energy& E, const force& F);
            
            //kinetic energy (E = p * v)
            energy operator*(const momentum& p, const speed& v);
            energy operator*(const speed& v, const momentum& p);
            
            momentum operator/(const energy& E, const speed& s);
            speed operator/(const energy& E, const momentum& s);
            
            inline namespace literals{
                energy operator "" _J(long double val);
                energy operator "" _J(unsigned long long int val);
            }
            
        }
        
    }
}
