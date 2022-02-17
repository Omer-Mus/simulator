//
//
#include <iostream>
#include "mass.h"
#include "spring.h"
#include <algorithm>
#include <functional>
#include <fstream>
#include <iterator>

#ifndef SIMULATION_SIMULATION_H
#define SIMULATION_SIMULATION_H


class Simulation {
private:
    std::vector<float> GRAVITY = {0,0,-9.81};
    float lim = 0;
    float T = 0;
    float DT;
    Spring s1;
    Mass mass1;
    Mass mass2;
    std::string f1;
    std::string f2;

    void time_inc() { T += DT; }
public:
    Simulation(float time, float time_d, std::string filem1, std::string filem2)
    {
        lim = time;
        DT = time_d;
        f1 = filem1;
        f2 = filem2;
    }

    void spring_init(Mass& m1, Mass& m2, int K=1000) { s1 = Spring(m1, m2, K); }

    void simulate()
    {
        std::ofstream fs1(f1);
        std::ofstream fs2(f2);
        std::vector<Mass> masses = {&mass1, &mass2};
        std::vector<Spring> springs = {s1};

        int c = 0;
        //<Start Simulation Loop>
        while (T < lim) {
            /**************************************************
              Part 4.a.
            **************************************************/
            //compute the F forces
            for (auto& s : springs) {

                std::vector<float> temp1;
                std::vector<float> temp2;
                for (int i=0; i<3; i++) {
                    temp1.push_back(s.m1.m * GRAVITY[i]);
                    temp2.push_back(s.m2.m * GRAVITY[i]);
                }

                for (int i=0; i<3; i++) {
                    s.m1.F[i] += temp1[i];
                    s.m2.F[i] += temp2[i];
                }

                if (s.m1.p.back() < 0) {
                    std::vector<float> c_pos = {0,0,100'000*s.m1.p[2]*(-1)};
                    for (int i=0; i<3; i++)
                        s.m1.F[i] += c_pos[i];
                }

                if (s.m2.p.back() < 0) {
                    std::vector<float> c_pos = {0,0,100'000*s.m2.p[2]*(-1)};
                    for (int i=0; i<3; i++)
                        s.m2.F[i] += c_pos[i];
                }
            }

            //iterate over the springs
            for (auto& s : springs) {
                double f = s.springForce();
//            std::cout << "origin " << f << std::endl;
                std::vector<float> temp;
                double magnitude = 0;
                for (int i=0; i<3; i++) {
                    temp.push_back(s.m2.p[i]-s.m1.p[i]);
                    magnitude += pow(s.m1.p[i]-s.m2.p[i], 2);
                }
                std::vector<float> tempUnit(temp);
                for (int i=0; i<3; i++) {
//                std::cout << magnitude << " " << s.m2.p[i]-s.m1.p[i] << "\n";
                    if (magnitude <= 0) tempUnit[i] = 0;
                    else tempUnit[i] /= sqrt(magnitude);
                }
                for (int i=0; i<3; i++) {
//                std::cout << f << " " << tempUnit[i] << std::endl;
//                if (c == 3) exit(0);
                    tempUnit[i] *= f;
                    s.m1.F[i] -= tempUnit[i];
                    s.m2.F[i] += tempUnit[i];
                }

                /**************************************************
                  Part 4.b.
                **************************************************/
                for (auto& s : springs) {
                    s.m1.update_acceleration();
                    s.m1.update_velocity(DT);
                    s.m1.update_position(DT);

                    s.m2.update_acceleration();
                    s.m2.update_velocity(DT);
                    s.m2.update_position(DT);

                    if (c == 50) {
                        std::cout << T << "\n";
                        fs1 << s.m1.p[0] << "," << s.m1.p[1] << "," << s.m1.p.back() << std::endl;
                        fs2 << s.m2.p[0] << "," << s.m2.p[1] << "," << s.m2.p.back() << std::endl;
                        c =0;
                    }
                }
            }
            for(auto& s : springs) {
                s.m1.update_damping();
                s.m2.update_damping();
            }
            T += DT;
            c++;
//            std::cout << "origin " << s1.m2.p.back() << " " << s1.m1.p.back() << std::endl;
            for (auto& s : springs) {
                s.m1.F =  {0, 0, 0};
                s.m2.F = {0, 0, 0};
            }

        }
        //<end Simulation Loop>
        fs1.close();
        fs2.close();

    }

    void spit_results()
    {
//        std::string filename = "hi.py";
        std::string command = "python3 /Users/omeromer/Desktop/simulator-main/graph.py";
//        command += filename;


        FILE* in = popen(command.c_str(), "r");
        pclose(in);
    }

};
#endif //SIMULATION_SIMULATION_H
