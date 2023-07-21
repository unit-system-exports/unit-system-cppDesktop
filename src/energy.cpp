
#include "unit_system/energy.hpp"


using namespace sakurajin::unit_system;

energy::energy(): energy(0){}
energy::energy(unit_t<8> val): energy(val.value,val.multiplier){}
energy::energy(long double val): energy(val,1){}
energy::energy(long double val, long double mult ): unit_t<8>(val,mult){}
energy::energy(long double val, long double mult, long double offset ): unit_t<8>(val,mult,offset){}

std::ostream& ::sakurajin::unit_system::operator<<(std::ostream& os, const ::sakurajin::unit_system::energy& t){
    auto t1 = ::sakurajin::unit_system::unit_cast(t,1);
    return os << t1.value << " energy";
}




energy literals::operator "" _J(long double len){
    return energy{len,1.0, 0.0};
}

energy literals::operator "" _J(unsigned long long int len){
    return energy{static_cast<long double>(len),1.0, 0.0};
}



energy literals::operator "" _Nm(long double len){
    return energy{len,1.0, 0.0};
}

energy literals::operator "" _Nm(unsigned long long int len){
    return energy{static_cast<long double>(len),1.0, 0.0};
}



energy literals::operator "" _eV(long double len){
    return energy{len,1.602176634e-19, 0.0};
}

energy literals::operator "" _eV(unsigned long long int len){
    return energy{static_cast<long double>(len),1.602176634e-19, 0.0};
}



energy literals::operator "" _Wh(long double len){
    return energy{len,3600.0, 0.0};
}

energy literals::operator "" _Wh(unsigned long long int len){
    return energy{static_cast<long double>(len),3600.0, 0.0};
}



energy literals::operator "" _Ws(long double len){
    return energy{len,1.0, 0.0};
}

energy literals::operator "" _Ws(unsigned long long int len){
    return energy{static_cast<long double>(len),1.0, 0.0};
}



energy literals::operator "" _PJ(long double len){
    return energy{len,1000000000000000.0, 0.0};
}

energy literals::operator "" _PJ(unsigned long long int len){
    return energy{static_cast<long double>(len),1000000000000000.0, 0.0};
}



energy literals::operator "" _TJ(long double len){
    return energy{len,1000000000000.0, 0.0};
}

energy literals::operator "" _TJ(unsigned long long int len){
    return energy{static_cast<long double>(len),1000000000000.0, 0.0};
}



energy literals::operator "" _GJ(long double len){
    return energy{len,1000000000.0, 0.0};
}

energy literals::operator "" _GJ(unsigned long long int len){
    return energy{static_cast<long double>(len),1000000000.0, 0.0};
}



energy literals::operator "" _MJ(long double len){
    return energy{len,1000000.0, 0.0};
}

energy literals::operator "" _MJ(unsigned long long int len){
    return energy{static_cast<long double>(len),1000000.0, 0.0};
}



energy literals::operator "" _kJ(long double len){
    return energy{len,1000.0, 0.0};
}

energy literals::operator "" _kJ(unsigned long long int len){
    return energy{static_cast<long double>(len),1000.0, 0.0};
}



energy literals::operator "" _mJ(long double len){
    return energy{len,0.001, 0.0};
}

energy literals::operator "" _mJ(unsigned long long int len){
    return energy{static_cast<long double>(len),0.001, 0.0};
}



energy literals::operator "" _uJ(long double len){
    return energy{len,1e-06, 0.0};
}

energy literals::operator "" _uJ(unsigned long long int len){
    return energy{static_cast<long double>(len),1e-06, 0.0};
}



energy literals::operator "" _nJ(long double len){
    return energy{len,1e-09, 0.0};
}

energy literals::operator "" _nJ(unsigned long long int len){
    return energy{static_cast<long double>(len),1e-09, 0.0};
}



energy literals::operator "" _pJ(long double len){
    return energy{len,1e-12, 0.0};
}

energy literals::operator "" _pJ(unsigned long long int len){
    return energy{static_cast<long double>(len),1e-12, 0.0};
}



energy literals::operator "" _fJ(long double len){
    return energy{len,1e-15, 0.0};
}

energy literals::operator "" _fJ(unsigned long long int len){
    return energy{static_cast<long double>(len),1e-15, 0.0};
}



energy literals::operator "" _aJ(long double len){
    return energy{len,1e-18, 0.0};
}

