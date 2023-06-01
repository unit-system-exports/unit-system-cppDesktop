#pragma once


#include "unit_system/unit_t.hpp"



#ifndef UNIT_SYSTEM_EXPORT_MACRO
    #define UNIT_SYSTEM_EXPORT_MACRO
#endif


namespace sakurajin{
    namespace unit_system{
        class UNIT_SYSTEM_EXPORT_MACRO acceleration : public unit_t<2011>{
        public:
            acceleration();
            acceleration(unit_t<2011> val);
            explicit acceleration(long double val);
            acceleration(long double val, long double mult);
            acceleration(long double val, long double mult, long double offset);
        };
        

        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const acceleration& t);

        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO acceleration operator "" _mps2(long double val);
            UNIT_SYSTEM_EXPORT_MACRO acceleration operator "" _mps2(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO acceleration operator "" _G(long double val);
            UNIT_SYSTEM_EXPORT_MACRO acceleration operator "" _G(unsigned long long int val);
            
            
            
        }
        
    }
}