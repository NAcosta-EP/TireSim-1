#include "Particle1D.hpp"

#include <stdexcept>

Particle1D::Particle1D(
    double mass, 
    double initialPosition, 
    double initialVelocity
)
    : mass_{mass}, netForce_{0.0}, state_{0.0,initialPosition, initialVelocity, 0.0}
{
    if(mass <= 0.0)
    {
        throw std::invalid_argument{
            "Particle mass must be greate than zero."
        };
    }
}

void Particle1D::update(double timeStep){
    if(timeStep <= 0.0){
        throw std::invalid_argument{"Timestep must be greater than zero"};
    }

    state_.acceleration = netForce_/mass_;
    state_.velocity = state_.velocity + state_.acceleration*timeStep;
    state_.position = state_.position + state_.velocity*timeStep;
    state_.time = state_.time + timeStep;
}

void Particle1D::setNetForce(double netForce){
    netForce_ = netForce;
}