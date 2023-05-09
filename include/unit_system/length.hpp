#pragma once


#include "unit_system/unit_t.hpp"



#ifndef UNIT_SYSTEM_EXPORT_MACRO
    #define UNIT_SYSTEM_EXPORT_MACRO
#endif


namespace sakurajin{
    namespace unit_system{
        class UNIT_SYSTEM_EXPORT_MACRO length : public unit_t<2>{
        public:
            length();
            length(unit_t<2> val);
            explicit length(long double val);
            length(long double val, long double mult);
            length(long double val, long double mult, long double offset);
        };
        

        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const length& t);

        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _km(long double val);
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _km(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _m(long double val);
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _m(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _dm(long double val);
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _dm(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _cm(long double val);
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _cm(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _mm(long double val);
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _mm(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _um(long double val);
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _um(unsigned long long int val);
            
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _nm(long double val);
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _nm(unsigned long long int val);
            
            
            
        }
        
    }
}