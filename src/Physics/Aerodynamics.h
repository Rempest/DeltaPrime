#pragma once
#include <cmath>

class Aerodynamics {
public:
    Aerodynamics(double air_density = 1.225,
                 double drag_coeff  = 0.47,
                 double lift_coeff  = 1.2,
                 double area        = 0.1)
        : rho_(air_density)
        , cd_(drag_coeff)
        , cl_(lift_coeff)
        , area_(area) {}

    double computeDrag(double velocity) const {
        return 0.5 * rho_ * cd_ * area_ * velocity * velocity;
    }

    double computeLift(double velocity) const {
        return 0.5 * rho_ * cl_ * area_ * velocity * velocity;
    }

    double computeReynolds(double velocity, double chord = 0.1) const {
        const double viscosity = 1.81e-5;
        return (rho_ * velocity * chord) / viscosity;
    }

private:
    double rho_;
    double cd_;
    double cl_;
    double area_;
};
