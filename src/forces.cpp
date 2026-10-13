#include "nbody/forces.hpp"
#include <cmath>
#include <iostream>

namespace nbody {
    // Returns a list of accelerations [xacc, yacc] for each body in System
    std::vector<std::array<double, 2>> accelerations(const System& s) {
        std::vector<std::array<double, 2>> result(s.size(), {0, 0});

        // Loops over all pairs, to determine forces on eachother. 
        // The outer loop i is the body being accellerated, and j is the body doing the pulling
        for (std::size_t i = 0; i < s.size(); i++) {
            for (std::size_t j = 0; j < s.size(); j++) {
                if (i == j) continue; // body does not exert force on itself
                double dx = s[j].x - s[i].x;
                double dy = s[j].y - s[i].y;
                double r2 = dx*dx + dy*dy; // will need r^3 eventually, so this saves computing power (r^3 = r2*r)
                double r = std::sqrt(r2);

                // Assuming G = 1 for simplification
                result[i][0] = s[j].mass * dx / (r2 * r);
                result[i][1] = s[j].mass * dy / (r2 * r);

            }
        }

        return result;
    }


}