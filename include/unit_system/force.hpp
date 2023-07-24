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
        class UNIT_SYSTEM_EXPORT_MACRO force {
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            force();
            force(const force& other) = default;

            explicit force(long double v);
            force(long double v, long double mult);
            force(long double v, long double mult, long double off);

            template<std::intmax_t numerator, std::intmax_t denumerator = 1>
            force(long double v, std::ratio<numerator, denumerator> mult, long double off = 0);

            force operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const force& other) const;
            force operator/(long double scalar) const;
            void operator/=(long double scalar);

            force operator+(const force& other) const;
            void operator+=(const force& other);

            force operator-(const force& other) const;
            void operator-=(const force& other);

            force operator-() const;

            void operator=(const force& other);

            explicit operator long double() const;

            #if __cplusplus >= 202002L
                int operator<=>(const force& other) const;
            #else
                bool operator<(const force& other) const;
                bool operator>(const force& other) const;
                bool operator<=(const force& other) const;
                bool operator>=(const force& other) const;
                bool operator==(const force& other) const;
                bool operator!=(const force& other) const;
            #endif
        };

        UNIT_SYSTEM_EXPORT_MACRO force unit_cast(const force& unit, long double new_multiplier = 1, long double new_offset = 0);
        UNIT_SYSTEM_EXPORT_MACRO force clamp(const force& unit, const force& lower, const force& upper);
        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const force& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _N(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _N(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _PN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _PN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _TN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _TN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _GN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _GN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _MN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _MN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _kN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _kN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _mN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _mN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _uN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _uN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _nN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _nN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _pN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _pN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _fN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _fN(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _aN(long double val);
            UNIT_SYSTEM_EXPORT_MACRO force operator "" _aN(unsigned long long int val);
            
            
        }
        
    }
}

namespace std{
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::force abs(const sakurajin::unit_system::force& unit);
}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::force::force(long double v, std::ratio<numerator, denumerator>, long double off): force{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}