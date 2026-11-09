#include <gtest/gtest.h>

#include "nbody/body.hpp"
#include "nbody/diagnostics.hpp"
#include "nbody/integrators.hpp"

#include <cmath>

using namespace nbody;

namespace {
    System circular_orbit() {
        double M = 1;
        double m = 0.001;
        double r = 1;
        double v = std::sqrt((M+m)/r);

        System s(2);

        s[0].mass = M;
        s[0].x    = -m / (M + m) * r;
        s[0].yvel = -m / (M + m) * v;

        s[1].mass = m;
        s[1].x    =  M / (M + m) * r;
        s[1].yvel =  M / (M + m) * v;

        return s;
    }

    void run(System& s, Integrator step, int steps, double dt) {
        for (int i = 0; i < steps; i++) step(s, dt);
    }
}
TEST(RK4, ConservesEnergy) {
    System s = circular_orbit();
    double e0 = total_energy(s);

    run(s, rk4, 62832, 0.001);

    double e_end = total_energy(s);

    double drift = std::abs((e_end - e0) / e0);
    EXPECT_LT(drift, 1e-10);
}

TEST(RK4, ConservesMomentum) {
    System s = circular_orbit();
    run(s, rk4, 62832, 0.001);
    auto p = total_momentum(s);
    EXPECT_NEAR(p[0], 0.0, 1e-12);
    EXPECT_NEAR(p[0], 0.0, 1e-12);
}

TEST(RK4, CircularOrbitStaysCircular) {
    System s = circular_orbit();
    run(s, rk4, 62832, 0.001);
    // TODO: EXPECT_NEAR the separation to 1.0, tolerance 1e-6
}

TEST(Euler, ConservesMomentum) {
    // TODO: same as RK4 momentum, using euler
}

TEST(Euler, OrbitSpiralsOutward) {
    System s = circular_orbit();
    run(s, euler, 62832, 0.001);
    // TODO: EXPECT_GT the separation to 1.05
}

TEST(Comparison, EulerFailsTightBoundRK4Passes) {
    const double tight = 1e-6;
    System e = circular_orbit();
    System r = circular_orbit();
    double e0 = total_energy(e);

    // TODO: run e with euler and r with rk4, 62832 steps, dt = 0.001
    // TODO: EXPECT_GT(rel_drift(e0, total_energy(e)), tight);   // Euler violates it
    // TODO: EXPECT_LT(rel_drift(e0, total_energy(r)), tight);   // RK4 satisfies it
}