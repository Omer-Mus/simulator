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
#include <iterator>
#include "simulation.h"

//std::vector<double> GRAVITY = {0,0,-9.81};
const double DT = 0.0001;
double T = 7;
//
//void time_inc() { T += DT; }

auto vectorMultiplication(const std::vector <double> &, const std::vector <double> &);




int main()
{


    Simulation sim = Simulation(T, DT);

    std::vector<Mass> masses;
    std::vector<Spring> springs;

    // C (0.5, 0.29, 0.82)  A = (1,0,0), O (0,0,0), B (0.5, 0.87, 0)
//    masses.push_back(Mass(0,0,1, 0.8));
//    masses.push_back(Mass(3,0,1, 0.8));
//
//    masses.push_back(Mass(0.5*3,0.87*3,1, 0.8));
//    masses.push_back(Mass(0.5*3,0.29*3,0.82*3+1, 0.8));

    // back 4
    masses.push_back(Mass(0,0,1, 0.8));
    masses.push_back(Mass(0,0,2, 0.8));

    masses.push_back(Mass(1,0,1, 0.8));
    masses.push_back(Mass(1,0,2, 0.8));
    // front 4
    masses.push_back(Mass(0,1,1, 0.8));
    masses.push_back(Mass(0,1,2, 0.8));

    masses.push_back(Mass(1,1,1, 0.8));
    masses.push_back(Mass(1,1,2, 0.8));

    for (int i=0; i < masses.size()-1; ++i)
        for (int j = i + 1; j < masses.size(); ++j)
            springs.push_back(Spring(masses[i], masses[j]));

            /**
                    X   1    2   3   4   5   6   7   8
                    1   0    1   1   1   1   1   1   1
                    2   0    0   1   1   1   1   1   1
                    3   0    0   0   1   1   1   1   1
                    4   0    0   0   0   1   1   1   1
                    5   0    0   0   0   0   1   1   1
                    6   0    0   0   0   0   0   1   1
                    7   0    0   0   0   0   0   0   1
                    8   0    0   0   0   0   0   0   0
            **/
//    std::vector<Spring> sp;
//    sp.push_back(Spring(masses[0], masses[3]));
    sim.simulate(springs, masses);
//    sim.show_results();
    return 0;
}



auto vectorMultiplication(const std::vector<double>& v1, const std::vector<double>& v2)
{
    std::vector<double> result;
    std::transform(v1.begin(), v1.end(), v2.begin(),
                   std::back_inserter(result), std::multiplies<double>());
    return result;
}















//#include <iostream>
//#include "mass.h"
//#include "spring.h"
//#include <algorithm>
//#include <functional>
//#include <fstream>
//#include <iterator>
//#include "simulation.h"
//
////std::vector<double> GRAVITY = {0,0,-9.81};
//const double DT = 0.0001;
//double T = 7;
////
////void time_inc() { T += DT; }
//
//auto vectorMultiplication(const std::vector <double> &, const std::vector <double> &);
//



//int main()
//{
//    Simulation sim = Simulation(T, DT);
//    // pos: [0,0,3], mass: 0.8 kg
//    Mass m1 = Mass(0,0,1, 0.8);
//    // pos: [0,0,2], mass: 0.8 kg
//    Mass m2 = Mass(0,0,2, 0.8);
//    std::vector<Mass> ms;
//    std::vector<Spring> sp;
//    sp.push_back(Spring(m1, m2));
//    sim.simulate(sp, ms);
//    sim.show_results();
//    return 0;
//}
//
//
//
//auto vectorMultiplication(const std::vector<double>& v1, const std::vector<double>& v2)
//{
//    std::vector<double> result;
//    std::transform(v1.begin(), v1.end(), v2.begin(),
//                   std::back_inserter(result), std::multiplies<double>());
//    return result;
//}
