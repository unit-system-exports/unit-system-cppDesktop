#pragma once

#include "unit_t.hpp"
#include <iostream>

namespace sakurajin{
    namespace unit_system{
        namespace base{
            //Amount of substance
            //The default unit is mole
            class amount : public unit_t<5>{
            public:
                amount(long double val);
                amount(long double val, long double mult);
                
                operator long double() const;
            };
            
            amount unit_cast(const amount& other, long double new_multiplier);
            
            std::ostream& operator<<(std::ostream& os, const amount& t);
            
            const long double avogadro_constant = 6.02214076e23;
            
            inline namespace literals{
                amount operator "" _mol(long double len);
                //specify how many things are there (eg. number of atoms)
                amount operator "" _things(long double len);
                
                amount operator "" _mol(unsigned long long int len);
                //specify how many things are there (eg. number of atoms)
                amount operator "" _things(unsigned long long int len);
            }
            
        }
    }
}
 