energy literals::operator "" _aJ(unsigned long long int len){
    return energy{static_cast<long double>(len),1e-18, 0.0};
}



energy literals::operator "" _GNm(long double len){
    return energy{len,1000000000.0, 0.0};
}

energy literals::operator "" _GNm(unsigned long long int len){
    return energy{static_cast<long double>(len),1000000000.0, 0.0};
}



energy literals::operator "" _MNm(long double len){
    return energy{len,1000000.0, 0.0};
}

energy literals::operator "" _MNm(unsigned long long int len){
    return energy{static_cast<long double>(len),1000000.0, 0.0};
}



energy literals::operator "" _kNm(long double len){
    return energy{len,1000.0, 0.0};
}

energy literals::operator "" _kNm(unsigned long long int len){
    return energy{static_cast<long double>(len),1000.0, 0.0};
}



energy literals::operator "" _mNm(long double len){
    return energy{len,0.001, 0.0};
}

energy literals::operator "" _mNm(unsigned long long int len){
    return energy{static_cast<long double>(len),0.001, 0.0};
}



energy literals::operator "" _uNm(long double len){
    return energy{len,1e-06, 0.0};
}

energy literals::operator "" _uNm(unsigned long long int len){
    return energy{static_cast<long double>(len),1e-06, 0.0};
}



energy literals::operator "" _PeV(long double len){
    return energy{len,0.0001602176634, 0.0};
}

energy literals::operator "" _PeV(unsigned long long int len){
    return energy{static_cast<long double>(len),0.0001602176634, 0.0};
}



energy literals::operator "" _TeV(long double len){
    return energy{len,1.602176634e-07, 0.0};
}

energy literals::operator "" _TeV(unsigned long long int len){
    return energy{static_cast<long double>(len),1.602176634e-07, 0.0};
}



energy literals::operator "" _GeV(long double len){
    return energy{len,1.6021766339999998e-10, 0.0};
}

energy literals::operator "" _GeV(unsigned long long int len){
    return energy{static_cast<long double>(len),1.6021766339999998e-10, 0.0};
}



energy literals::operator "" _MeV(long double len){
    return energy{len,1.6021766339999998e-13, 0.0};
}

energy literals::operator "" _MeV(unsigned long long int len){
    return energy{static_cast<long double>(len),1.6021766339999998e-13, 0.0};
}



energy literals::operator "" _keV(long double len){
    return energy{len,1.602176634e-16, 0.0};
}

energy literals::operator "" _keV(unsigned long long int len){
    return energy{static_cast<long double>(len),1.602176634e-16, 0.0};
}



energy literals::operator "" _meV(long double len){
    return energy{len,1.6021766339999998e-22, 0.0};
}

energy literals::operator "" _meV(unsigned long long int len){
    return energy{static_cast<long double>(len),1.6021766339999998e-22, 0.0};
}



energy literals::operator "" _ueV(long double len){
    return energy{len,1.602176634e-25, 0.0};
}

energy literals::operator "" _ueV(unsigned long long int len){
    return energy{static_cast<long double>(len),1.602176634e-25, 0.0};
}



energy literals::operator "" _PWh(long double len){
    return energy{len,3.6e+18, 0.0};
}

energy literals::operator "" _PWh(unsigned long long int len){
    return energy{static_cast<long double>(len),3.6e+18, 0.0};
}



energy literals::operator "" _TWh(long double len){
    return energy{len,3600000000000000.0, 0.0};
}

energy literals::operator "" _TWh(unsigned long long int len){
    return energy{static_cast<long double>(len),3600000000000000.0, 0.0};
}



energy literals::operator "" _GWh(long double len){
    return energy{len,3600000000000.0, 0.0};
}

energy literals::operator "" _GWh(unsigned long long int len){
    return energy{static_cast<long double>(len),3600000000000.0, 0.0};
}



energy literals::operator "" _MWh(long double len){
    return energy{len,3600000000.0, 0.0};
}

energy literals::operator "" _MWh(unsigned long long int len){
    return energy{static_cast<long double>(len),3600000000.0, 0.0};
}



energy literals::operator "" _kWh(long double len){
    return energy{len,3600000.0, 0.0};
}

energy literals::operator "" _kWh(unsigned long long int len){
    return energy{static_cast<long double>(len),3600000.0, 0.0};
}


