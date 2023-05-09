#pragma once


#include "unit_system/unit_t.hpp"



#ifndef UNIT_SYSTEM_EXPORT_MACRO
    #define UNIT_SYSTEM_EXPORT_MACRO
#endif


namespace sakurajin{
    namespace unit_system{
        class UNIT_SYSTEM_EXPORT_MACRO mass : public unit_t<3>{
        public:
            mass();
            mass(unit_t<3> val);
            explicit mass(long double val);
            mass(long double val, long double mult);
            mass(long double val, long double mult, long double offset);
        };
        

        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const mass& t);

        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _t(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _t(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _kg(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _kg(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _g(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _g(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _mg(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _mg(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _ug(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _ug(unsigned long long int val);
            
            
            
        }
        
    }
}