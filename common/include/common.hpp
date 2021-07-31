#pragma once

#include "base.hpp"
#include "speed.hpp"
#include "acceleration.hpp"
#include "momentum.hpp"
#include "force.hpp"
#include "energy.hpp"
#include "power.hpp"

#if __has_include(<iostream>)

    #include <iostream>
    
    namespace sakurajin{
        namespace unit_system{
            namespace common{
                std::ostream& operator<<(std::ostream& os, const acceleration& v);
            
                std::ostream& operator<<(std::ostream& os, const energy& v);
            
                std::ostream& operator<<(std::ostream& os, const force& v);
            
                std::ostream& operator<<(std::ostream& os, const momentum& v);
            
                std::ostream& operator<<(std::ostream& os, const power& p);
            
                std::ostream& operator<<(std::ostream& os, const speed& v);
            }
        }
    }
    
#endif
