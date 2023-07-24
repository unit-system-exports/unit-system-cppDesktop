#pragma once

#ifndef UNIT_SYSTEM_EXPORT_MACRO
    #define UNIT_SYSTEM_EXPORT_MACRO
#endif

#include <cstddef>
#include <cmath>
#include <algorithm>
#include <ratio>
#include <iostream>
#include <chrono>

namespace sakurajin{
    namespace unit_system{
        class UNIT_SYSTEM_EXPORT_MACRO mass {
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            mass();
            mass(const mass& other) = default;

            explicit mass(long double v);
            mass(long double v, long double mult);
            mass(long double v, long double mult, long double off);

            template<std::intmax_t numerator, std::intmax_t denumerator = 1>
            mass(long double v, std::ratio<numerator, denumerator> mult, long double off = 0);

            mass operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const mass& other) const;
            mass operator/(long double scalar) const;
            void operator/=(long double scalar);

            mass operator+(const mass& other) const;
            void operator+=(const mass& other);

            mass operator-(const mass& other) const;
            void operator-=(const mass& other);

            mass operator-() const;

            void operator=(const mass& other);

            explicit operator long double() const;

            #if __cplusplus >= 202002L
                int operator<=>(const mass& other) const;
            #else
                bool operator<(const mass& other) const;
                bool operator>(const mass& other) const;
                bool operator<=(const mass& other) const;
                bool operator>=(const mass& other) const;
                bool operator==(const mass& other) const;
                bool operator!=(const mass& other) const;
            #endif
        };

        UNIT_SYSTEM_EXPORT_MACRO mass unit_cast(const mass& unit, long double new_multiplier = 1, long double new_offset = 0);
        UNIT_SYSTEM_EXPORT_MACRO mass clamp(const mass& unit, const mass& lower, const mass& upper);
        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const mass& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _t(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _t(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _kg(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _kg(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _g(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _g(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _mg(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _mg(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _ug(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _ug(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _ng(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _ng(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _pg(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _pg(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _fg(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _fg(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _ag(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _ag(unsigned long long int val);
            
            
        }
        
    }
}

namespace std{
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::mass abs(const sakurajin::unit_system::mass& unit);
}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::mass::mass(long double v, std::ratio<numerator, denumerator>, long double off): mass{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}