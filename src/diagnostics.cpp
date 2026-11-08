#include "nbody/diagnostics.hpp"
#include <cmath>

namespace nbody {
    double total_energy(const System& s) {
        double T = 0;
        double U = 0;

        for (std::size_t i = 0; i < s.size(); i++) {
            // Calc T
            T += 0.5 * s[i].mass * (s[i].xvel * s[i].xvel + s[i].yvel * s[i].yvel);

            // Calc V
            for (std::size_t j = i+1; j < s.size(); j++) {
                double dx = s[j].x - s[i].x;
                double dy = s[j].y - s[i].y;
                double r = std::sqrt(dx*dx + dy*dy);
                U -= s[i].mass * s[j].mass / r;
            }
        }

        return T + U;
    }

    std::array<double, 2> total_momentum(const System& s) {
        double px_tot = 0;
        double py_tot = 0;
        for (std::size_t i = 0; i < s.size(); i++) {
            px_tot += s[i].mass * s[i].xvel;
            py_tot += s[i].mass * s[i].yvel;
        }
        return {px_tot, py_tot};
    }
}