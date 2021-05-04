#pragma once

#include <array>
#include <cmath>
#include <algorithm>

namespace sakurajin{
    namespace unit_system{
        namespace base{
            
            //The identifier should be unique for each child class
            //It is used so that only values with the same unit can be
            // compared, copied and converted.
            //0 for unit_t 
            //1 for time
            //2 for length
            //3 for mass
            //4 for temp
            //5 for amount
            //6 for el current
            //7 for lum. intensity
            //8 & 9 are reserved
            //combined units can just combine these numbers with the 0 as divide symbol
            // examples: 
            //   16 for charge (A s)
            //   201 for speed (m / s)
            //   2011 for acceleration (m / (s * s) )
            //combinations of many types might use the unused digits (8 & 9) to shorten
            // examples:
            //   8 for energy (J) instead of 322011
            //   801 for Power (W) instead of 3220111
            template <std::size_t indentifier>
            class unit_t{
            public:
                const long double multiplier = 1;
                long double value = 0;
                long double rel_error = 0.000001;
                
                unit_t(long double v);
                unit_t(long double v, long double mult);
                
                unit_t operator*(long double scalar) const;
                void operator*=(long double scalar);
                
                unit_t operator/(long double scalar) const;
                void operator/=(long double scalar);
                
                unit_t operator+(const unit_t& other) const;
                void operator+=(const unit_t& other);
                
                unit_t operator-(const unit_t& other) const;
                void operator-=(const unit_t& other);
                
                void operator=(const unit_t& other);
                
                bool operator<(const unit_t& other) const;
                bool operator>(const unit_t& other) const;
                bool operator<=(const unit_t& other) const;
                bool operator>=(const unit_t& other) const;
                bool operator==(const unit_t& other) const;
                bool operator!=(const unit_t& other) const;
                
#if __cplusplus >= 202002L
                int operator<=>(const unit_t& other) const;
#endif
                
            };
            
            //the simple unit cast
            template <std::size_t indentifier>
            unit_t<indentifier> unit_cast(const unit_t<indentifier>& unit, long double new_multiplier){
                unit_t<indentifier> retval{unit.value * (unit.multiplier / new_multiplier), new_multiplier};
                return retval;
            }
            
            //All of the constructors
            template <std::size_t indentifier>
            unit_t<indentifier>::unit_t(long double v): value{v}{};
            
            template <std::size_t indentifier>
            unit_t<indentifier>::unit_t(long double v, long double mult): multiplier{mult}, value{v}{};

            //const member functions
            template <std::size_t indentifier>
            unit_t<indentifier> unit_t<indentifier>::operator*(long double scalar) const{
                unit_t<indentifier> retval{value*scalar, multiplier};
                return retval;
            }

            template <std::size_t indentifier>
            unit_t<indentifier> unit_t<indentifier>::operator/(long double scalar) const{
                unit_t<indentifier> retval{value/scalar, multiplier};
                return retval;
            }

            template <std::size_t indentifier>
            unit_t<indentifier> unit_t<indentifier>::operator+(const unit_t<indentifier>& other) const{
                auto retval = other.multiplier == multiplier ? other : unit_cast(other,multiplier);
                retval.value += value;
                return retval;
            }

            template <std::size_t indentifier>
            unit_t<indentifier> unit_t<indentifier>::operator-(const unit_t<indentifier>& other) const{
                auto retval = other.multiplier == multiplier ? other : unit_cast(other,multiplier);
                retval.value = value - retval.value;
                return retval;
            }

            //comparison operators
            template <std::size_t indentifier>
            bool unit_t<indentifier>::operator<(const unit_t<indentifier>& other) const{
                const auto retval = other.multiplier == multiplier ? other : unit_cast(other,multiplier);
                return value < retval.value;
            }

            template <std::size_t indentifier>
            bool unit_t<indentifier>::operator>(const unit_t<indentifier>& other) const{
                const auto retval = other.multiplier == multiplier ? other : unit_cast(other,multiplier);
                return value > retval.value;
            }

            template <std::size_t indentifier>
            bool unit_t<indentifier>::operator<=(const unit_t<indentifier>& other) const{
                const auto retval = other.multiplier == multiplier ? other : unit_cast(other,multiplier);
                return value <= retval.value;
            }

            template <std::size_t indentifier>
            bool unit_t<indentifier>::operator>=(const unit_t<indentifier>& other) const{
                const auto retval = other.multiplier == multiplier ? other : unit_cast(other,multiplier);
                return value >= retval.value;
            }

            template <std::size_t indentifier>
            bool unit_t<indentifier>::operator==(const unit_t<indentifier>& other) const{
                const auto retval = other.multiplier == multiplier ? other : unit_cast(other,multiplier);
                auto delta = value-retval.value;
                auto epsilon = 0.000001 * std::max(std::abs(value), std::abs(retval.value));
                return std::abs(delta) < epsilon;
            }

            template <std::size_t indentifier>
            bool unit_t<indentifier>::operator!=(const unit_t<indentifier>& other) const{
                return ! (*this == other);
            }

            #if __cplusplus >= 202002L
            template <std::size_t indentifier>
            int unit_t<indentifier>::operator<=>(const unit_t<indentifier>& other) const{
                const auto retval = other.multiplier == multiplier ? other : unit_cast(other,multiplier);
                if(*this < retval){
                    return -1;
                }
                
                if(*this > retval){
                    return 1;
                }
                
                return 0;
            }
            #endif

            //non const member functions
            template <std::size_t indentifier>
            void unit_t<indentifier>::operator*=(long double scalar){
                value*=scalar;
            }

            template <std::size_t indentifier>
            void unit_t<indentifier>::operator/=(long double scalar){
                value/=scalar;
            }

            template <std::size_t indentifier>
            void unit_t<indentifier>::operator+=(const unit_t<indentifier>& other){
                const auto otherVal = other.multiplier == multiplier ? other : unit_cast(other,multiplier);
                value += otherVal.value;
            }

            template <std::size_t indentifier>
            void unit_t<indentifier>::operator-=(const unit_t<indentifier>& other){
                const auto otherVal = other.multiplier == multiplier ? other : unit_cast(other,multiplier);
                value -= otherVal.value;
            }

            template <std::size_t indentifier>
            void unit_t<indentifier>::operator=(const unit_t<indentifier>& other){
                const auto otherVal = other.multiplier == multiplier ? other : unit_cast(other,multiplier);
                value = otherVal.value;
            }
            
        }
    }
}


