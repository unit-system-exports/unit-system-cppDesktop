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
        
        
        class time_si;
        
        class speed;
        
        class mass;
        
        class force;
        
        

        class UNIT_SYSTEM_EXPORT_MACRO acceleration {
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            acceleration();
            acceleration(const acceleration& other) = default;

            explicit acceleration(long double v);
            acceleration(long double v, long double mult);
            acceleration(long double v, long double mult, long double off);

            template<std::intmax_t numerator, std::intmax_t denumerator = 1>
            acceleration(long double v, std::ratio<numerator, denumerator> mult, long double off = 0);

            acceleration operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const acceleration& other) const;
            acceleration operator/(long double scalar) const;
            void operator/=(long double scalar);

            acceleration operator+(const acceleration& other) const;
            void operator+=(const acceleration& other);

            acceleration operator-(const acceleration& other) const;
            void operator-=(const acceleration& other);

            acceleration operator-() const;

            void operator=(const acceleration& other);

            explicit operator long double() const;

            acceleration convert_multiplier(long double new_multiplier = 1) const;
            acceleration convert_offset(long double new_offset = 0) const;
            acceleration convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            #if __cplusplus >= 202002L
                int operator<=>(const acceleration& other) const;
            #else
                bool operator<(const acceleration& other) const;
                bool operator>(const acceleration& other) const;
                bool operator<=(const acceleration& other) const;
                bool operator>=(const acceleration& other) const;
                bool operator==(const acceleration& other) const;
                bool operator!=(const acceleration& other) const;
            #endif

        
        
            
        
        
            speed operator*(const time_si& other) const;
        

        
        
            
            force operator*(const mass& other) const;
            
        
        

        
        };

        UNIT_SYSTEM_EXPORT_MACRO acceleration unit_cast(const acceleration& unit, long double new_multiplier = 1, long double new_offset = 0);
        UNIT_SYSTEM_EXPORT_MACRO acceleration clamp(const acceleration& unit, const acceleration& lower, const acceleration& upper);
        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const acceleration& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO acceleration operator "" _mps2(long double val);
            UNIT_SYSTEM_EXPORT_MACRO acceleration operator "" _mps2(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO acceleration operator "" _G(long double val);
            UNIT_SYSTEM_EXPORT_MACRO acceleration operator "" _G(unsigned long long int val);
            
            
        }
        
    }
}

namespace std{
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::acceleration abs(const sakurajin::unit_system::acceleration& unit);
}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::acceleration::acceleration(long double v, std::ratio<numerator, denumerator>, long double off): acceleration{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}