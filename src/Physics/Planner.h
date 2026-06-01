
double computeTargetVelocity(const State& state) const {
    return (target_x_ - state.x) * gain_;
}

#pragma once
#include "State.h"
#include <cmath>

class Planner {
public:
    Planner(double tx = 0, double ty = 0, double tz = 0, double gain = 0.5)
        : tx_(tx), ty_(ty), tz_(tz), gain_(gain) {}

    void setTarget(double x, double y, double z) {
        tx_ = x; ty_ = y; tz_ = z;
    }

    double computeVx(const State& s) const { return (tx_ - s.x) * gain_; }
    double computeVy(const State& s) const { return (ty_ - s.y) * gain_; }
    double computeVz(const State& s) const { return (tz_ - s.z) * gain_; }

    double distanceToTarget(const State& s) const {
        return std::sqrt(
            std::pow(tx_ - s.x, 2) +
            std::pow(ty_ - s.y, 2) +
            std::pow(tz_ - s.z, 2)
        );
    }

    bool isReached(const State& s, double tol = 0.1) const {
        return distanceToTarget(s) < tol;
    }

private:
    double tx_, ty_, tz_, gain_;
};