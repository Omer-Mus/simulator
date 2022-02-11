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
#include <iterator>


std::vector<float> GRAVITY = {0,0,-9.81};
const float DT = 0.00001;
float T = 0;

void time_inc() { T += DT; }

auto vectorMultiplication(const std::vector <float> &, const std::vector <float> &);

int main() {
    // pos: [0,0,3], mass: 0.8 kg
    Mass m1 = Mass(0,0,1, 0.8);
    // pos: [0,0,2], mass: 0.8 kg
    Mass m2 = Mass(0,0,2, 0.8);
    Spring s1 = Spring(m1, m2);

    std::vector<Mass> masses = {m1, m2};
    std::vector<Spring> springs = {s1};
    int c = 0;

    std::ofstream fs1("mass1.csv");
    std::ofstream fs2("mass2.csv");

    //<Start Simulation Loop>
    while (T < 4) {
        /**************************************************
          Part 4.a.
        **************************************************/
        //compute the F forces
        for (auto& m: masses) {

            std::vector<float> temp;
            for (int i=0; i<3; i++)
                temp.push_back(m.m * GRAVITY[i]);

            for (int i=0; i<3; i++)
                m.F[i] += temp[i];

            if (m.p[2] < 0) {
                std::vector<float> c_pos = {0,0,100'000*m.p[2]*(-1)};
                for (int i=0; i<3; i++)
                    m.F[i] += c_pos[i];
            }
        }

        //iterate over the springs
        for (auto& s : springs) {
            double f = s.springForce();
            std::vector<float> temp;
            double magnitude = 0;
            for (int i=0; i<3; i++) {
                temp.push_back(s.m1.p[i]-s.m2.p[i]);
                magnitude += pow(s.m1.p[i]-s.m2.p[i], 2);
            }
            std::vector<float> tempUnit = temp;
            for (int i=0; i<3; i++)
                tempUnit[i] /= sqrt(std::abs (magnitude));
            for (int i=0; i<3; i++) {
                tempUnit[i] *= f;
                s.m1.F[i] += tempUnit[i];
                s.m2.F[i] -= tempUnit[i];
            }

            /**************************************************
              Part 4.b.
            **************************************************/
            bool flag = true;
            for (auto& m : masses) {
                m.update_acceleration();
                m.update_velocity(DT);
                m.update_position(DT);
                if (c == 50) {
                    if (flag == true) {
                        fs1 << 0 << " " << 0 << " " << m.p.back() << std::endl;
                        flag = false;
                    } else {
                        fs2 << 0 << " " << 0 << " " << m.p.back() << std::endl;
                    }
                }
            }
            if (!flag) c =0;

            time_inc();
            c++;

        }
    } //<end Simulation Loop>
    fs1.close();
    fs2.close();
    return 0;
}

auto vectorMultiplication(const std::vector<float>& v1, const std::vector<float>& v2)
{
    std::vector<float> result;
    std::transform(v1.begin(), v1.end(), v2.begin(),
                   std::back_inserter(result), std::multiplies<float>());
    return result;
}
