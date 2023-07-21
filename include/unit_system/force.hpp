#pragma once


#include "unit_system/unit_t.hpp"


#ifndef UNIT_SYSTEM_EXPORT_MACRO
    #define UNIT_SYSTEM_EXPORT_MACRO
#endif

namespace sakurajin{
    namespace unit_system{
        class UNIT_SYSTEM_EXPORT_MACRO force : public unit_t<32011>{
        public:
            force();
            force(unit_t<32011> val);
            explicit force(long double val);
            force(long double val, long double mult);
            force(long double val, long double mult, long double offset);
        };

        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const force& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _N(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _N(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _PN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _PN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _TN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _TN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _GN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _GN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _MN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _MN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _kN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _kN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _mN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _mN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _uN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _uN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _nN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _nN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _pN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _pN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _fN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _fN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _aN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _aN(unsigned long long int val);
            
            
        }
        
    }
}