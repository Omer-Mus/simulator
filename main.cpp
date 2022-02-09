/*
 * main.cpp
 * Runs simulation
 * find a way to visualize your output, for now it doesn't have to be high-fidelity
 * You could literally just write your spring end locations to a text file that you can load in python and render into a video, for example.
 * You just need to be able to see what is going on, so you know if your simulation is working.
 * See the rest of my comments below
 * The next step is to run this, and see if it works, you can also print the coordinates, and see if looks correct, e.g. if the positions move vertically, fall on the plain and then rise up again.
 */

#include <iostream>
#include "mass.h"
#include "spring.h"
#include <algorithm>
#include <functional>
#include <fstream>
#include <string>
#include <iterator>


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
    int c = 0;
    //<Start Simulation Loop>
    while (T < 5) {
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
          s.m1.F[i] += tempUnit[i];
          s.m2.F[i] -= tempUnit[i];
        }

        if (c == 50) {
            std::vector<double> f(s1.getVec1());
            std::vector<double> d(s1.getVec2());


            std::ofstream fs("mass1.csv");
            std::ostream_iterator<std::string> res1(fs, " ");
            std::copy(f.begin(), f.end(), res1);


            std::ofstream fs2("mass2.csv");
            std::ostream_iterator<std::string> res(fs2, " ");
            std::copy(d.begin(), d.end(), res);
            c = 0;
        }
        time_inc();
        c++;

      }
      /**************************************************
        Part 4.b.
      **************************************************/

      for (auto& m : masses) {
        m.update_acceleration();
        m.update_velocity(DT);
        m.update_position(DT);
      }


    } //<end Simulation Loop>
    return 0;
}

auto vectorMultiplication(const std::vector<double>& v1, const std::vector<double>& v2)
{
    std::vector<double> result;
    std::transform(v1.begin(), v1.end(), v2.begin(),
                   std::back_inserter(result), std::multiplies<double>());
    return result;
}
