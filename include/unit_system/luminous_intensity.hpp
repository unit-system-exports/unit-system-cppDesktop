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
        class UNIT_SYSTEM_EXPORT_MACRO luminous_intensity {
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            luminous_intensity();
            luminous_intensity(const luminous_intensity& other) = default;

            explicit luminous_intensity(long double v);
            luminous_intensity(long double v, long double mult);
            luminous_intensity(long double v, long double mult, long double off);

            template<std::intmax_t numerator, std::intmax_t denumerator = 1>
            luminous_intensity(long double v, std::ratio<numerator, denumerator> mult, long double off = 0);

            luminous_intensity operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const luminous_intensity& other) const;
            luminous_intensity operator/(long double scalar) const;
            void operator/=(long double scalar);

            luminous_intensity operator+(const luminous_intensity& other) const;
            void operator+=(const luminous_intensity& other);

            luminous_intensity operator-(const luminous_intensity& other) const;
            void operator-=(const luminous_intensity& other);

            luminous_intensity operator-() const;

            void operator=(const luminous_intensity& other);

            explicit operator long double() const;

            #if __cplusplus >= 202002L
                int operator<=>(const luminous_intensity& other) const;
            #else
                bool operator<(const luminous_intensity& other) const;
                bool operator>(const luminous_intensity& other) const;
                bool operator<=(const luminous_intensity& other) const;
                bool operator>=(const luminous_intensity& other) const;
                bool operator==(const luminous_intensity& other) const;
                bool operator!=(const luminous_intensity& other) const;
            #endif
        };

        UNIT_SYSTEM_EXPORT_MACRO luminous_intensity unit_cast(const luminous_intensity& unit, long double new_multiplier = 1, long double new_offset = 0);
        UNIT_SYSTEM_EXPORT_MACRO luminous_intensity clamp(const luminous_intensity& unit, const luminous_intensity& lower, const luminous_intensity& upper);
        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const luminous_intensity& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO luminous_intensity operator "" _cd(long double val);
            UNIT_SYSTEM_EXPORT_MACRO luminous_intensity operator "" _cd(unsigned long long int val);
            
            
        }
        
    }
}

namespace std{
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::luminous_intensity abs(const sakurajin::unit_system::luminous_intensity& unit);
}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::luminous_intensity::luminous_intensity(long double v, std::ratio<numerator, denumerator>, long double off): luminous_intensity{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}