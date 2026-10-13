#include "nbody/forces.hpp"
#include "nbody/integrators.hpp"

namespace nbody {

    // Uses explicit euler (causes energy errors, used for comparison)
    void euler(System& s, double dt) {
        std::vector<std::array<double, 2>> acc = nbody::accelerations(s);

        for (std::size_t i = 0; i < s.size(); i++) {
            s[i].x += s[i].xvel * dt;
            s[i].y += s[i].yvel * dt;
            
            s[i].xvel += acc[i][0] * dt;
            s[i].yvel += acc[i][1] * dt;
        }

    }
}