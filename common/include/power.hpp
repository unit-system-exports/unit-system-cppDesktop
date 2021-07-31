#pragma once


#include "unit_t.hpp"
#include "force.hpp"
#include "speed.hpp"
#include "energy.hpp"
#include "time.hpp"

namespace sakurajin {
    namespace unit_system {
        namespace common {
            class power : public unit_t<801> {
            public:
              power();
              power(unit_t<801> val);
              explicit power(long double val);
              power(long double val, long double mult);
            };
            
            //Energy / time = Power
            energy operator*(const power& P, const base::time_si& t);
            energy operator*(const base::time_si& t, const power& P);

            power operator/(const energy& E, const base::time_si& t);

            base::time_si operator/(const energy& E, const power& P);

            //Force * speed = Power
            power operator*(const force& F, const speed& v);
            power operator*(const speed& v, const force& F);

            force operator/(const power& P, const speed& v);

            speed operator/(const power& P, const force& F);

            inline namespace literals {
                power operator "" _W(long double val);
                power operator "" _W(unsigned long long int val);
             }
        }
    }
}

//F = P/v
