#include <iostream>
#include <cmath>

#include "SimulationState.hpp"
#include "Particle1D.hpp"
#include "Spring1D.hpp"
#include "CsvWriter.hpp"

int main(){
    Spring1D springA{0.0,2.5,-2.0, 1, 2.0};
    Spring1D springB{0.0,1.5,2.0};
    Spring1D springC{0.0,-2.5, 2.0};
    Spring1D springD{0.0, 0.0, 2.0};

    std::cout << "Rest Length: 2.0 m, Anchor: 0.0 m, Particle: 2.5 m, Ext: " << springA.getExtension() <<" m\n";
    std::cout << "Rest Length: 2.0 m, Anchor: 0.0 m, Particle: 1.5 m, Ext: " << springB.getExtension() <<" m\n";
    std::cout << "Rest Length: 2.0 m, Anchor: 0.0 m, Particle: -2.5 m, Ext: " << springC.getExtension() <<" m\n";
    std::cout << "Rest Length: 2.0 m, Anchor: 0.0 m, Particle: 0.0 m, Ext: " << springD.getExtension() <<" m\n";
    return 0;
}