#pragma once
#include "nbody/body.hpp"

#include <array>

namespace nbody {

    // Kinetic + potential energy (G = 1)
    double total_energy(const System& s);

    // Total linear momentum [px, py]
    std::array<double, 2> total_momentum(const System& s);
}