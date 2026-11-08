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

    
    void leapfrog(System& s, double dt) {
        // Compute acceleration at current position
        
        // half-kick velocity
        // update position
        // Compute acceleration at next position
        // half-kick velocity
    }

    void rk4(System& s, double dt) {
        std::size_t n = s.size();
        std::vector<std::array<double, 2>> acc = nbody::accelerations(s);

        // Each step uses a fresh copy of the system
        System s2 = s; 
        for (std::size_t i = 0; i < n; i++) {
            s2[i].x = s[i].x + s[i].xvel * dt/2;
            s2[i].y = s[i].y + s[i].yvel * dt/2;
            s2[i].xvel = s[i].xvel + acc[i][0] * dt/2;
            s2[i].yvel = s[i].yvel + acc[i][1] * dt/2;
        }

        std::vector<std::array<double, 2>> acc2 = nbody::accelerations(s2);

        System s3 = s; 
        for (std::size_t i = 0; i < n; i++) {
            s3[i].x = s[i].x + s2[i].xvel * dt/2;
            s3[i].y = s[i].y + s2[i].yvel * dt/2;
            s3[i].xvel = s[i].xvel + acc2[i][0] * dt/2;
            s3[i].yvel = s[i].yvel + acc2[i][1] * dt/2;
        }

        std::vector<std::array<double, 2>> acc3 = nbody::accelerations(s3);
        System s4 = s;
        for (std::size_t i = 0; i < n; i++) {
            s4[i].x = s[i].x + s3[i].xvel * dt;
            s4[i].y = s[i].y + s3[i].yvel * dt;
            s4[i].xvel = s[i].xvel + acc3[i][0] * dt;
            s4[i].yvel = s[i].yvel + acc3[i][1] * dt;
        }

        std::vector<std::array<double, 2>> acc4 = nbody::accelerations(s4);

        // Final update: weighted average (1, 2, 2, 1) / 6
        for (std::size_t i = 0; i < n; i++) {
            s[i].x    += dt/6 * (s[i].xvel + 2*s2[i].xvel + 2*s3[i].xvel + s4[i].xvel);
            s[i].y    += dt/6 * (s[i].yvel + 2*s2[i].yvel + 2*s3[i].yvel + s4[i].yvel);
            s[i].xvel += dt/6 * (acc[i][0] + 2*acc2[i][0] + 2*acc3[i][0] + acc4[i][0]);
            s[i].yvel += dt/6 * (acc[i][1] + 2*acc2[i][1] + 2*acc3[i][1] + acc4[i][1]);
        }
    }
}