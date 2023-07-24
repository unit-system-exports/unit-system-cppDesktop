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
        class UNIT_SYSTEM_EXPORT_MACRO speed {
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            speed();
            speed(const speed& other) = default;

            explicit speed(long double v);
            speed(long double v, long double mult);
            speed(long double v, long double mult, long double off);

            template<std::intmax_t numerator, std::intmax_t denumerator = 1>
            speed(long double v, std::ratio<numerator, denumerator> mult, long double off = 0);

            speed operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const speed& other) const;
            speed operator/(long double scalar) const;
            void operator/=(long double scalar);

            speed operator+(const speed& other) const;
            void operator+=(const speed& other);

            speed operator-(const speed& other) const;
            void operator-=(const speed& other);

            speed operator-() const;

            void operator=(const speed& other);

            explicit operator long double() const;

            #if __cplusplus >= 202002L
                int operator<=>(const speed& other) const;
            #else
                bool operator<(const speed& other) const;
                bool operator>(const speed& other) const;
                bool operator<=(const speed& other) const;
                bool operator>=(const speed& other) const;
                bool operator==(const speed& other) const;
                bool operator!=(const speed& other) const;
            #endif
        };

        UNIT_SYSTEM_EXPORT_MACRO speed unit_cast(const speed& unit, long double new_multiplier = 1, long double new_offset = 0);
        UNIT_SYSTEM_EXPORT_MACRO speed clamp(const speed& unit, const speed& lower, const speed& upper);
        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const speed& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO speed operator "" _mps(long double val);
            UNIT_SYSTEM_EXPORT_MACRO speed operator "" _mps(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO speed operator "" _kmph(long double val);
            UNIT_SYSTEM_EXPORT_MACRO speed operator "" _kmph(unsigned long long int val);
            
            
        }
        
    }
}

namespace std{
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::speed abs(const sakurajin::unit_system::speed& unit);
}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::speed::speed(long double v, std::ratio<numerator, denumerator>, long double off): speed{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}