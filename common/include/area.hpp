#pragma once

#include "unit_t.hpp"
#include "length.hpp"

namespace sakurajin{
    namespace unit_system{
        namespace common{
            class area : public unit_t<22>{
            public:
                area();
                area(unit_t<22> val);
                explicit area(long double val);
                area(long double val, long double mult);
            };
            
            base::length operator/(const area& a, const base::length& l);
            
            area operator*(const base::length& l1, const base::length& l2);
            area square(const base::length& l);
            
            inline namespace literals{
                area operator "" _km2(long double val);
                area operator "" _m2(long double val);
                area operator "" _mm2(long double val);

                area operator "" _km2(unsigned long long int val);
                area operator "" _m2(unsigned long long int val);
                area operator "" _mm2(unsigned long long int val);
            }
            
        }
            
    }
}

