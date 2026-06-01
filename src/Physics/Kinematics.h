
#pragma once
#include <cmath>
#include "State.h"

class Kinematics {
public:
    void integrate(State& state, double dt) const {
        state.vx += state.ax * dt;
        state.vy += state.ay * dt;
        state.vz += state.az * dt;

        state.x += state.vx * dt;
        state.y += state.vy * dt;
        state.z += state.vz * dt;
    }

    double speed(const State& s) const {
        return std::sqrt(s.vx*s.vx + s.vy*s.vy + s.vz*s.vz);
    }

    double altitude(const State& s) const {
        return s.z;
    }

    double horizontalDistance(const State& s) const {
        return std::sqrt(s.x*s.x + s.y*s.y);
    }
};