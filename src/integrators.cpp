#include "nbody/forces.hpp"
#include "nbody/integrators.hpp"

namespace nbody {
    void euler(System& s, double dt) {
        std::vector<std::array<double, 2>> accelerations = nbody::accelerations(s);

        for (std::size_t i; i < s.size(); i++) {
        }

    }
}