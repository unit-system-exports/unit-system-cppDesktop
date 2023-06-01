#pragma once


#include "unit_system/unit_t.hpp"



#ifndef UNIT_SYSTEM_EXPORT_MACRO
    #define UNIT_SYSTEM_EXPORT_MACRO
#endif


namespace sakurajin{
    namespace unit_system{
        class UNIT_SYSTEM_EXPORT_MACRO electric_current : public unit_t<6>{
        public:
            electric_current();
            electric_current(unit_t<6> val);
            explicit electric_current(long double val);
            electric_current(long double val, long double mult);
            electric_current(long double val, long double mult, long double offset);
        };
        

        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const electric_current& t);

        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _A(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _A(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _PA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _PA(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _TA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _TA(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _GA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _GA(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _MA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _MA(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _kA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _kA(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _mA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _mA(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _uA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _uA(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _nA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _nA(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _pA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _pA(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _fA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _fA(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _aA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _aA(unsigned long long int val);
            
            
            
        }
        
    }
}