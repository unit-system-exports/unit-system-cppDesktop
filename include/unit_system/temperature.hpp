#pragma once


#include "unit_system/unit_t.hpp"



#ifndef UNIT_SYSTEM_EXPORT_MACRO
    #define UNIT_SYSTEM_EXPORT_MACRO
#endif


namespace sakurajin{
    namespace unit_system{
        class UNIT_SYSTEM_EXPORT_MACRO temperature : public unit_t<4>{
        public:
            temperature();
            temperature(unit_t<4> val);
            explicit temperature(long double val);
            temperature(long double val, long double mult);
            temperature(long double val, long double mult, long double offset);
        };
        

        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const temperature& t);

        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO temperature operator "" _K(long double val);
            UNIT_SYSTEM_EXPORT_MACRO temperature operator "" _K(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO temperature operator "" _C(long double val);
            UNIT_SYSTEM_EXPORT_MACRO temperature operator "" _C(unsigned long long int val);
            
            
            
        }
        
    }
}