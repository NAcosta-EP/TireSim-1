#pragma once

#include "Particle1D.hpp"
#include <stdexcept>

class Spring1D{
    private:
        //Spring Material Properties
        double stiffness_{1.0};
        double restLength_{1.0};
        double coeffDamping_{0.0};

        //Spring Spatial Properties
        Particle1D *particleA_;
        Particle1D *particleB_;
        double extension_{0.0};

        //Spring Force Properties
        double forceSpring_{0.0};
        double forceDamping_{0.0};
        double forceTotal_{0.0};

        //Spring Energy Properties
        double springEnergy_{0.0};

    public:
        /**
         * @brief 1D Spring Physics Object
         * @param anchorPos Anchor Position of Spring [Meters]
         * @param particle Particle at end of spring <- Pass in Particle address.
         * @param restLength Resting length of the spring, must be 0 or greater. [Meters]
         * @param stiffness  Spring stiffness, must be greater than 0. [Newton/Meter]
         * @param coeffDamping Spring damping coefficent, must be 0 or greater. [Unitless]
        */
        Spring1D(Particle1D *particleA, Particle1D *particleB, double restLength, double stiffness, double coeffDamping);
        Spring1D(Particle1D *particleA, Particle1D *particleB, double restLength, double stiffness) : Spring1D(particleA, particleB, restLength, stiffness, 0.0) {}
        Spring1D(Particle1D *particleA, Particle1D *particleB, double restLength) : Spring1D(particleA, particleB, restLength, 1.0, 0.0) {}

        double getStiffness(){return stiffness_;};
        void setStiffness(double stiffness);

        double getRestLength(){return restLength_;};
        void setRestLength(double restLength);

        double getDampingCoeff(){return coeffDamping_;};
        void setDampingCoeff(double dampingCoeff);

        double getExtension();
        void setExtension(double extentionLength);

        double getSpringForce();
        void setSpringForce(double force);

        double getDampingForce();
        void setDampingForce(double force);

        double getTotalForce();
        void setTotalForce(double force);

        double getSpringEnergy();
        void setSpringEnergy(double energy);
};
