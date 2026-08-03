#pragma once

class Spring1D{
    private:
        double stiffness_{1.0};
        double restLength_{1.0};
        double coeffDamping_{0.0};
        double anchorPos_{0.0};
        double particlePos_{0.0};
        double extension_{0.0};
        double force_{0.0};

    public:
        Spring1D(double anchorPos, double particlePos, double restLength, double stiffness, double coeffDamping);
        Spring1D(double anchorPos, double particlePos, double restLength, double stiffness) : Spring1D(anchorPos, particlePos, restLength, stiffness, 0.0) {}
        Spring1D(double anchorPos, double particlePos, double restLength) : Spring1D(anchorPos, particlePos, restLength, 1.0, 0.0) {}

        double getStiffness(){return stiffness_;};
        void setStiffness(double stiffness);

        double getRestLength(){return restLength_;};
        void setRestLength(double restLength);

        double getDampingCoeff(){return coeffDamping_;};
        void setDampingCoeff(double dampingCoeff);

        double getAnchorPosition(){return anchorPos_;};
        void setAnchorPos(double anchorPos);

        double getParticlePosition(){return particlePos_;};
        void setParticlePos(double particlePos);

        double getExtension();
        void setExtension(double extentionLength);

        double getSpringForce();
        void setSpringForce(double force);
};
