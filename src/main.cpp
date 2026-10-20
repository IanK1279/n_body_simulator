#include "nbody/body.hpp"
#include "nbody/integrators.hpp"

#include <iostream>

int main() {

    nbody::System s;
    // x, y, xvel, yvel, mass
    s.push_back({2, 0, 0, -0.5, 2});
    s.push_back({1, 0, 0, 1, 0.5});
    s.push_back({0, 4, -1, 0, 0.5});
    s.push_back({0, 4, 0, 1, 1});

    double dt = 0.01;
    int steps = 10000;
    std::cout.precision(10);
    std::cout << "t";
    for (int i = 0; i < s.size() ; i++) {
        std::cout << ",x" << i << "," << "y" << i;
    }
    std::cout << "\n";
    for (int step = 0; step < steps; step++){     
        double t = step * dt;   
        std::cout << t;
        for (int i = 0; i < s.size(); i++) {
            std::cout << "," << s[i].x << ","  << s[i].y ;
        }
        std::cout << "\n";
        nbody::euler(s, dt);
    }
    return 0;
}
