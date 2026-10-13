#include "nbody/forces.hpp"
#include <cmath>
#include <iostream>

namespace nbody {
    // Returns a list of accelerations [xacc, yacc] for each body in System
    std::vector<std::array<double, 2>> accelerations(const System& s) {
        std::vector<std::array<double, 2>> result(s.size(), {0, 0});
        // TODO

        // Loops over all pairs, to determine forces on eachother. 
        // The outer loop i is the body being accellerated, and j is the body doing the pulling
        for (std::size_t i = 0; i < s.size(); i++) {
            for (std::size_t j = 0; j < s.size(); j++) {
                if (i == j) continue; // body does not exert force on itself
                
            }
        }

        return result;
    }


}