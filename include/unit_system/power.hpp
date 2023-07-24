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
        class UNIT_SYSTEM_EXPORT_MACRO power {
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            power();
            power(const power& other) = default;

            explicit power(long double v);
            power(long double v, long double mult);
            power(long double v, long double mult, long double off);

            template<std::intmax_t numerator, std::intmax_t denumerator = 1>
            power(long double v, std::ratio<numerator, denumerator> mult, long double off = 0);

            power operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const power& other) const;
            power operator/(long double scalar) const;
            void operator/=(long double scalar);

            power operator+(const power& other) const;
            void operator+=(const power& other);

            power operator-(const power& other) const;
            void operator-=(const power& other);

            power operator-() const;

            void operator=(const power& other);

            explicit operator long double() const;

            #if __cplusplus >= 202002L
                int operator<=>(const power& other) const;
            #else
                bool operator<(const power& other) const;
                bool operator>(const power& other) const;
                bool operator<=(const power& other) const;
                bool operator>=(const power& other) const;
                bool operator==(const power& other) const;
                bool operator!=(const power& other) const;
            #endif
        };

        UNIT_SYSTEM_EXPORT_MACRO power unit_cast(const power& unit, long double new_multiplier = 1, long double new_offset = 0);
        UNIT_SYSTEM_EXPORT_MACRO power clamp(const power& unit, const power& lower, const power& upper);
        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const power& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _W(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _W(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _PW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _PW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _TW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _TW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _GW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _GW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _MW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _MW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _kW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _kW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _mW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _mW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _uW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _uW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _nW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _nW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _pW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _pW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _fW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _fW(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _aW(long double val);
            UNIT_SYSTEM_EXPORT_MACRO power operator "" _aW(unsigned long long int val);
            
            
        }
        
    }
}

namespace std{
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::power abs(const sakurajin::unit_system::power& unit);
}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::power::power(long double v, std::ratio<numerator, denumerator>, long double off): power{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}