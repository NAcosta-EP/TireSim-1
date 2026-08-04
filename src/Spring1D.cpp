#include "Spring1D.hpp"

#include <stdexcept>

/**
 * @brief 1D Spring Physics Object
 * @param anchorPos Anchor Position of Spring [Meters]
 * @param particlePos Position of Particle end of spring <- Pass in Particle Pos [Meters]
 * @param restLength Resting length of the spring, must be 0 or greater. [Meters]
 * @param stiffness  Spring stiffness, must be greater than 0. [Newton/Meter]
 * @param coeffDamping Spring damping coefficent, must be 0 or greater. [Unitless]
*/
Spring1D::Spring1D(double anchorPos, double particlePos, double restLength, double stiffness, double coeffDamping)
    : anchorPos_{anchorPos}, particlePos_{particlePos}
{

    setRestLength(restLength);
    setStiffness(stiffness);
    setDampingCoeff(coeffDamping);


}

void Spring1D::setStiffness(double stiffness){
    if(stiffness <= 0.0){
        throw std::invalid_argument("Spring stiffness must greater than 0.");
    }
    stiffness_ = stiffness;
}

void Spring1D:: setRestLength(double restLength){
    if(restLength < 0.0){
        throw std::invalid_argument("Rest length must be greater than 0.");
    }
    restLength_ = restLength;
}

void Spring1D::setDampingCoeff(double coeffDamping){
    if(coeffDamping < 0.0){
        throw std::invalid_argument("Spring stiffness must be equal to or greater than 0.");
    }

    coeffDamping_ = coeffDamping;
}

void Spring1D::setParticlePos(double particlePosition){
    particlePos_ = particlePosition;
}

double Spring1D::getExtension(){
    //Length_ext - Length_rest
    extension_ = abs(particlePos_ - anchorPos_) - restLength_;
    return extension_;
}

double Spring1D::getSpringForce(){
    // Hooke's Law F = -k*del_L*directionCoeff
    int dir = 1;

    if(particlePos_ < anchorPos_){
        dir = -dir;
    }

    force_ = -stiffness_*getExtension()*dir;
    return force_;
}