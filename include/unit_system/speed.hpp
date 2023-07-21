#pragma once


#include "unit_system/unit_t.hpp"


#ifndef UNIT_SYSTEM_EXPORT_MACRO
    #define UNIT_SYSTEM_EXPORT_MACRO
#endif

namespace sakurajin{
    namespace unit_system{
        class UNIT_SYSTEM_EXPORT_MACRO speed : public unit_t<201>{
        public:
            speed();
            speed(unit_t<201> val);
            explicit speed(long double val);
            speed(long double val, long double mult);
            speed(long double val, long double mult, long double offset);
        };

        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const speed& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO speed operator "" _mps(long double val);
            UNIT_SYSTEM_EXPORT_MACRO speed operator "" _mps(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO speed operator "" _kmph(long double val);
            UNIT_SYSTEM_EXPORT_MACRO speed operator "" _kmph(unsigned long long int val);
            
            
        }
        
    }
}