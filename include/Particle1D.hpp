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
        Particle1D(double mass) : Particle1D(mass,0.0,0.0) {}

        void setNetForce(double netForce);
        double getNetForce() const {return netForce_;};

        void update(double timeStep);

        void setMass(double mass);
        double getMass() const {return mass_;};


        const SimulationState& state() const {return state_;};
};