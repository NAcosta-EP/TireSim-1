#include <iostream>

#include "SimulationState.hpp"
#include "Particle1D.hpp"

int main(){
    // ------- Phase 0 Code Task --------
    // std::cout << "TireSim - Phase 0 is running.\n";


    // ------- Phase 1 - Lesson 1 Code Task ---------
    // SimulationState simState{0,2,-3,0};

    // std::cout << "Time: " << simState.time << " s\n";
    // std::cout << "Position: " << simState.position << " m\n";
    // std::cout << "Velocity: " << simState.velocity << " m/s\n";
    // std::cout << "Acceleration: " << simState.acceleration << " m/s^2\n";

    // ------- Phase 1 - Lesson 2 Code Task ---------

    // Particle1D particleA{0.0,0,0}; <- Does not work, aborts code
    // Particle1D particleA{1.0,0.0,0.0}; // <-Valid Particle

    // ------- Phase 1 - Lesson 3 Code Task ---------
    /*
        Hand calculate the following acceleration cases:
        CASE 1: F= 10 N, m= 2 kg
        CASE 2: F= 12 N, m= 3 kg
        CASE 3: F= 0 N, m= 5 kg

        Modify the Particle1D update function to calculate
        acceleration from net force and mass.

        - Create a particle for each case
        - Set the force
        - Update each particle
        - Print the calculated acceleration
        - Compare to the hand calulcations
    */
    // Particle1D particleA{2.0,0.0,0.0};
    // Particle1D particleB{3.0,0.0,0.0};
    // Particle1D particleC{5.0,0.0,0.0};

    // particleA.setNetForce(10.0);
    // particleB.setNetForce(12.0);
    // particleC.setNetForce(0.0);

    // particleA.update();
    // particleB.update();
    // particleC.update();

    // std::cout << "Case 1 Accleration: " << particleA.state().acceleration << " m/s^2\n";
    // std::cout << "Case 2 Accleration: " << particleB.state().acceleration << " m/s^2\n";
    // std::cout << "Case 3 Accleration: " << particleC.state().acceleration << " m/s^2\n";

    // ------- Phase 1 - Lesson 4 Code Task ----------
    /*
    Basic Numerical Integration
    Expand update() so it:

    - Rejects a zero or negative timestep.
    - Calculates acceleration.
    - Updates velocity.
    - Updates position.
    - Updates time.

    The order of these operations is part of the numerical method.

    - Run exactly three updates using a timestep of 0.1 seconds.

    My program results should match my hand-calculated table.
    */
    int cycles = 20;
    double timeStep = 0.1; //seconds
    Particle1D particleA{2.0,0.0,0.0};
    particleA.setNetForce(10.0);

    for(int x=0;x<cycles;++x){
        particleA.update(timeStep);
        std::cout << "Timestep: " << x+1 << "\n";
        std::cout << "Time: " << particleA.state().time << " s\n";
        std::cout << "Accleration: " << particleA.state().acceleration << " m/s^2\n";
        std::cout << "Velocity: " << particleA.state().velocity << " m/s\n";
        std::cout << "Position: " << particleA.state().position << " m\n";
        std::cout << "\n";
    }

    return 0;
}