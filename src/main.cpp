#include "nbody/body.hpp"
#include "nbody/integrators.hpp"

#include <iostream>

int main() {

    nbody::System s;
    // x, y, xvel, yvel, mass
    s.push_back({0, 0, 0, 0, 1});
    s.push_back({1, 0, 0, 1, 0.001});

    double dt = 0.01;
    int steps = 10000;
    double t = 0;
    std::cout << "t," << "x0," << "y0," << "x1," << "y1," << "\n";
    while (t < steps * dt) {
        std::cout << t << "," << s[0].x << ","  << s[0].y << "," << s[1].x << "," << s[1].y << "," << "\n";
        nbody::euler(s, dt);
        t += dt;
    }
    return 0;
}
