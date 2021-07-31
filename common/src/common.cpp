#include "common.hpp"

#if __has_include(<iostream>)

    using namespace sakurajin::unit_system;

    std::ostream& common::operator<<(std::ostream& os, const common::acceleration& a){
        auto a1 = sakurajin::unit_system::unit_cast(a,1);
        return os << a1.value << " meter per second^2";
    }

    std::ostream& common::operator<<(std::ostream& os, const common::energy& p){
        auto p1 = sakurajin::unit_system::unit_cast(p,1);
        return os << p1.value << " Joules";
    }

    std::ostream& common::operator<<(std::ostream& os, const common::force& p){
        auto p1 = sakurajin::unit_system::unit_cast(p,1);
        return os << p1.value << " Newton";
    }

    std::ostream& common::operator<<(std::ostream& os, const common::momentum& p){
        auto p1 = sakurajin::unit_system::unit_cast(p,1);
        return os << p1.value << " kilogram * meter per second";
    }

    std::ostream& common::operator<<(std::ostream& os, const common::power& p){
        auto p1 = sakurajin::unit_system::unit_cast(p,1);
        return os << p1.value << " Watts";
    }

    std::ostream& common::operator<<(std::ostream& os, const common::speed& v){
        auto v1 = sakurajin::unit_system::unit_cast(v,1);
        return os << v1.value << " meter per second";
    }

#endif
