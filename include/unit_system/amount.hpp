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
        class UNIT_SYSTEM_EXPORT_MACRO amount {
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            amount();
            amount(const amount& other) = default;

            explicit amount(long double v);
            amount(long double v, long double mult);
            amount(long double v, long double mult, long double off);

            template<std::intmax_t numerator, std::intmax_t denumerator = 1>
            amount(long double v, std::ratio<numerator, denumerator> mult, long double off = 0);

            amount operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const amount& other) const;
            amount operator/(long double scalar) const;
            void operator/=(long double scalar);

            amount operator+(const amount& other) const;
            void operator+=(const amount& other);

            amount operator-(const amount& other) const;
            void operator-=(const amount& other);

            amount operator-() const;

            void operator=(const amount& other);

            explicit operator long double() const;

            #if __cplusplus >= 202002L
                int operator<=>(const amount& other) const;
            #else
                bool operator<(const amount& other) const;
                bool operator>(const amount& other) const;
                bool operator<=(const amount& other) const;
                bool operator>=(const amount& other) const;
                bool operator==(const amount& other) const;
                bool operator!=(const amount& other) const;
            #endif
        };

        UNIT_SYSTEM_EXPORT_MACRO amount unit_cast(const amount& unit, long double new_multiplier = 1, long double new_offset = 0);
        UNIT_SYSTEM_EXPORT_MACRO amount clamp(const amount& unit, const amount& lower, const amount& upper);
        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const amount& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO amount operator "" _mol(long double val);
            UNIT_SYSTEM_EXPORT_MACRO amount operator "" _mol(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO amount operator "" _things(long double val);
            UNIT_SYSTEM_EXPORT_MACRO amount operator "" _things(unsigned long long int val);
            
            
        }
        
    }
}

namespace std{
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::amount abs(const sakurajin::unit_system::amount& unit);
}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::amount::amount(long double v, std::ratio<numerator, denumerator>, long double off): amount{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}