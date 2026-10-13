#include "nbody/forces.hpp"
#include <cmath>

namespace nbody {
    // Returns a list of accelerations [xacc, yacc] for each body in System
    std::vector<std::array<double, 2>> accelerations(const System& s) {
        std::vector<std::array<double, 2>> result(s.size(), {0, 0});
        // TODO
    }


}