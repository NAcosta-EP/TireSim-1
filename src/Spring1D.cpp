#include "Spring1D.hpp"

/**
 * @brief 1D Spring Physics Object
 * @param anchorPos Anchor Position of Spring [Meters]
 * @param particle Particle at end of spring <- Pass in Particle address.
 * @param restLength Resting length of the spring, must be 0 or greater. [Meters]
 * @param stiffness  Spring stiffness, must be greater than 0. [Newton/Meter]
 * @param coeffDamping Spring damping coefficent, must be 0 or greater. [Unitless]
*/
Spring1D::Spring1D(Particle1D *particleA, Particle1D *particleB, double restLength, double stiffness, double coeffDamping)
    : particleA_{particleA}, particleB_{particleB}
{

    if(particleA == NULL){
        particleA_ = new Particle1D{1.0,0.0,0.0};
    }

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

double Spring1D::getExtension(){
    //Length_ext - Length_rest
    extension_ = abs(particleB_->state().position - particleA_->state().position) - restLength_;
    return extension_;
}

double Spring1D::getSpringForce(){
    // Hooke's Law F = -k*del_L*directionCoeff
    int dir = 1;

    if(particleB_->state().position < particleA_->state().position){
        dir = -dir;
    }

    forceSpring_ = -stiffness_*getExtension()*dir;
    return forceSpring_;
}

double Spring1D::getDampingForce(){
    forceDamping_ = -coeffDamping_*(abs(particleA_->state().velocity) + abs(particleB_->state().velocity));
    return forceDamping_;
}

double Spring1D::getTotalForce(){
    return forceTotal_ = getSpringForce() + getDampingForce();
}

double Spring1D::getSpringEnergy(){
    return springEnergy_ = 0.5*stiffness_*extension_*extension_;
}