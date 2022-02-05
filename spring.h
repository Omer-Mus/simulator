#include "mass.h"
#include <cmath>  
#ifndef SPRING_H
#define SPRING_H

class Spring {
public:
  double L0 = 0;
  double K = 10'000;
  Mass m1 = Mass(0,0,0,0);
  Mass m2 = Mass(0,0,0,0);

  Spring(Mass m1, Mass m2, double K = 10'000) {
    m1 = m1;
    m2 = m2;
    K = K;
    L0 = sqrt(pow((m1.p[0] - m2.p[0]), 2) + pow(m1.p[1] - m2.p[1], 2) + pow(m1.p[2] - m2.p[2], 2));
  }

  double springForce() {
    double L = sqrt(pow((m1.p[0] - m2.p[0]), 2) + pow(m1.p[1] - m2.p[1], 2) + pow(m1.p[2] - m2.p[2], 2));
    return K * (L - L0);
  }
  ~Spring() {}

};

#endif
