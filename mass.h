#include <vector>
#include <cmath>
#include <iostream>

#ifndef MASS_H
#define MASS_H

/*
I would not include DT as a variablein Mass.h; Masses don't deal with simulations,
only simulations do, so the file where DT belongs is simulation.cpp (or main.cpp in your case)
If you want to include an update in as a member/class function, then you would pass DT as a parameter
PS: If you don't use the mass.external variable, then get rid of it.
*/
class Mass {

public:
    double m = 0;
    std::vector<double> p; //position
    std::vector<double> v; //velocity
    std::vector<double> a; //acceleration
    std::vector<double> F; //external forces
    Mass(){};
    Mass(double x, double y, double z, double mass=0.8) {
        this->m = mass;  // intialize mass
        //set intial position
        this->p.push_back(x);
        this->p.push_back(y);
        this->p.push_back(z);

        // set velocity, acceleration & Froce to 0
        for (int i=0; i < 3; i ++) {
            this->v.push_back(0);
            this->a.push_back(0);
            this->F.push_back(0); // F = a*m
        }
        // intially, gravitiy is the acceleration
    }

    ~Mass(){

    }

    // assigment operator overload
    void operator = (const Mass &M ) {
        this->m = M.m;
        this->p = M.p;
        this->a = M.a;
        this->v = M.v;
        this->F = M.F;
    }

    // calculate force
    void init_force(int x, int y, int z) {
        this->F.push_back(x*this->m);
        this->F.push_back(y*this->m);
        this->F.push_back(z*this->m);
    }

    // update velocity
    void update_velocity(const double DT, double damping) {
        for (int i = 0; i < 3; i++ ) {
            this->v[i] = this->v[i] + DT * this->a[i];
            this->v[i] *= damping;
        }
    }

    // update position
    void update_position(const double DT) {
        for (int i = 0; i < 3; i++ )
            this->p[i] = this->p[i] + DT*this->v[i];
    }

    // calculate
    void update_acceleration() {
        for (int i = 0; i < 3; i++ )
            this->a[i] = this->F[i]/this->m;
    }

    void update_damping() {
        for(int i=0; i < 3; ++i)
            this->v[i] *= 0.9999;

    }
    void print() {
        std::cout << "m " << m << "\n";

        std::cout << "sizes " << F.size() << " " << p.size() << "\n";

        for(auto& f : p)
            std::cout << "p " << f << "\n";
        for(auto& f : v)
            std::cout << "v " << f << "\n";
        for(auto& f : a)
            std::cout << "a " << f << "\n";
        for(auto& f : F)
            std::cout << "F " << f << "\n";
    }
};


#endif
