#pragma once

#include "unit_t.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace base{
            class electric_current : public unit_t<6>{
            public:
                electric_current();
                electric_current(unit_t<6> val);
                explicit electric_current(long double val);
                electric_current(long double val, long double mult);
                
            };

            inline namespace literals{
                electric_current operator "" _MA(long double len);
                electric_current operator "" _kA(long double len);
                electric_current operator "" _A(long double len);
                electric_current operator "" _mA(long double len);
                electric_current operator "" _uA(long double len);
                electric_current operator "" _nA(long double len);
                
                electric_current operator "" _MA(unsigned long long int len);
                electric_current operator "" _kA(unsigned long long int len);
                electric_current operator "" _A(unsigned long long int len);
                electric_current operator "" _mA(unsigned long long int len);
                electric_current operator "" _uA(unsigned long long int len);
                electric_current operator "" _nA(unsigned long long int len);
            }
            
        }
    }
}
 
