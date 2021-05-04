#pragma once

namespace sakurajin{
    namespace unit_system{
        namespace base{
            class unit_t{
            public:
                const double multiplier = 1;
                double value = 0;
                
                unit_t(double v);
                unit_t(double v, double mult);
                
                unit_t operator*(double scalar) const;
                void operator*=(double scalar);
                
                unit_t operator/(double scalar) const;
                void operator/=(double scalar);
                
                unit_t operator+(const unit_t& other) const;
                void operator+=(const unit_t& other);
                
                unit_t operator-(const unit_t& other) const;
                void operator-=(const unit_t& other);
                
                void operator=(const unit_t& other);
                
            };
            
            unit_t unit_cast(const unit_t& unit, double new_multiplier);
        }
    }
}


