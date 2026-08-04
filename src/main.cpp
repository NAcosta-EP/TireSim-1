#include <iostream>
#include <cmath>

#include "SimulationState.hpp"
#include "Particle1D.hpp"
#include "Spring1D.hpp"
#include "CsvWriter.hpp"

int main(){

    std::vector<std::string> const columnHeaders{"time", "position","velocity","acceleration","spring_extension","spring_force","damping_force","total_force"};
    CsvWriter writer{columnHeaders,"Spring Test C_20_critdamping"};
    Particle1D partA{1.0, 1.0, 0.0};
    Spring1D springA{0.0, &partA, 0.0, 100, 20.0};

    double const timeStep{0.0001};
    double const finalTime{2.0};

    writer.writeData({
        std::to_string(partA.state().time),
        std::to_string(partA.state().position),
        std::to_string(partA.state().velocity),
        std::to_string(partA.state().acceleration),
        std::to_string(springA.getExtension()),
        std::to_string(springA.getSpringForce()),
        std::to_string(springA.getDampingForce()),
        std::to_string(springA.getTotalForce())
    });

    while (partA.state().time < finalTime)
    {
        partA.setNetForce(springA.getTotalForce());
        partA.update(timeStep);


        writer.writeData({
            std::to_string(partA.state().time),
            std::to_string(partA.state().position),
            std::to_string(partA.state().velocity),
            std::to_string(partA.state().acceleration),
            std::to_string(springA.getExtension()),
            std::to_string(springA.getSpringForce()),
            std::to_string(springA.getDampingForce()),
            std::to_string(springA.getTotalForce())
        });
    }

    writer.endWrite();
    return 0;
}