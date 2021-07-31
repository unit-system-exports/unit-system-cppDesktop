#pragma once

#include "unit_t.hpp"
#include "time.hpp"
#include "amount.hpp"
#include "length.hpp"
#include "electric_current.hpp"
#include "luminous_intensity.hpp"
#include "mass.hpp"
#include "temperature.hpp"
#include "prefix.hpp"

#if __has_include(<iostream>)

    #include <iostream>
    
    namespace sakurajin{
        namespace unit_system{
            namespace base{
                std::ostream& operator<<(std::ostream& os, const amount& t);
            
                std::ostream& operator<<(std::ostream& os, const electric_current& I);
            
                std::ostream& operator<<(std::ostream& os, const length& s);
            
                std::ostream& operator<<(std::ostream& os, const luminous_intensity& J);
            
                std::ostream& operator<<(std::ostream& os, const mass& s);
            
                std::ostream& operator<<(std::ostream& os, const temperature& J);
            
                std::ostream& operator<<(std::ostream& os, const time_si& t);
            }
        }
    }
    
#endif

#if __has_include(<chrono>)

    #include <chrono>
    
    namespace sakurajin{
        namespace unit_system{
            template<class Rep, class Period = std::ratio<1> >
            base::time_si unit_cast(const std::chrono::duration<Rep, Period>& other, long double new_multiplier = 1.0){
                auto t = std::chrono::duration_cast<std::chrono::nanoseconds>(other);
                auto retval = base::time_si{t.count() / 1000000000.0, 1};
                return unit_cast(retval, new_multiplier);
            };
        }
    }
    
#endif
