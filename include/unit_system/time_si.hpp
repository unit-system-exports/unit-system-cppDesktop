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
        class UNIT_SYSTEM_EXPORT_MACRO time_si {
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            time_si();
            time_si(const time_si& other) = default;

            explicit time_si(long double v);
            time_si(long double v, long double mult);
            time_si(long double v, long double mult, long double off);

            template<std::intmax_t numerator, std::intmax_t denumerator = 1>
            time_si(long double v, std::ratio<numerator, denumerator> mult, long double off = 0);

            time_si operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const time_si& other) const;
            time_si operator/(long double scalar) const;
            void operator/=(long double scalar);

            time_si operator+(const time_si& other) const;
            void operator+=(const time_si& other);

            time_si operator-(const time_si& other) const;
            void operator-=(const time_si& other);

            time_si operator-() const;

            void operator=(const time_si& other);

            explicit operator long double() const;

            #if __cplusplus >= 202002L
                int operator<=>(const time_si& other) const;
            #else
                bool operator<(const time_si& other) const;
                bool operator>(const time_si& other) const;
                bool operator<=(const time_si& other) const;
                bool operator>=(const time_si& other) const;
                bool operator==(const time_si& other) const;
                bool operator!=(const time_si& other) const;
            #endif
        };

        UNIT_SYSTEM_EXPORT_MACRO time_si unit_cast(const time_si& unit, long double new_multiplier = 1, long double new_offset = 0);
        UNIT_SYSTEM_EXPORT_MACRO time_si clamp(const time_si& unit, const time_si& lower, const time_si& upper);
        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const time_si& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _a(long double val);
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _a(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _d(long double val);
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _d(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _h(long double val);
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _h(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _minute(long double val);
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _minute(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _s(long double val);
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _s(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _ms(long double val);
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _ms(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _us(long double val);
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _us(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _ns(long double val);
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _ns(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _ps(long double val);
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _ps(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _fs(long double val);
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _fs(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _as(long double val);
            UNIT_SYSTEM_EXPORT_MACRO time_si operator "" _as(unsigned long long int val);
            
            
        }
        
    }
}

namespace std{
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::time_si abs(const sakurajin::unit_system::time_si& unit);
}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::time_si::time_si(long double v, std::ratio<numerator, denumerator>, long double off): time_si{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}