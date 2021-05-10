# unit-system

**Please note that the project is still in the early development state and some things might not work as expected!**

This is an implementation of the SI unit system for C++ development.
The library is split into three parts:

* base -> This contains all the base units
* common -> This contains commonly used units
* extra -> This contains addional units that are not needed by most people

If you feel like any unit is missing feel free to implement it and open a pull request.
You can create a new unit by letting it inherit from unit_t.
Since unit_t is a template make sure to assign a unique ID.
Below is a detailed description on how to create your own units.

Although this library is focued on SI units it can be used to work with imperial units, but there will NEVER be upstream support for it.
If you want to use imperial units you can figure out how to convert and add literals by yourself.

## Usage examples

```c++
#include "common.hpp"
#include <iostream>

using namespace sakurajin::unit_system::prefix;
using namespace sakurajin::unit_system::common;
using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::base::literals;

int main(){
    const auto t2 = 10.0_h;
    const auto s2 = 250.0_km;
    
    std::cout << s2 << " driven in " << t2 << " is an average speed of:" << s2/t2 << std::endl;
}

```

## Including the unit-system library

Depending on your build system you might have to figure out how to include and link this library by yourself.

### meson

unit-system is written in C++ with the meson build system.
Integrating this library is very easy.
Just use the wrapdb to download the version you need, and then you can add the library as a dependency object.

## Units that are currently supported

unit_t -> an unit template that is the basis of all of the units

### Base

* time_si -> time with seconds as base unit
* length -> length with meter as base unit
* mass -> mass with kg as base unit
* temperature (partial) -> temperatur with K as base unit
* amount -> amount of substance with mole as base unit
* electric_current (partial) -> electric current with Ampere as base unit
* luminous_intensity (partial) -> luminous intensity with candela as base unit

### Common

* speed -> speed with `m / s` as base unit
* acceleration -> acceleration with `m / s^2` as base unit
* momentum -> momentum with `kg * m / s` as base unit
* force -> force with `kg * m / s^2` (Newton) as base unit
* energy -> energy with `kg * m^2 / s^2` (Joules) as base unit

### Extra

For now this is not needed
