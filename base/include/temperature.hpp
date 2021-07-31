#pragma once

#include "unit_t.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace base{
            class temperature : public unit_t<4>{
            public:
                temperature();
                temperature(unit_t<4> val);
                explicit temperature(long double val);
                temperature(long double val, long double mult);
                temperature(long double val, long double mult, long double offset);
                
            };
            
            inline namespace literals{
                temperature operator "" _K(long double len);
                temperature operator "" _K(unsigned long long int len);
                
                #ifndef ARDUINO
                    temperature operator "" _C(long double len);
                    temperature operator "" _C(unsigned long long int len);
                #else
                    temperature operator "" _Celsius(long double len);
                    temperature operator "" _Celsius(unsigned long long int len);
                #endif
            }
            
            namespace constants{
                const long double waterFreezinPoint = 273.15;
            }
            
        }
    }
}
 
