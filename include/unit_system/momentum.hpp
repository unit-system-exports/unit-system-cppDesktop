#pragma once


#include "unit_system/unit_t.hpp"


#ifndef UNIT_SYSTEM_EXPORT_MACRO
    #define UNIT_SYSTEM_EXPORT_MACRO
#endif

namespace sakurajin{
    namespace unit_system{
        class UNIT_SYSTEM_EXPORT_MACRO momentum : public unit_t<3201>{
        public:
            momentum();
            momentum(unit_t<3201> val);
            explicit momentum(long double val);
            momentum(long double val, long double mult);
            momentum(long double val, long double mult, long double offset);
        };

        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const momentum& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO momentum operator "" _kgmps(long double val);
            UNIT_SYSTEM_EXPORT_MACRO momentum operator "" _kgmps(unsigned long long int val);
            
            
        }
        
    }
}