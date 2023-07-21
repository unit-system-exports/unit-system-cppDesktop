#pragma once


#include "unit_system/unit_t.hpp"


#ifndef UNIT_SYSTEM_EXPORT_MACRO
    #define UNIT_SYSTEM_EXPORT_MACRO
#endif

namespace sakurajin{
    namespace unit_system{
        class UNIT_SYSTEM_EXPORT_MACRO area : public unit_t<22>{
        public:
            area();
            area(unit_t<22> val);
            explicit area(long double val);
            area(long double val, long double mult);
            area(long double val, long double mult, long double offset);
        };

        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const area& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _m2(long double val);
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _m2(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _are(long double val);
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _are(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _hectare(long double val);
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _hectare(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _km2(long double val);
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _km2(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _mm2(long double val);
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _mm2(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _um2(long double val);
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _um2(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _nm2(long double val);
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _nm2(unsigned long long int val);
            
            
        }
        
    }
}