#pragma once

#include "SimulationState.hpp"

class Particle1D
{
    private:
        SimulationState state_;
        double netForce_;
        double mass_;

    public:
        Particle1D(double mass, double initialPosition, double initialVelocity);
        void setNetForce(double netForce);
        void update(double timeStep);
        double mass() const {return mass_;};
        double netForce() const {return netForce_;};
        SimulationState state() const {return state_;};
};