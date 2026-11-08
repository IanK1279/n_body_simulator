#pragma once
#include "nbody/body.hpp"

namespace nbody {

    using Integrator = void (*)(System&, double);
    // updates body in system s, using dt as the time interval. 
    
    void euler(System& s, double dt);
    void leapfrog(System& s, double dt);
    void rk4(System& s, double dt);
}