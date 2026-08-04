#pragma once

#include "Particle1D.hpp"
#include <stdexcept>

class Spring1D{
    private:
        double stiffness_{1.0};
        double restLength_{1.0};
        double coeffDamping_{0.0};
        double anchorPos_{0.0};
        Particle1D *particle_;
        double extension_{0.0};
        double forceSpring_{0.0};
        double forceDamping_{0.0};
        double forceTotal_{0.0};

    public:
        Spring1D(double anchorPos, Particle1D *particle, double restLength, double stiffness, double coeffDamping);
        Spring1D(double anchorPos, Particle1D *particle, double restLength, double stiffness) : Spring1D(anchorPos, particle, restLength, stiffness, 0.0) {}
        Spring1D(double anchorPos, Particle1D *particle, double restLength) : Spring1D(anchorPos, particle, restLength, 1.0, 0.0) {}

        double getStiffness(){return stiffness_;};
        void setStiffness(double stiffness);

        double getRestLength(){return restLength_;};
        void setRestLength(double restLength);

        double getDampingCoeff(){return coeffDamping_;};
        void setDampingCoeff(double dampingCoeff);

        double getAnchorPosition(){return anchorPos_;};
        void setAnchorPos(double anchorPos);

        double getExtension();
        void setExtension(double extentionLength);

        double getSpringForce();
        void setSpringForce(double force);

        double getDampingForce();
        void setDampingForce(double force);

        double getTotalForce();
        void setTotalForce(double force);
};
