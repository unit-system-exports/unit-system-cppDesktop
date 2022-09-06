#pragma once

#if __has_include(<cstddef>)
    #include <cstddef>
#else
    namespace std{
        using size_t = unsigned int;
    }
#endif

#if __has_include(<cmath>)
    #include <cmath>
#else
    #ifdef abs
        #undef abs
    #endif
    
    namespace std{
        template <typename T>
        T abs(T var){
            return var > 0 ? var : -var;
        }
    }
#endif

#if __has_include(<algorithm>)
    #include <algorithm>
#else
    #ifdef max
        #undef max
    #endif
    
    namespace std{
        
        template <typename T>
        T max(T v1, T v2){
            return v1 > v2 ? v1 : v2;
        }
    }
#endif



namespace sakurajin{
    namespace unit_system{
            
        //The identifier should be unique for each child class
        //It is used so that only values with the same unit can be
        // compared, copied and converted.
        //  0 for unit_t 
        //  1 for time_si
        //  2 for length
        //  3 for mass
        //  4 for temp
        //  5 for amount
        //  6 for el current
        //  7 for lum. intensity
        //
        //  8 for energy (not part of base but part of common)
        //
        //  9 is reserved
        //
        //combined units can just combine these numbers with the 0 as divide symbol
        // examples: 
        //   16 for charge (A s)
        //   201 for speed (m / s)
        //   2011 for acceleration (m / (s * s) )
        //combinations of many types might use the reserved digit (9) to shorten
        //if common is not used, you may also use the digit 8 to shorten the identifier
        // examples:
        //   8 for energy (J) instead of 322011
        //   801 for Power (W) instead of 3220111
        template <std::size_t identifier>
        class unit_t{
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;
            
            unit_t();
            unit_t(const unit_t<identifier>& other) = default;

            explicit unit_t(long double v);
            unit_t(long double v, long double mult);
            unit_t(long double v, long double mult, long double off);
            
            unit_t operator*(long double scalar) const;
            void operator*=(long double scalar);
            
            long double operator/(const unit_t<identifier>& other) const;
            unit_t operator/(long double scalar) const;
            void operator/=(long double scalar);
            
            unit_t operator+(const unit_t<identifier>& other) const;
            void operator+=(const unit_t<identifier>& other);
            
            unit_t operator-(const unit_t<identifier>& other) const;
            void operator-=(const unit_t<identifier>& other);
            
            unit_t operator-() const;
            
            void operator=(const unit_t<identifier>& other);
                        
            #if __cplusplus >= 202002L
                int operator<=>(const unit_t<identifier>& other) const;
            #else
                bool operator<(const unit_t<identifier>& other) const;
                bool operator>(const unit_t<identifier>& other) const;
                bool operator<=(const unit_t<identifier>& other) const;
                bool operator>=(const unit_t<identifier>& other) const;
                bool operator==(const unit_t<identifier>& other) const;
                bool operator!=(const unit_t<identifier>& other) const;
            #endif
            
        };
  
        //changes multiplier and offset
        //This is needed primarily for temperatures
        template <std::size_t identifier>
        unit_t<identifier> unit_cast(const unit_t<identifier>& unit, long double new_multiplier = 1, long double new_offset = 0){
            auto valBase0 = (unit.value + unit.offset) * unit.multiplier;
            unit_t<identifier> retval{valBase0/new_multiplier-new_offset, new_multiplier, new_offset};
            return retval;
        }
        
        template <std::size_t identifier>
        unit_t<identifier> clamp(const unit_t<identifier>& unit, const unit_t<identifier>& lower, const unit_t<identifier>& upper){
            
            auto _lower = unit_cast(lower, unit.multiplier, unit.offset);
            auto _upper = unit_cast(upper, unit.multiplier, unit.offset);
            
            auto val = unit.value > _lower.value ? ( unit.value < _upper.value ? unit.value : _upper.value ) : _lower.value;
            
            return unit_t<identifier>{val, unit.multiplier, unit.offset};
        }
        
        template <std::size_t identifier>
        unit_t<identifier> abs(const unit_t<identifier>& unit){
            return unit.value < 0 ? -unit : unit;
        }
        
