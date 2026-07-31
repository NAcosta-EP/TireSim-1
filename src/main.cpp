#include <iostream>
#include <cmath>

#include "SimulationState.hpp"
#include "Particle1D.hpp"
#include "CsvWriter.hpp"

int main(){
    constexpr double simulationTimeLimit{20.000}; // in Seconds
    constexpr double timeStep{0.01}; // in Seconds

    constexpr double coeffDrag{0.5}; // Unitless
    constexpr double particleArea{0.1}; // m^2
    constexpr double airPressure{1.225}; //kg per m^3
    constexpr double forceThrust{10.0}; // N
    double forceDrag{0.0}; // N

    Particle1D partA{2.0,0.0,0.0};
    partA.setNetForce(forceThrust);

    CsvWriter writer{{"time_s", "position_m", "velocity_m_per_s", "acceleration_m_per_s2"},"P1L9_NoDrag_Case"};

    writer.writeData({
        std::to_string(partA.state().time),
        std::to_string(partA.state().position),
        std::to_string(partA.state().velocity),
        std::to_string(partA.state().acceleration)
    });

    while(partA.state().time + timeStep < simulationTimeLimit)
    {
        //forceDrag = -0.5*airPressure*coeffDrag*particleArea*std::abs(partA.state().velocity)*partA.state().velocity;
        partA.setNetForce(forceThrust+forceDrag);
        partA.update(timeStep);
        writer.writeData({
            std::to_string(partA.state().time),
            std::to_string(partA.state().position),
            std::to_string(partA.state().velocity),
            std::to_string(partA.state().acceleration)
        });
    }
    writer.endWrite();

    return 0;
}