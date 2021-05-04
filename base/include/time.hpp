#pragma once

#include "unit_t.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace base{
            class time : public unit_t<1>{
            public:
                time(long double val);
                time(long double val, long double mult);
                
            };
            
            time operator "" _a(long double len);
            time operator "" _d(long double len);
            time operator "" _h(long double len);
            time operator "" _min(long double len);
            time operator "" _s(long double len);
            time operator "" _ms(long double len);
            time operator "" _us(long double len);
            time operator "" _ns(long double len);
            time operator "" _fs(long double len);
            
        }
    }
}
