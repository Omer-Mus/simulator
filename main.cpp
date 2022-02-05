#include <iostream>
#include "mass.h"
#include "spring.h"
#include <algorithm>
#include <functional>
std::vector<double> GRAVITY = {0,0,-9.81};
const double DT = 0.0001;
double T = 0;

void time_inc() { T += DT; }
 
auto vectorMultiplication(const std::vector <double> &, const std::vector <double> &);

int main() {
  // pos: [0,0,3], mass: 0.8 kg
  Mass m1 = Mass(0,0,1, 0.8); 
  // pos: [0,0,2], mass: 0.8 kg
  Mass m2 = Mass(0,0,2, 0.8);
  Spring s1 = Spring(m1, m2);

  std::vector<Mass> masses = {m1, m2};
  std::vector<Spring> springs = {s1};


  /**************************************************

    Part 4.a.

  **************************************************/
  //compute the F forces 
  for (auto& m: masses) {

    std::vector<double> temp;
    for (int i=0; i<3; i++) 
      temp.push_back(m.m * GRAVITY[i]);

    for (int i=0; i<3; i++)
      m.F[i] += temp[i];
    
    if (m.p[2] < 0) {
      std::vector<double> c_pos = {0,0,100'000*m.p[2]*(-1)};
      for (int i=0; i<3; i++) 
        m.F[i] += c_pos[i];
    }
  }

  //iterate over the springs
  for (auto& s : springs) { 
    double f = s.springForce();
    std::vector<double> temp;
    double magnitude = 0;
    for (int i=0; i<3; i++) {
      temp.push_back(s.m1.p[i]-s.m2.p[i]);
      magnitude += pow(s.m1.p[i]-s.m2.p[i], 2);
    }
    std::vector<double> tempUnit = temp;
    for (int i=0; i<3; i++)
      tempUnit[i] /= sqrt(magnitude);
    for (int i=0; i<3; i++) {
      tempUnit[i] *= f;
      s.m1.external[i] += tempUnit[i];
      s.m2.external[i] -= tempUnit[i];
    }
  
  }
  /**************************************************

    Part 4.b.
    
  **************************************************/

  for (auto& m : masses) {
    m.accelerate();
    m.update_position();
    
  }

  return 0;
}

auto vectorMultiplication(const std::vector<double>& v1, const std::vector<double>& v2)
{
    std::vector<double> result;
    std::transform(v1.begin(), v1.end(), v2.begin(), 
                   std::back_inserter(result), std::multiplies<double>());
    return result;
}
