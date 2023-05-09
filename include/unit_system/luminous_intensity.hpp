#pragma once


#include "unit_system/unit_t.hpp"



#ifndef UNIT_SYSTEM_EXPORT_MACRO
    #define UNIT_SYSTEM_EXPORT_MACRO
#endif


namespace sakurajin{
    namespace unit_system{
        class UNIT_SYSTEM_EXPORT_MACRO luminous_intensity : public unit_t<7>{
        public:
            luminous_intensity();
            luminous_intensity(unit_t<7> val);
            explicit luminous_intensity(long double val);
            luminous_intensity(long double val, long double mult);
            luminous_intensity(long double val, long double mult, long double offset);
        };
        

        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const luminous_intensity& t);

        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO luminous_intensity operator "" _cd(long double val);
            UNIT_SYSTEM_EXPORT_MACRO luminous_intensity operator "" _cd(unsigned long long int val);
            
            
            
        }
        
    }
}