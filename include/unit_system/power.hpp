#pragma once


#include "unit_system/unit_t.hpp"


#ifndef UNIT_SYSTEM_EXPORT_MACRO
    #define UNIT_SYSTEM_EXPORT_MACRO
#endif

namespace sakurajin{
    namespace unit_system{
        class UNIT_SYSTEM_EXPORT_MACRO power : public unit_t<801>{
        public:
            power();
            power(unit_t<801> val);
            explicit power(long double val);
            power(long double val, long double mult);
            power(long double val, long double mult, long double offset);
        };

        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const power& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _W(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _W(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _PW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _PW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _TW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _TW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _GW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _GW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _MW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _MW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _kW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _kW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _mW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _mW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _uW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _uW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _nW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _nW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _pW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _pW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _fW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _fW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _aW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _aW(unsigned long long int val);
            
            
        }
        
    }
}