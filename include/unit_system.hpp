#pragma once

#include <cstddef>
#include <cmath>
#include <algorithm>
#include <ratio>
#include <iostream>
#include <chrono>

#ifndef UNIT_SYSTEM_EXPORT_MACRO
    #define UNIT_SYSTEM_EXPORT_MACRO
#endif

namespace sakurajin{
    namespace unit_system{
        //forward declare all units
        
        class time_si;
        class length;
        class mass;
        class temperature;
        class amount;
        class electric_current;
        class luminous_intensity;
        class energy;
        class power;
        class speed;
        class acceleration;
        class area;
        class force;
        class momentum;

        
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

            time_si convert_multiplier(long double new_multiplier = 1) const;
            time_si convert_offset(long double new_offset = 0) const;
            time_si convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

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

        
        
            
            length operator*(const speed& other) const;
            
        
        

        
        
            
            speed operator*(const acceleration& other) const;
            
        
        

        
        
            
            energy operator*(const power& other) const;
            
        
        

        
        
            
            momentum operator*(const force& other) const;
            
        
        

        
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
        

        
        class UNIT_SYSTEM_EXPORT_MACRO mass {
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            mass();
            mass(const mass& other) = default;

            explicit mass(long double v);
            mass(long double v, long double mult);
            mass(long double v, long double mult, long double off);

            template<std::intmax_t numerator, std::intmax_t denumerator = 1>
            mass(long double v, std::ratio<numerator, denumerator> mult, long double off = 0);

            mass operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const mass& other) const;
            mass operator/(long double scalar) const;
            void operator/=(long double scalar);

            mass operator+(const mass& other) const;
            void operator+=(const mass& other);

            mass operator-(const mass& other) const;
            void operator-=(const mass& other);

            mass operator-() const;

            void operator=(const mass& other);

            explicit operator long double() const;

            mass convert_multiplier(long double new_multiplier = 1) const;
            mass convert_offset(long double new_offset = 0) const;
            mass convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            #if __cplusplus >= 202002L
                int operator<=>(const mass& other) const;
            #else
                bool operator<(const mass& other) const;
                bool operator>(const mass& other) const;
                bool operator<=(const mass& other) const;
                bool operator>=(const mass& other) const;
                bool operator==(const mass& other) const;
                bool operator!=(const mass& other) const;
            #endif

        
        
            
        
        
            force operator*(const acceleration& other) const;
        

        
        
            
        
        
            momentum operator*(const speed& other) const;
        

        
        };

