#pragma once


#include "unit_system/unit_t.hpp"


#ifndef UNIT_SYSTEM_EXPORT_MACRO
    #define UNIT_SYSTEM_EXPORT_MACRO
#endif

namespace sakurajin{
    namespace unit_system{
        class UNIT_SYSTEM_EXPORT_MACRO amount : public unit_t<5>{
        public:
            amount();
            amount(unit_t<5> val);
            explicit amount(long double val);
            amount(long double val, long double mult);
            amount(long double val, long double mult, long double offset);
        };

        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const amount& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO amount operator "" _mol(long double val);
            UNIT_SYSTEM_EXPORT_MACRO amount operator "" _mol(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO amount operator "" _things(long double val);
            UNIT_SYSTEM_EXPORT_MACRO amount operator "" _things(unsigned long long int val);
            
            
        }
        
    }
}