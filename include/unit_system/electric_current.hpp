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
        

        class UNIT_SYSTEM_EXPORT_MACRO electric_current {
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            electric_current();
            electric_current(const electric_current& other) = default;

            explicit electric_current(long double v);
            electric_current(long double v, long double mult);
            electric_current(long double v, long double mult, long double off);

            template<std::intmax_t numerator, std::intmax_t denumerator = 1>
            electric_current(long double v, std::ratio<numerator, denumerator> mult, long double off = 0);

            electric_current operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const electric_current& other) const;
            electric_current operator/(long double scalar) const;
            void operator/=(long double scalar);

            electric_current operator+(const electric_current& other) const;
            void operator+=(const electric_current& other);

            electric_current operator-(const electric_current& other) const;
            void operator-=(const electric_current& other);

            electric_current operator-() const;

            void operator=(const electric_current& other);

            explicit operator long double() const;

            electric_current convert_multiplier(long double new_multiplier = 1) const;
            electric_current convert_offset(long double new_offset = 0) const;
            electric_current convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            #if __cplusplus >= 202002L
                int operator<=>(const electric_current& other) const;
            #else
                bool operator<(const electric_current& other) const;
                bool operator>(const electric_current& other) const;
                bool operator<=(const electric_current& other) const;
                bool operator>=(const electric_current& other) const;
                bool operator==(const electric_current& other) const;
                bool operator!=(const electric_current& other) const;
            #endif

        
        };

        UNIT_SYSTEM_EXPORT_MACRO electric_current unit_cast(const electric_current& unit, long double new_multiplier = 1, long double new_offset = 0);
        UNIT_SYSTEM_EXPORT_MACRO electric_current clamp(const electric_current& unit, const electric_current& lower, const electric_current& upper);
        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const electric_current& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _A(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _A(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _PA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _PA(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _TA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _TA(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _GA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _GA(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _MA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _MA(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _kA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _kA(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _mA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _mA(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _uA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _uA(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _nA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _nA(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _pA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _pA(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _fA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _fA(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _aA(long double val);
            UNIT_SYSTEM_EXPORT_MACRO electric_current operator "" _aA(unsigned long long int val);
            
            
        }
        
    }
}

namespace std{
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::electric_current abs(const sakurajin::unit_system::electric_current& unit);
}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::electric_current::electric_current(long double v, std::ratio<numerator, denumerator>, long double off): electric_current{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}