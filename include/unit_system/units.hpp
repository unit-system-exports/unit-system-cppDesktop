#ifndef UNIT_SYSTEM_UNITS_HEADER
#define UNIT_SYSTEM_UNITS_HEADER

// This header simply includes all units from the unit-system library

#include "unit_system/time_si.hpp"

#include "unit_system/length.hpp"

#include "unit_system/mass.hpp"

#include "unit_system/temperature.hpp"

#include "unit_system/amount.hpp"

#include "unit_system/electric_current.hpp"

#include "unit_system/luminous_intensity.hpp"

#include "unit_system/energy.hpp"

#include "unit_system/power.hpp"

#include "unit_system/speed.hpp"

#include "unit_system/acceleration.hpp"

#include "unit_system/area.hpp"

#include "unit_system/force.hpp"

#include "unit_system/momentum.hpp"


namespace sakurajin{
    namespace unit_system{
        template<class Rep, class Period = std::ratio<1> >
        time_si unit_cast(const std::chrono::duration<Rep, Period>& other, long double new_multiplier = 1.0){
            auto t = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1,1>>>(other);
            auto retval = time_si{t.count(), 1};
            return unit_cast(retval, new_multiplier);
        }
    }
}
#endif