#pragma once


#include "unit_system/units.hpp"



#ifndef UNIT_SYSTEM_EXPORT_MACRO
    #define UNIT_SYSTEM_EXPORT_MACRO
#endif


namespace sakurajin{
    namespace unit_system{
        
        UNIT_SYSTEM_EXPORT_MACRO length operator*(const speed& v1, const time_si& v2);
        UNIT_SYSTEM_EXPORT_MACRO time_si operator/(const length& v1, const speed& v2);
        
        UNIT_SYSTEM_EXPORT_MACRO length operator*(const time_si& v1, const speed& v2);
        UNIT_SYSTEM_EXPORT_MACRO speed operator/(const length& v1, const time_si& v2);
        
        
        UNIT_SYSTEM_EXPORT_MACRO speed operator*(const acceleration& v1, const time_si& v2);
        UNIT_SYSTEM_EXPORT_MACRO time_si operator/(const speed& v1, const acceleration& v2);
        
        UNIT_SYSTEM_EXPORT_MACRO speed operator*(const time_si& v1, const acceleration& v2);
        UNIT_SYSTEM_EXPORT_MACRO acceleration operator/(const speed& v1, const time_si& v2);
        
        
        UNIT_SYSTEM_EXPORT_MACRO area operator*(const length& v1, const length& v2);
        UNIT_SYSTEM_EXPORT_MACRO length operator/(const area& v1, const length& v2);
        
        UNIT_SYSTEM_EXPORT_MACRO area square(const length& v1);
        
        
        UNIT_SYSTEM_EXPORT_MACRO energy operator*(const force& v1, const length& v2);
        UNIT_SYSTEM_EXPORT_MACRO length operator/(const energy& v1, const force& v2);
        
        UNIT_SYSTEM_EXPORT_MACRO energy operator*(const length& v1, const force& v2);
        UNIT_SYSTEM_EXPORT_MACRO force operator/(const energy& v1, const length& v2);
        
        
        UNIT_SYSTEM_EXPORT_MACRO energy operator*(const power& v1, const time_si& v2);
        UNIT_SYSTEM_EXPORT_MACRO time_si operator/(const energy& v1, const power& v2);
        
        UNIT_SYSTEM_EXPORT_MACRO energy operator*(const time_si& v1, const power& v2);
        UNIT_SYSTEM_EXPORT_MACRO power operator/(const energy& v1, const time_si& v2);
        
        
        UNIT_SYSTEM_EXPORT_MACRO energy operator*(const momentum& v1, const speed& v2);
        UNIT_SYSTEM_EXPORT_MACRO speed operator/(const energy& v1, const momentum& v2);
        
        UNIT_SYSTEM_EXPORT_MACRO energy operator*(const speed& v1, const momentum& v2);
        UNIT_SYSTEM_EXPORT_MACRO momentum operator/(const energy& v1, const speed& v2);
        
        
        UNIT_SYSTEM_EXPORT_MACRO momentum operator*(const force& v1, const time_si& v2);
        UNIT_SYSTEM_EXPORT_MACRO time_si operator/(const momentum& v1, const force& v2);
        
        UNIT_SYSTEM_EXPORT_MACRO momentum operator*(const time_si& v1, const force& v2);
        UNIT_SYSTEM_EXPORT_MACRO force operator/(const momentum& v1, const time_si& v2);
        
        
        UNIT_SYSTEM_EXPORT_MACRO force operator*(const mass& v1, const acceleration& v2);
        UNIT_SYSTEM_EXPORT_MACRO acceleration operator/(const force& v1, const mass& v2);
        
        UNIT_SYSTEM_EXPORT_MACRO force operator*(const acceleration& v1, const mass& v2);
        UNIT_SYSTEM_EXPORT_MACRO mass operator/(const force& v1, const acceleration& v2);
        
        
        UNIT_SYSTEM_EXPORT_MACRO momentum operator*(const mass& v1, const speed& v2);
        UNIT_SYSTEM_EXPORT_MACRO speed operator/(const momentum& v1, const mass& v2);
        
        UNIT_SYSTEM_EXPORT_MACRO momentum operator*(const speed& v1, const mass& v2);
        UNIT_SYSTEM_EXPORT_MACRO mass operator/(const momentum& v1, const speed& v2);
        
        
        UNIT_SYSTEM_EXPORT_MACRO power operator*(const force& v1, const speed& v2);
        UNIT_SYSTEM_EXPORT_MACRO speed operator/(const power& v1, const force& v2);
        
        UNIT_SYSTEM_EXPORT_MACRO power operator*(const speed& v1, const force& v2);
        UNIT_SYSTEM_EXPORT_MACRO force operator/(const power& v1, const speed& v2);
        
        
    }
}