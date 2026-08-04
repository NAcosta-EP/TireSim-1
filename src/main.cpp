#include <iostream>
#include <cmath>

#include "SimulationState.hpp"
#include "Particle1D.hpp"
#include "Spring1D.hpp"
#include "CsvWriter.hpp"

int main(){
    Spring1D springA{0.0, 2.2, 2.0, 100};
    Spring1D springB{0.0, 1.8, 2.0, 100};
    Spring1D springC{0.0, -2.2, 2.0, 100};
    Spring1D springD{0.0, -1.8, 2.0, 100};

    std::cout << "Rest Length: 2.0 m, Anchor: 0.0 m, Particle: "<< springA.getParticlePosition() <<" m, Ext: " <<
        springA.getExtension() <<" m, "<< springA.getSpringForce() << "N\n";
    std::cout << "Rest Length: 2.0 m, Anchor: 0.0 m, Particle: "<< springB.getParticlePosition() <<" m, Ext: " <<
        springB.getExtension() <<" m, "<< springB.getSpringForce() << "N\n";
    std::cout << "Rest Length: 2.0 m, Anchor: 0.0 m, Particle: "<< springC.getParticlePosition() <<" m, Ext: " <<
        springC.getExtension() <<" m, "<< springC.getSpringForce() << "N\n";
    std::cout << "Rest Length: 2.0 m, Anchor: 0.0 m, Particle: "<< springD.getParticlePosition() <<" m, Ext: " <<
        springD.getExtension() <<" m, "<< springD.getSpringForce() << "N\n";
    return 0;
}