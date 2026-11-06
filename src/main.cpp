#include "nbody/body.hpp"
#include "nbody/integrators.hpp"

#include <fstream>     // std::ifstream
#include <sstream>     // std::istringstream
#include <string>
#include <iostream>

nbody::System load_preset(std::string& path) {
    nbody::System s;
    // read file
    std::ifstream file(path);
    if (!file) {
        std::cerr << "Could not open " << path << "\n";
        return s;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        nbody::Body b;
        if (ss >> b.x >> b.y >> b.xvel >> b.yvel >> b.mass) {
            s.push_back(b);
        }
    }
    return s;

}

int main() {

    std::string preset_path = "presets/sunplanetmoon.txt";
    nbody::System s = load_preset(preset_path);

    double dt = 0.01;
    int steps = 15000;
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