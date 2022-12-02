#pragma once

#ifndef UNIT_SYSTEM_UNIT_TYPE_TEMPLATE
#error "do not directly include the std workarounds!"
#endif

#ifndef UNIT_SYSTEM_NO_STD
    #include <cstddef>
    #include <cmath>
    #include <algorithm>
    #include <ratio>
#else
    #ifdef abs
        #undef abs
    #endif

    #ifdef max
        #undef max
    #endif

    namespace std{
        using size_t = unsigned long long;
        using intmax_t = long long;
        
        template <typename T>
        T abs(T var){
            return var > 0 ? var : -var;
        }
        
        template <typename T>
        T max(T v1, T v2){
            return v1 > v2 ? v1 : v2;
        }
        
        template <intmax_t num, intmax_t den = 1>
        class ratio {
        public:
            typedef ratio<num, den> type;
            static constexpr intmax_t n = num;
            static constexpr intmax_t d = den;
        };
        
        typedef ratio<1,       1000000000000000000> atto;
        typedef ratio<1,          1000000000000000> femto;
        typedef ratio<1,             1000000000000> pico;
        typedef ratio<1,                1000000000> nano;
        typedef ratio<1,                   1000000> micro;
        typedef ratio<1,                      1000> milli;
        typedef ratio<1,                       100> centi;
        typedef ratio<1,                        10> deci;
        typedef ratio<                       10, 1> deca;
        typedef ratio<                      100, 1> hecto;
        typedef ratio<                     1000, 1> kilo;
        typedef ratio<                  1000000, 1> mega;
        typedef ratio<               1000000000, 1> giga;
        typedef ratio<            1000000000000, 1> tera;
        typedef ratio<         1000000000000000, 1> peta;
        typedef ratio<      1000000000000000000, 1> exa;
  
    }

#endif
