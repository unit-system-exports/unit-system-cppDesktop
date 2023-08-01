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
        

        class UNIT_SYSTEM_EXPORT_MACRO temperature {
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            temperature();
            temperature(const temperature& other) = default;

            explicit temperature(long double v);
            temperature(long double v, long double mult);
            temperature(long double v, long double mult, long double off);

            template<std::intmax_t numerator, std::intmax_t denumerator = 1>
            temperature(long double v, std::ratio<numerator, denumerator> mult, long double off = 0);

            temperature operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const temperature& other) const;
            temperature operator/(long double scalar) const;
            void operator/=(long double scalar);

            temperature operator+(const temperature& other) const;
            void operator+=(const temperature& other);

            temperature operator-(const temperature& other) const;
            void operator-=(const temperature& other);

            temperature operator-() const;

            void operator=(const temperature& other);

            explicit operator long double() const;

            temperature convert_multiplier(long double new_multiplier = 1) const;
            temperature convert_offset(long double new_offset = 0) const;
            temperature convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            #if __cplusplus >= 202002L
                int operator<=>(const temperature& other) const;
            #else
                bool operator<(const temperature& other) const;
                bool operator>(const temperature& other) const;
                bool operator<=(const temperature& other) const;
                bool operator>=(const temperature& other) const;
                bool operator==(const temperature& other) const;
                bool operator!=(const temperature& other) const;
            #endif

        
        };

        UNIT_SYSTEM_EXPORT_MACRO temperature unit_cast(const temperature& unit, long double new_multiplier = 1, long double new_offset = 0);
        UNIT_SYSTEM_EXPORT_MACRO temperature clamp(const temperature& unit, const temperature& lower, const temperature& upper);
        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const temperature& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO temperature operator "" _K(long double val);
            UNIT_SYSTEM_EXPORT_MACRO temperature operator "" _K(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO temperature operator "" _C(long double val);
            UNIT_SYSTEM_EXPORT_MACRO temperature operator "" _C(unsigned long long int val);
            
            
        }
        
    }
}

namespace std{
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::temperature abs(const sakurajin::unit_system::temperature& unit);
}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::temperature::temperature(long double v, std::ratio<numerator, denumerator>, long double off): temperature{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}