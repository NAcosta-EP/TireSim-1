#pragma once

#include "SimulationState.hpp"

class Particle1D
{
    private:
        SimulationState state_;
        double netForce_;
        double mass_;
        bool fixed_;

    public:
        Particle1D(double mass, bool fixed, double initialPosition, double initialVelocity);
        Particle1D(double mass, bool fixed) : Particle1D(mass,fixed,0.0,0.0) {}
        Particle1D(double mass) : Particle1D(mass,false,0.0,0.0) {}

        void setNetForce(double netForce);
        double getNetForce() const {return netForce_;};

        void update(double timeStep);

        void setMass(double mass);
        double getMass() const {return mass_;};

        void setFixed(bool fixed);
        bool isFixed(){return fixed_;};


        const SimulationState& state() const {return state_;};
};