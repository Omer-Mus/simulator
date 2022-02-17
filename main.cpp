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
#include "simulation.h"

//std::vector<float> GRAVITY = {0,0,-9.81};
const float DT = 0.0001;
float T = 7;
//
//void time_inc() { T += DT; }

auto vectorMultiplication(const std::vector <float> &, const std::vector <float> &);




int main()
{
    Simulation sim = Simulation(T, DT, "mass1.csv", "mass2.csv");
    // pos: [0,0,3], mass: 0.8 kg
    Mass m1 = Mass(0,0,1, 0.8);
    // pos: [0,0,2], mass: 0.8 kg
    Mass m2 = Mass(0,0,2, 0.8);
    sim.spring_init(m1, m2);
    sim.simulate();
    sim.spit_results();
    return 0;
}



auto vectorMultiplication(const std::vector<float>& v1, const std::vector<float>& v2)
{
    std::vector<float> result;
    std::transform(v1.begin(), v1.end(), v2.begin(),
                   std::back_inserter(result), std::multiplies<float>());
    return result;
}
