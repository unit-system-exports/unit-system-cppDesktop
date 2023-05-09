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
            
            
            
        }
        
    }
}