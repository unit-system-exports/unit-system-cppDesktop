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
        
        
        class speed;
        
        class time_si;
        
        class area;
        
        class force;
        
        class energy;
        
        

        class UNIT_SYSTEM_EXPORT_MACRO length {
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            length();
            length(const length& other) = default;

            explicit length(long double v);
            length(long double v, long double mult);
            length(long double v, long double mult, long double off);

            template<std::intmax_t numerator, std::intmax_t denumerator = 1>
            length(long double v, std::ratio<numerator, denumerator> mult, long double off = 0);

            length operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const length& other) const;
            length operator/(long double scalar) const;
            void operator/=(long double scalar);

            length operator+(const length& other) const;
            void operator+=(const length& other);

            length operator-(const length& other) const;
            void operator-=(const length& other);

            length operator-() const;

            void operator=(const length& other);

            explicit operator long double() const;

            length convert_multiplier(long double new_multiplier = 1) const;
            length convert_offset(long double new_offset = 0) const;
            length convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            #if __cplusplus >= 202002L
                int operator<=>(const length& other) const;
            #else
                bool operator<(const length& other) const;
                bool operator>(const length& other) const;
                bool operator<=(const length& other) const;
                bool operator>=(const length& other) const;
                bool operator==(const length& other) const;
                bool operator!=(const length& other) const;
            #endif

        
        
            
            time_si operator/(const speed& other) const;
            
        
        
            speed operator/(const time_si& other) const;
        

        
        
            
            area square() const;
            
        
        
            area operator*(const length& other) const;
        

        
        
            
            energy operator*(const force& other) const;
            
        
        

        
        };

        UNIT_SYSTEM_EXPORT_MACRO length unit_cast(const length& unit, long double new_multiplier = 1, long double new_offset = 0);
        UNIT_SYSTEM_EXPORT_MACRO length clamp(const length& unit, const length& lower, const length& upper);
        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const length& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _m(long double val);
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _m(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _km(long double val);
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _km(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _dm(long double val);
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _dm(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _cm(long double val);
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _cm(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _mm(long double val);
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _mm(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _um(long double val);
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _um(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _nm(long double val);
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _nm(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _pm(long double val);
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _pm(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _fm(long double val);
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _fm(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _am(long double val);
            UNIT_SYSTEM_EXPORT_MACRO length operator "" _am(unsigned long long int val);
            
            
        }
        
    }
}

namespace std{
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::length abs(const sakurajin::unit_system::length& unit);
}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::length::length(long double v, std::ratio<numerator, denumerator>, long double off): length{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}