#pragma once

#include "unit_t.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace base{
            class mass : public unit_t<3>{
            public:
                mass();
                mass(unit_t<3> val);
                explicit mass(long double val);
                mass(long double val, long double mult);
                
            };
            
            inline namespace literals{
                mass operator "" _kg(long double len);
                mass operator "" _g(long double len);
                mass operator "" _mg(long double len);
                mass operator "" _ug(long double len);
                mass operator "" _t(long double len);
                
                mass operator "" _kg(unsigned long long int len);
                mass operator "" _g(unsigned long long int len);
                mass operator "" _mg(unsigned long long int len);
                mass operator "" _ug(unsigned long long int len);
                mass operator "" _t(unsigned long long int len);
            }
            
        }
    }
}
 
