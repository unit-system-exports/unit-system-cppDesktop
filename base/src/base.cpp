#include "base.hpp"

using namespace sakurajin::unit_system::base;
    
#if __has_include(<iostream>)

    std::ostream& ::sakurajin::unit_system::base::operator<<(std::ostream& os, const ::sakurajin::unit_system::base::amount& t){
        auto t1 = sakurajin::unit_system::unit_cast(t,1);
        return os << t1.value << " things";
    }

    std::ostream& ::sakurajin::unit_system::base::operator<<(std::ostream& os, const ::sakurajin::unit_system::base::electric_current& I){
        auto I1 = ::sakurajin::unit_system::unit_cast(I,1);
        return os << I1.value << " Ampere";
    }
    
    std::ostream& ::sakurajin::unit_system::base::operator<<(std::ostream& os, const ::sakurajin::unit_system::base::length& s){
        auto s1 = sakurajin::unit_system::unit_cast(s,1);
        return os << s1.value << " meter";
    }

    std::ostream& ::sakurajin::unit_system::base::operator<<(std::ostream& os, const luminous_intensity& J){
        auto J1 = sakurajin::unit_system::unit_cast(J,1);
        return os << J1.value << " candela";
    }

    std::ostream& ::sakurajin::unit_system::base::operator<<(std::ostream& os, const mass& s){
        auto s1 = sakurajin::unit_system::unit_cast(s,1);
        return os << s1.value << " kilogram";
    }

    std::ostream& ::sakurajin::unit_system::base::operator<<(std::ostream& os, const temperature& J){
        auto J1 = sakurajin::unit_system::unit_cast(J,1,0);
        return os << J1.value << " Kelvin";
    }

    std::ostream& sakurajin::unit_system::base::operator<<(std::ostream& os, const time_si& t){
        auto t1 = sakurajin::unit_system::unit_cast(t,1,0);
        return os << t1.value << " seconds";
    }

#endif
