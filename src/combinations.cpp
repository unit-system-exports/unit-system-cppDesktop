
#include "unit_system/combinations.hpp"



sakurajin::unit_system::length sakurajin::unit_system::operator*(const sakurajin::unit_system::speed& v1, const sakurajin::unit_system::time_si& v2){
    speed _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    time_si _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return length{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::time_si sakurajin::unit_system::operator/(const sakurajin::unit_system::length& v1, const sakurajin::unit_system::speed& v2){
    length _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    speed _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return time_si{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::length sakurajin::unit_system::operator*(const sakurajin::unit_system::time_si& v1, const sakurajin::unit_system::speed& v2){
    time_si _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    speed _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return length{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::speed sakurajin::unit_system::operator/(const sakurajin::unit_system::length& v1, const sakurajin::unit_system::time_si& v2){
    length _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    time_si _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return speed{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::speed sakurajin::unit_system::operator*(const sakurajin::unit_system::acceleration& v1, const sakurajin::unit_system::time_si& v2){
    acceleration _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    time_si _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return speed{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::time_si sakurajin::unit_system::operator/(const sakurajin::unit_system::speed& v1, const sakurajin::unit_system::acceleration& v2){
    speed _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    acceleration _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return time_si{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::speed sakurajin::unit_system::operator*(const sakurajin::unit_system::time_si& v1, const sakurajin::unit_system::acceleration& v2){
    time_si _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    acceleration _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return speed{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::acceleration sakurajin::unit_system::operator/(const sakurajin::unit_system::speed& v1, const sakurajin::unit_system::time_si& v2){
    speed _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    time_si _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return acceleration{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::area sakurajin::unit_system::operator*(const sakurajin::unit_system::length& v1, const sakurajin::unit_system::length& v2){
    length _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    length _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return area{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::length sakurajin::unit_system::operator/(const sakurajin::unit_system::area& v1, const sakurajin::unit_system::length& v2){
    area _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    length _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return length{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::area sakurajin::unit_system::square(const sakurajin::unit_system::length& v1){
    return v1*v1;
}


sakurajin::unit_system::energy sakurajin::unit_system::operator*(const sakurajin::unit_system::force& v1, const sakurajin::unit_system::length& v2){
    force _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    length _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return energy{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::length sakurajin::unit_system::operator/(const sakurajin::unit_system::energy& v1, const sakurajin::unit_system::force& v2){
    energy _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    force _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return length{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::energy sakurajin::unit_system::operator*(const sakurajin::unit_system::length& v1, const sakurajin::unit_system::force& v2){
    length _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    force _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return energy{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::force sakurajin::unit_system::operator/(const sakurajin::unit_system::energy& v1, const sakurajin::unit_system::length& v2){
    energy _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    length _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return force{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::energy sakurajin::unit_system::operator*(const sakurajin::unit_system::power& v1, const sakurajin::unit_system::time_si& v2){
    power _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    time_si _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return energy{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::time_si sakurajin::unit_system::operator/(const sakurajin::unit_system::energy& v1, const sakurajin::unit_system::power& v2){
    energy _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    power _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return time_si{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::energy sakurajin::unit_system::operator*(const sakurajin::unit_system::time_si& v1, const sakurajin::unit_system::power& v2){
    time_si _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    power _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return energy{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::power sakurajin::unit_system::operator/(const sakurajin::unit_system::energy& v1, const sakurajin::unit_system::time_si& v2){
    energy _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    time_si _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return power{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::energy sakurajin::unit_system::operator*(const sakurajin::unit_system::momentum& v1, const sakurajin::unit_system::speed& v2){
    momentum _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    speed _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return energy{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::speed sakurajin::unit_system::operator/(const sakurajin::unit_system::energy& v1, const sakurajin::unit_system::momentum& v2){
    energy _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    momentum _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return speed{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::energy sakurajin::unit_system::operator*(const sakurajin::unit_system::speed& v1, const sakurajin::unit_system::momentum& v2){
    speed _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    momentum _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return energy{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::momentum sakurajin::unit_system::operator/(const sakurajin::unit_system::energy& v1, const sakurajin::unit_system::speed& v2){
    energy _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    speed _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return momentum{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::momentum sakurajin::unit_system::operator*(const sakurajin::unit_system::force& v1, const sakurajin::unit_system::time_si& v2){
    force _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    time_si _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return momentum{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::time_si sakurajin::unit_system::operator/(const sakurajin::unit_system::momentum& v1, const sakurajin::unit_system::force& v2){
    momentum _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    force _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return time_si{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::momentum sakurajin::unit_system::operator*(const sakurajin::unit_system::time_si& v1, const sakurajin::unit_system::force& v2){
    time_si _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    force _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return momentum{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::force sakurajin::unit_system::operator/(const sakurajin::unit_system::momentum& v1, const sakurajin::unit_system::time_si& v2){
    momentum _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    time_si _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return force{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::force sakurajin::unit_system::operator*(const sakurajin::unit_system::mass& v1, const sakurajin::unit_system::acceleration& v2){
    mass _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    acceleration _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return force{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::acceleration sakurajin::unit_system::operator/(const sakurajin::unit_system::force& v1, const sakurajin::unit_system::mass& v2){
    force _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    mass _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return acceleration{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::force sakurajin::unit_system::operator*(const sakurajin::unit_system::acceleration& v1, const sakurajin::unit_system::mass& v2){
    acceleration _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    mass _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return force{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::mass sakurajin::unit_system::operator/(const sakurajin::unit_system::force& v1, const sakurajin::unit_system::acceleration& v2){
    force _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    acceleration _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return mass{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::momentum sakurajin::unit_system::operator*(const sakurajin::unit_system::mass& v1, const sakurajin::unit_system::speed& v2){
    mass _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    speed _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return momentum{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::speed sakurajin::unit_system::operator/(const sakurajin::unit_system::momentum& v1, const sakurajin::unit_system::mass& v2){
    momentum _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    mass _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return speed{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::momentum sakurajin::unit_system::operator*(const sakurajin::unit_system::speed& v1, const sakurajin::unit_system::mass& v2){
    speed _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    mass _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return momentum{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::mass sakurajin::unit_system::operator/(const sakurajin::unit_system::momentum& v1, const sakurajin::unit_system::speed& v2){
    momentum _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    speed _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return mass{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::power sakurajin::unit_system::operator*(const sakurajin::unit_system::force& v1, const sakurajin::unit_system::speed& v2){
    force _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    speed _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return power{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::speed sakurajin::unit_system::operator/(const sakurajin::unit_system::power& v1, const sakurajin::unit_system::force& v2){
    power _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    force _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return speed{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}


sakurajin::unit_system::power sakurajin::unit_system::operator*(const sakurajin::unit_system::speed& v1, const sakurajin::unit_system::force& v2){
    speed _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    force _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return power{_v1.value*_v2.value,_v1.multiplier*_v2.multiplier};
}

sakurajin::unit_system::force sakurajin::unit_system::operator/(const sakurajin::unit_system::power& v1, const sakurajin::unit_system::speed& v2){
    power _v1 = sakurajin::unit_system::unit_cast(v1,v1.multiplier,0);
    speed _v2 = sakurajin::unit_system::unit_cast(v2,v2.multiplier,0);
    return force{_v1.value/_v2.value,_v1.multiplier/_v2.multiplier};
}