        UNIT_SYSTEM_EXPORT_MACRO mass unit_cast(const mass& unit, long double new_multiplier = 1, long double new_offset = 0);
        UNIT_SYSTEM_EXPORT_MACRO mass clamp(const mass& unit, const mass& lower, const mass& upper);
        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const mass& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _t(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _t(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _kg(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _kg(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _g(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _g(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _mg(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _mg(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _ug(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _ug(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _ng(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _ng(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _pg(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _pg(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _fg(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _fg(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _ag(long double val);
            UNIT_SYSTEM_EXPORT_MACRO mass operator "" _ag(unsigned long long int val);
            
            
        }
        

        
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

            amount convert_multiplier(long double new_multiplier = 1) const;
            amount convert_offset(long double new_offset = 0) const;
            amount convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

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

            luminous_intensity convert_multiplier(long double new_multiplier = 1) const;
            luminous_intensity convert_offset(long double new_offset = 0) const;
            luminous_intensity convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

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
        

        
        class UNIT_SYSTEM_EXPORT_MACRO energy {
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            energy();
            energy(const energy& other) = default;

            explicit energy(long double v);
            energy(long double v, long double mult);
            energy(long double v, long double mult, long double off);

            template<std::intmax_t numerator, std::intmax_t denumerator = 1>
            energy(long double v, std::ratio<numerator, denumerator> mult, long double off = 0);

            energy operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const energy& other) const;
            energy operator/(long double scalar) const;
            void operator/=(long double scalar);

            energy operator+(const energy& other) const;
            void operator+=(const energy& other);

            energy operator-(const energy& other) const;
            void operator-=(const energy& other);

            energy operator-() const;

            void operator=(const energy& other);

            explicit operator long double() const;

            energy convert_multiplier(long double new_multiplier = 1) const;
            energy convert_offset(long double new_offset = 0) const;
            energy convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            #if __cplusplus >= 202002L
                int operator<=>(const energy& other) const;
            #else
                bool operator<(const energy& other) const;
                bool operator>(const energy& other) const;
                bool operator<=(const energy& other) const;
                bool operator>=(const energy& other) const;
                bool operator==(const energy& other) const;
                bool operator!=(const energy& other) const;
            #endif

        
        
            
            length operator/(const force& other) const;
            
        
        
            force operator/(const length& other) const;
        

        
        
            
            time_si operator/(const power& other) const;
            
        
        
            power operator/(const time_si& other) const;
        

        
        
            
            speed operator/(const momentum& other) const;
            
        
        
            momentum operator/(const speed& other) const;
        

        
        };

        UNIT_SYSTEM_EXPORT_MACRO energy unit_cast(const energy& unit, long double new_multiplier = 1, long double new_offset = 0);
        UNIT_SYSTEM_EXPORT_MACRO energy clamp(const energy& unit, const energy& lower, const energy& upper);
        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const energy& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _J(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _J(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _Nm(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _Nm(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _eV(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _eV(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _Wh(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _Wh(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _Ws(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _Ws(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _PJ(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _PJ(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _TJ(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _TJ(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _GJ(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _GJ(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _MJ(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _MJ(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _kJ(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _kJ(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _mJ(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _mJ(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _uJ(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _uJ(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _nJ(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _nJ(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _pJ(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _pJ(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _fJ(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _fJ(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _aJ(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _aJ(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _GNm(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _GNm(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _MNm(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _MNm(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _kNm(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _kNm(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _mNm(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _mNm(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _uNm(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _uNm(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _PeV(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _PeV(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _TeV(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _TeV(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _GeV(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _GeV(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _MeV(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _MeV(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _keV(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _keV(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _meV(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _meV(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _ueV(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _ueV(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _PWh(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _PWh(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _TWh(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _TWh(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _GWh(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _GWh(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _MWh(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _MWh(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _kWh(long double val);
            UNIT_SYSTEM_EXPORT_MACRO energy operator "" _kWh(unsigned long long int val);
            
            
        }
        

        
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

            power convert_multiplier(long double new_multiplier = 1) const;
            power convert_offset(long double new_offset = 0) const;
            power convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

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

        
        
            
        
        
            energy operator*(const time_si& other) const;
        

        
        
            
            speed operator/(const force& other) const;
            
        
        
            force operator/(const speed& other) const;
        

        
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
        

        
        class UNIT_SYSTEM_EXPORT_MACRO speed {
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            speed();
            speed(const speed& other) = default;

            explicit speed(long double v);
            speed(long double v, long double mult);
            speed(long double v, long double mult, long double off);

            template<std::intmax_t numerator, std::intmax_t denumerator = 1>
            speed(long double v, std::ratio<numerator, denumerator> mult, long double off = 0);

            speed operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const speed& other) const;
            speed operator/(long double scalar) const;
            void operator/=(long double scalar);

            speed operator+(const speed& other) const;
            void operator+=(const speed& other);

            speed operator-(const speed& other) const;
            void operator-=(const speed& other);

            speed operator-() const;

            void operator=(const speed& other);

            explicit operator long double() const;

            speed convert_multiplier(long double new_multiplier = 1) const;
            speed convert_offset(long double new_offset = 0) const;
            speed convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            #if __cplusplus >= 202002L
                int operator<=>(const speed& other) const;
            #else
                bool operator<(const speed& other) const;
                bool operator>(const speed& other) const;
                bool operator<=(const speed& other) const;
                bool operator>=(const speed& other) const;
                bool operator==(const speed& other) const;
                bool operator!=(const speed& other) const;
            #endif

        
        
            
        
        
            length operator*(const time_si& other) const;
        

        
        
            
            time_si operator/(const acceleration& other) const;
            
        
        
            acceleration operator/(const time_si& other) const;
        

        
        
            
            energy operator*(const momentum& other) const;
            
        
        

        
        
            
            momentum operator*(const mass& other) const;
            
        
        

        
        
            
            power operator*(const force& other) const;
            
        
        

        
        };

        UNIT_SYSTEM_EXPORT_MACRO speed unit_cast(const speed& unit, long double new_multiplier = 1, long double new_offset = 0);
        UNIT_SYSTEM_EXPORT_MACRO speed clamp(const speed& unit, const speed& lower, const speed& upper);
        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const speed& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO speed operator "" _mps(long double val);
            UNIT_SYSTEM_EXPORT_MACRO speed operator "" _mps(unsigned long long int val);
            
            
            
            UNIT_SYSTEM_EXPORT_MACRO speed operator "" _kmph(long double val);
            UNIT_SYSTEM_EXPORT_MACRO speed operator "" _kmph(unsigned long long int val);
            
            
        }
        

        
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

            force convert_multiplier(long double new_multiplier = 1) const;
            force convert_offset(long double new_offset = 0) const;
            force convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

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

        
        
            
        
        
            energy operator*(const length& other) const;
        

        
        
            
        
        
            momentum operator*(const time_si& other) const;
        

        
        
            
            acceleration operator/(const mass& other) const;
            
        
        
            mass operator/(const acceleration& other) const;
        

        
        
            
        
        
            power operator*(const speed& other) const;
        

        
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
        

        
        class UNIT_SYSTEM_EXPORT_MACRO momentum {
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            momentum();
            momentum(const momentum& other) = default;

            explicit momentum(long double v);
            momentum(long double v, long double mult);
            momentum(long double v, long double mult, long double off);

            template<std::intmax_t numerator, std::intmax_t denumerator = 1>
            momentum(long double v, std::ratio<numerator, denumerator> mult, long double off = 0);

            momentum operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const momentum& other) const;
            momentum operator/(long double scalar) const;
            void operator/=(long double scalar);

            momentum operator+(const momentum& other) const;
            void operator+=(const momentum& other);

            momentum operator-(const momentum& other) const;
            void operator-=(const momentum& other);

            momentum operator-() const;

            void operator=(const momentum& other);

            explicit operator long double() const;

            momentum convert_multiplier(long double new_multiplier = 1) const;
            momentum convert_offset(long double new_offset = 0) const;
            momentum convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            #if __cplusplus >= 202002L
                int operator<=>(const momentum& other) const;
            #else
                bool operator<(const momentum& other) const;
                bool operator>(const momentum& other) const;
                bool operator<=(const momentum& other) const;
                bool operator>=(const momentum& other) const;
                bool operator==(const momentum& other) const;
                bool operator!=(const momentum& other) const;
            #endif

        
        
            
        
        
            energy operator*(const speed& other) const;
        

        
        
            
            time_si operator/(const force& other) const;
            
        
        
            force operator/(const time_si& other) const;
        

        
        
            
            speed operator/(const mass& other) const;
            
        
        
            mass operator/(const speed& other) const;
        

        
        };

        UNIT_SYSTEM_EXPORT_MACRO momentum unit_cast(const momentum& unit, long double new_multiplier = 1, long double new_offset = 0);
        UNIT_SYSTEM_EXPORT_MACRO momentum clamp(const momentum& unit, const momentum& lower, const momentum& upper);
        UNIT_SYSTEM_EXPORT_MACRO std::ostream& operator<<(std::ostream& os, const momentum& t);

        
        inline namespace literals{
            
            
            UNIT_SYSTEM_EXPORT_MACRO momentum operator "" _kgmps(long double val);
            UNIT_SYSTEM_EXPORT_MACRO momentum operator "" _kgmps(unsigned long long int val);
            
            
        }
        

        
    }
}


template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::time_si::time_si(long double v, std::ratio<numerator, denumerator>, long double off): time_si{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::length::length(long double v, std::ratio<numerator, denumerator>, long double off): length{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::mass::mass(long double v, std::ratio<numerator, denumerator>, long double off): mass{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::temperature::temperature(long double v, std::ratio<numerator, denumerator>, long double off): temperature{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::amount::amount(long double v, std::ratio<numerator, denumerator>, long double off): amount{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::electric_current::electric_current(long double v, std::ratio<numerator, denumerator>, long double off): electric_current{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::luminous_intensity::luminous_intensity(long double v, std::ratio<numerator, denumerator>, long double off): luminous_intensity{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::energy::energy(long double v, std::ratio<numerator, denumerator>, long double off): energy{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::power::power(long double v, std::ratio<numerator, denumerator>, long double off): power{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::speed::speed(long double v, std::ratio<numerator, denumerator>, long double off): speed{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::acceleration::acceleration(long double v, std::ratio<numerator, denumerator>, long double off): acceleration{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::area::area(long double v, std::ratio<numerator, denumerator>, long double off): area{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::force::force(long double v, std::ratio<numerator, denumerator>, long double off): force{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::momentum::momentum(long double v, std::ratio<numerator, denumerator>, long double off): momentum{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}


namespace std{
    
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::time_si abs(const sakurajin::unit_system::time_si& unit);
    
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::length abs(const sakurajin::unit_system::length& unit);
    
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::mass abs(const sakurajin::unit_system::mass& unit);
    
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::temperature abs(const sakurajin::unit_system::temperature& unit);
    
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::amount abs(const sakurajin::unit_system::amount& unit);
    
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::electric_current abs(const sakurajin::unit_system::electric_current& unit);
    
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::luminous_intensity abs(const sakurajin::unit_system::luminous_intensity& unit);
    
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::energy abs(const sakurajin::unit_system::energy& unit);
    
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::power abs(const sakurajin::unit_system::power& unit);
    
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::speed abs(const sakurajin::unit_system::speed& unit);
    
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::acceleration abs(const sakurajin::unit_system::acceleration& unit);
    
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::area abs(const sakurajin::unit_system::area& unit);
    
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::force abs(const sakurajin::unit_system::force& unit);
    
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::momentum abs(const sakurajin::unit_system::momentum& unit);
    
}


//add compatibility with std::chrono
namespace sakurajin{
    namespace unit_system{
        template<class Rep, class Period = std::ratio<1> >
        time_si unit_cast(const std::chrono::duration<Rep, Period>& other, long double new_multiplier = 1.0){
            auto t = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1,1>>>(other);
            auto retval = time_si{t.count(), 1};
            return unit_cast(retval, new_multiplier);
        }
    }
}

//add all constants
namespace sakurajin{
    namespace unit_system{
        namespace constants{
            
            const long double avogadro_constant = 6.02214076e+23;
            
            const long double waterFreezingPoint = 273.15;
            
        }
    }
}