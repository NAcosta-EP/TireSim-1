#include <iostream>
#include <cmath>

#include "SimulationState.hpp"
#include "Particle1D.hpp"
#include "Spring1D.hpp"
#include "CsvWriter.hpp"

int main(){

    std::vector<std::string> const columnHeaders{"time-A", "position-A","velocity-A","acceleration-A","force-A","time-B", "position-B","velocity-B","acceleration-B","force-B","spring_extension","spring_force","damping_force","spring_total_force", "kinetic_energy-A", "kinetic_energy-B", "spring_energy", "total_energy"};
    CsvWriter writer{columnHeaders,"Spring Test - TwoPart - 10C"};
    Particle1D partA{1.0, 0.0, 0.0};
    Particle1D partB{1.0, 1.0, 0.0};
    Spring1D springA{&partB, &partA, 0.0, 100, 10.0};

    double const timeStep{0.0001};
    double const finalTime{2.0};

    writer.writeData({
        std::to_string(partA.state().time),
        std::to_string(partA.state().position),
        std::to_string(partA.state().velocity),
        std::to_string(partA.state().acceleration),
        std::to_string(partA.getNetForce()),
        std::to_string(partB.state().time),
        std::to_string(partB.state().position),
        std::to_string(partB.state().velocity),
        std::to_string(partB.state().acceleration),
        std::to_string(partB.getNetForce()),
        std::to_string(springA.getExtension()),
        std::to_string(springA.getSpringForce()),
        std::to_string(springA.getDampingForce()),
        std::to_string(springA.getTotalForce()),
        std::to_string(partA.state().kineticEnergy),
        std::to_string(partB.state().kineticEnergy),
        std::to_string(springA.getSpringEnergy()),
        std::to_string(partA.state().kineticEnergy + partB.state().kineticEnergy + springA.getSpringEnergy())
    });

    while (partA.state().time < finalTime)
    {
        partA.setNetForce(springA.getTotalForce());
        partB.setNetForce(-springA.getTotalForce());
        partA.update(timeStep);
        partB.update(timeStep);


        writer.writeData({
            std::to_string(partA.state().time),
            std::to_string(partA.state().position),
            std::to_string(partA.state().velocity),
            std::to_string(partA.state().acceleration),
            std::to_string(partA.getNetForce()),
            std::to_string(partB.state().time),
            std::to_string(partB.state().position),
            std::to_string(partB.state().velocity),
            std::to_string(partB.state().acceleration),
            std::to_string(partB.getNetForce()),
            std::to_string(springA.getExtension()),
            std::to_string(springA.getSpringForce()),
            std::to_string(springA.getDampingForce()),
            std::to_string(springA.getTotalForce()),
            std::to_string(partA.state().kineticEnergy),
            std::to_string(partB.state().kineticEnergy),
            std::to_string(springA.getSpringEnergy()),
            std::to_string(partA.state().kineticEnergy + partB.state().kineticEnergy + springA.getSpringEnergy())
        });
    }

    writer.endWrite();
    return 0;
}