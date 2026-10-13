#pragma once
#include "nbody/body.hpp"

namespace nbody {

    // updates body in system s, using dt as the time interval. 
    void euler(System& s, double dt);
}