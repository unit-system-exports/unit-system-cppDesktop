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
        
        
        class length;
        
        

        class UNIT_SYSTEM_EXPORT_MACRO area {
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            area();
            area(const area& other) = default;

            explicit area(long double v);
            area(long double v, long double mult);
            area(long double v, long double mult, long double off);

            template<std::intmax_t numerator, std::intmax_t denumerator = 1>
            area(long double v, std::ratio<numerator, denumerator> mult, long double off = 0);

            area operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const area& other) const;
            area operator/(long double scalar) const;
            void operator/=(long double scalar);

            area operator+(const area& other) const;
            void operator+=(const area& other);

            area operator-(const area& other) const;
            void operator-=(const area& other);

            area operator-() const;

            void operator=(const area& other);

            explicit operator long double() const;

            area convert_multiplier(long double new_multiplier = 1) const;
            area convert_offset(long double new_offset = 0) const;
            area convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            #if __cplusplus >= 202002L
                int operator<=>(const area& other) const;
            #else
                bool operator<(const area& other) const;
                bool operator>(const area& other) const;
                bool operator<=(const area& other) const;
                bool operator>=(const area& other) const;
                bool operator==(const area& other) const;
                bool operator!=(const area& other) const;
            #endif

        
        
            
            length sqrt() const;
            
        
        
            length operator/(const length& other) const;
        

        
        };

        UNIT_SYSTEM_EXPORT_MACRO area unit_cast(const area& unit, long double new_multiplier = 1, long double new_offset = 0);
        UNIT_SYSTEM_EXPORT_MACRO area clamp(const area& unit, const area& lower, const area& upper);
        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const area& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _m2(long double val);
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _m2(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _are(long double val);
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _are(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _hectare(long double val);
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _hectare(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _km2(long double val);
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _km2(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _mm2(long double val);
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _mm2(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _um2(long double val);
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _um2(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _nm2(long double val);
            UNIT_SYSTEM_EXPORT_MACRO area operator "" _nm2(unsigned long long int val);
            
            
        }
        
    }
}

namespace std{
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::area abs(const sakurajin::unit_system::area& unit);
}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::area::area(long double v, std::ratio<numerator, denumerator>, long double off): area{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}