        //All of the constructors
        template <std::size_t identifier>
        unit_t<identifier>::unit_t(): unit_t{0.0}{};
        
        template <std::size_t identifier>
        unit_t<identifier>::unit_t(long double v): unit_t{v,1,0}{};
        
        template <std::size_t identifier>
        unit_t<identifier>::unit_t(long double v, long double mult): unit_t{v,mult,0}{};
        
        template <std::size_t identifier>
        unit_t<identifier>::unit_t(long double v, long double mult, long double off): multiplier{mult}, value{v}, offset{off}{};

        //const member functions
        template <std::size_t identifier>
        unit_t<identifier> unit_t<identifier>::operator*(long double scalar) const{
            unit_t<identifier> retval{value*scalar, multiplier, offset};
            return retval;
        }
        
        template <std::size_t identifier>
        unit_t<identifier> operator*(long double scalar, const unit_t<identifier>& val){
            return {val.value*scalar, val.multiplier, val.offset};
        }

        template <std::size_t identifier>
        long double unit_t<identifier>::operator/(const unit_t<identifier>& other) const{
            auto otherVal = unit_cast(other, multiplier, offset);
            return value/otherVal.value;
        }

        template <std::size_t identifier>
        unit_t<identifier> unit_t<identifier>::operator/(long double scalar) const{
            unit_t<identifier> retval{value/scalar, multiplier, offset};
            return retval;
        }

        template <std::size_t identifier>
        unit_t<identifier> unit_t<identifier>::operator+(const unit_t<identifier>& other) const{
            auto retval = sakurajin::unit_system::unit_cast(other, multiplier,offset);
            retval.value += value;
            return retval;
        }

        template <std::size_t identifier>
        unit_t<identifier> unit_t<identifier>::operator-(const unit_t<identifier>& other) const{
            auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
            retval.value = value - retval.value;
            return retval;
        }
        
        template <std::size_t identifier>
        unit_t<identifier> unit_t<identifier>::operator-() const{
            return unit_t<identifier>{-value,multiplier,offset};
        }

        //comparison operators

        #if __cplusplus >= 202002L
            template <std::size_t identifier>
            int unit_t<identifier>::operator<=>(const unit_t<identifier>& other) const{
                const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
                if(*this < retval){
                    return -1;
                }
                
                if(*this > retval){
                    return 1;
                }
                
                return 0;
            }
        #else
            template <std::size_t identifier>
            bool unit_t<identifier>::operator<(const unit_t<identifier>& other) const{
                const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
                return value < retval.value;
            }

            template <std::size_t identifier>
            bool unit_t<identifier>::operator>(const unit_t<identifier>& other) const{
                const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
                return value > retval.value;
            }

            template <std::size_t identifier>
            bool unit_t<identifier>::operator<=(const unit_t<identifier>& other) const{
                const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
                return value <= retval.value;
            }

            template <std::size_t identifier>
            bool unit_t<identifier>::operator>=(const unit_t<identifier>& other) const{
                const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
                return value >= retval.value;
            }

            template <std::size_t identifier>
            bool unit_t<identifier>::operator==(const unit_t<identifier>& other) const{
                const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
                auto delta = value-retval.value;
                auto epsilon = 0.000001 * std::max(std::abs(value), std::abs(retval.value));
                return std::abs(delta) < epsilon;
            }

            template <std::size_t identifier>
            bool unit_t<identifier>::operator!=(const unit_t<identifier>& other) const{
                return ! (*this == other);
            }
        #endif

        //non const member functions
        template <std::size_t identifier>
        void unit_t<identifier>::operator*=(long double scalar){
            value*=scalar;
        }

        template <std::size_t identifier>
        void unit_t<identifier>::operator/=(long double scalar){
            value/=scalar;
        }

        template <std::size_t identifier>
        void unit_t<identifier>::operator+=(const unit_t<identifier>& other){
            const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
            value += otherVal.value;
        }

        template <std::size_t identifier>
        void unit_t<identifier>::operator-=(const unit_t<identifier>& other){
            const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
            value -= otherVal.value;
        }

        template <std::size_t identifier>
        void unit_t<identifier>::operator=(const unit_t<identifier>& other){
            const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
            value = otherVal.value;
        }
        
    }
}


