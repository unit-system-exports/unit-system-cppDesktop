#pragma once

#include "unit_t.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace base{
            class length : public unit_t<2>{
            public:
                length(long double val);
                length(long double val, long double mult);
                
            };
            
            length operator "" _km(long double len);
            length operator "" _m(long double len);
            length operator "" _dm(long double len);
            length operator "" _cm(long double len);
            length operator "" _mm(long double len);
            length operator "" _um(long double len);
            length operator "" _nm(long double len);
            
        }
    }
}
 
