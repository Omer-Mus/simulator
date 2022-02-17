#include "mass.h"
#include <cmath>
#include <iostream>

#ifndef SPRING_H
#define SPRING_H

class Spring {
public:
    float L0 = 0;
    float K = 1000;
    Mass m1 = Mass(0,0,1,0.8);
    Mass m2 = Mass(0,0,2,0.8);

    Spring(){}
    Spring(Mass &m1, Mass &m2, float K_c = 1000) {
        m1 = m1;
        m2 = m2;
        K = K_c;
        L0 = sqrt(pow(abs(m1.p[0] - m2.p[0]), 2) + pow(abs(m1.p[1] - m2.p[1]), 2) + pow(abs(m1.p[2] - m2.p[2]), 2));
    }
    void operator = (const Spring &S ) {
        m1 = S.m1;
        m2 = S.m2;
        K = S.K;
        L0 = S.L0;
    }
    double springForce() {
//        std::cout << m1.p[0] << " " <<  m2.p[0] << "\n";
//        std::cout << m1.p[1] << " " <<  m2.p[1] << "\n";
//        std::cout << m1.p[2] << " " << m2.p[2] << "\n\n";
        double powers = pow(abs(m1.p[0] - m2.p[0]), 2) + pow(abs(m1.p[1] - m2.p[1]), 2) + pow(abs(m1.p[2] - m2.p[2]), 2);
//        std::cout << powers << "\n";

//        if (!powers || isnan(powers)) return K*(0 - L0);
        float L = sqrt(powers);
//        std::cout << L << " " << L0 << " " << K * (L - L0) << "\n";
        return K * (L0 - L);
    }
    std::vector<float> getVec1() {
        std::vector<float> v(m1.p.begin(), m1.p.end());
        return v;
    }
    std::vector<float> getVec2() {
        std::vector<float> v(m2.p.begin(), m2.p.end());
        return v;
    }
    ~Spring() {}

};

#endif
