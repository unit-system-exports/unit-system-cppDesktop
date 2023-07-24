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
        class UNIT_SYSTEM_EXPORT_MACRO momentum {
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            momentum();
            momentum(const momentum& other) = default;

            explicit momentum(long double v);
            momentum(long double v, long double mult);
            momentum(long double v, long double mult, long double off);

            template<std::intmax_t numerator, std::intmax_t denumerator = 1>
            momentum(long double v, std::ratio<numerator, denumerator> mult, long double off = 0);

            momentum operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const momentum& other) const;
            momentum operator/(long double scalar) const;
            void operator/=(long double scalar);

            momentum operator+(const momentum& other) const;
            void operator+=(const momentum& other);

            momentum operator-(const momentum& other) const;
            void operator-=(const momentum& other);

            momentum operator-() const;

            void operator=(const momentum& other);

            explicit operator long double() const;

            #if __cplusplus >= 202002L
                int operator<=>(const momentum& other) const;
            #else
                bool operator<(const momentum& other) const;
                bool operator>(const momentum& other) const;
                bool operator<=(const momentum& other) const;
                bool operator>=(const momentum& other) const;
                bool operator==(const momentum& other) const;
                bool operator!=(const momentum& other) const;
            #endif
        };

        UNIT_SYSTEM_EXPORT_MACRO momentum unit_cast(const momentum& unit, long double new_multiplier = 1, long double new_offset = 0);
        UNIT_SYSTEM_EXPORT_MACRO momentum clamp(const momentum& unit, const momentum& lower, const momentum& upper);
        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const momentum& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO momentum operator "" _kgmps(long double val);
            UNIT_SYSTEM_EXPORT_MACRO momentum operator "" _kgmps(unsigned long long int val);
            
            
        }
        
    }
}

namespace std{
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::momentum abs(const sakurajin::unit_system::momentum& unit);
}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::momentum::momentum(long double v, std::ratio<numerator, denumerator>, long double off): momentum{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}