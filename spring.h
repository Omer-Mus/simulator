#include "mass.h"
#include <cmath>
#include <iostream>

#ifndef SPRING_H
#define SPRING_H

class Spring {
public:
    float L0 = 0;
    float K = 1000;
    Mass *m1;
    Mass *m2;

    Spring(){};
    Spring(Mass &m1, Mass &m2, double K_c = 1000) {
        this->m1 = &m1;
        this->m2 = &m2;
        this->K = K_c;
        this->L0 = sqrt(pow(this->m1->p[0] - this->m2->p[0], 2) + pow(this->m1->p[1] - this->m2->p[1], 2) + pow(this->m1->p[2] - this->m2->p[2], 2));
    }
    void operator = (const Spring &S ) {
        this->m1 = S.m1;
        this->m2 = S.m2;
        this->K = S.K;
        this->L0 = S.L0;
    }
    double springForce() {
//        std::cout << m1.p[0] << " " <<  m2.p[0] << "\n";
//        std::cout << m1.p[1] << " " <<  m2.p[1] << "\n";
//        std::cout << m1.p[2] << " " << m2.p[2] << "\n\n";
        double powers = pow(this->m1->p[0] - this->m2->p[0], 2) + pow(this->m1->p[1] - this->m2->p[1], 2) + pow(this->m1->p[2] - this->m2->p[2], 2);
//        std::cout << powers << "\n";

//        if (!powers || isnan(powers)) return K*(0 - L0);
        double L = sqrt(powers);
//        std::cout << L << " " << L0 << " " << K * (L - L0) << "\n";
        return this->K * (this->L0 - L);
    }

    ~Spring() {}

};

#endif
