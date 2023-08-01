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
        
        
        class force;
        
        class length;
        
        class power;
        
        class time_si;
        
        class momentum;
        
        class speed;
        
        

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
        
    }
}

namespace std{
    UNIT_SYSTEM_EXPORT_MACRO sakurajin::unit_system::energy abs(const sakurajin::unit_system::energy& unit);
}

template<std::intmax_t numerator, std::intmax_t denumerator>
sakurajin::unit_system::energy::energy(long double v, std::ratio<numerator, denumerator>, long double off): energy{
    v, static_cast<long double>(numerator)/static_cast<long double>(denumerator), off
}{}