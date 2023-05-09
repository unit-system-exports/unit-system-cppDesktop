#pragma once


#include "unit_system/unit_t.hpp"



#ifndef UNIT_SYSTEM_EXPORT_MACRO
    #define UNIT_SYSTEM_EXPORT_MACRO
#endif


namespace sakurajin{
    namespace unit_system{
        class UNIT_SYSTEM_EXPORT_MACRO energy : public unit_t<8>{
        public:
            energy();
            energy(unit_t<8> val);
            explicit energy(long double val);
            energy(long double val, long double mult);
            energy(long double val, long double mult, long double offset);
        };
        

        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const energy& t);

        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _MJ(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _MJ(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _kJ(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _kJ(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _J(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _J(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _Nm(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _Nm(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _kWh(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _kWh(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _Wh(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _Wh(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _GeV(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _GeV(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _MeV(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _MeV(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _keV(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _keV(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _eV(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _eV(unsigned long long int val);
            
            
            
        }
        
    }
}