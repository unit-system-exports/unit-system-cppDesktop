#pragma once

#include "unit_t.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace base{
            class time_si : public unit_t<1>{
            public:
                time_si(long double val);
                time_si(long double val, long double mult);
                
            };
            
            inline namespace literals{
                time_si operator "" _a(long double len);
                time_si operator "" _d(long double len);
                time_si operator "" _h(long double len);
                time_si operator "" _min(long double len);
                time_si operator "" _s(long double len);
                time_si operator "" _ms(long double len);
                time_si operator "" _us(long double len);
                time_si operator "" _ns(long double len);
                time_si operator "" _fs(long double len);
            }
            
        }
    }
}
