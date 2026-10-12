#pragma once
#include "nbody/body.hpp"

#include <array>
#include <vector>

namespace nbody {

    // Returns a list of accelerations [xacc, yacc] for each body in System
    std::vector<std::array<double, 2>> accelerations(const System& s);
}