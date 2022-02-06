#include <vector>

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
  double m=0;
  std::vector<double> p; //position
  std::vector<double> v; //velocity
  std::vector<double> a; //acceleration
  std::vector<double> F; //external forces

  Mass(double x, double y, double z, double m) {
    m = m;  // intialize mass
    //set intial position
    p.push_back(x);
    p.push_back(y);
    p.push_back(z);

    // set velocity, acceleration & Froce to 0
    for (int i=0; i < 3; i ++) {
      v.push_back(0);
      a.push_back(0);
      F.push_back(0); // F = a*m
    }
    // intially, gravitiy is the acceleration
  }

  ~Mass(){ 

  }
  
  // assigment operator overload
  void operator = (const Mass &M ) { 
    m = M.m;
    p = M.p;
    a = M.a;
    v = M.v;
    F = M.F;
  }

  // calculate force
  void init_force(int x, int y, int z) {
    F.push_back(x*m);
    F.push_back(y*m);
    F.push_back(z*m);
  }

  // update velocity
  void update_velocity() {
    for (int i = 0; i < 3; i++ ) {
      v[i] = v[i] + DT*a[i];
    }
  }

  // update position 
  void update_position(const double DT) {
    for (int i = 0; i < 3; i++ ) {
      p[i] = p[i] + DT*v[i];
    }
  }

  // calculate
  void update_acceleration(const double DT) {
    for (int i = 0; i < 3; i++ ) {
      a[i] = F[i]/m;
    }
  }

};


#endif
