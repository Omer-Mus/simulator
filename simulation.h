//#include <iostream>
//#include "mass.h"
//#include "spring.h"
//#include <algorithm>
//#include <functional>
//#include <fstream>
//#include <iterator>
//
//#ifndef SIMULATION_SIMULATION_H
//#define SIMULATION_SIMULATION_H
//
//
//class Simulation {
//private:
//    std::vector<double> GRAVITY = {0,0,-9.81};
//    double lim = 0;
//    double T = 0;
//    double DT;
//
//    void time_inc() { this->T += this->DT; }
//public:
//    Simulation(double time, double time_d)
//    {
//        this->lim = time;
//        this->DT = time_d;
//
//    }
//
//
//    void simulate(std::vector<Spring> springs, std::vector<Mass> masses)
//    {
//        std::ofstream fs1("mass1.csv");
//        std::ofstream fs2;
//        for(int trunc=2; trunc < 9; ++trunc) {
//            std::string str = "mass" + std::to_string(trunc) + ".csv";
//            fs2.open(str.c_str(), std::ofstream::out | std::ofstream::trunc);
//            fs2.close();
//        }
//        int c = 0;
//        //<Start Simulation Loop>
//        while (T < lim) {
//            /**************************************************
//              Part 4.a.
//            **************************************************/
//            //compute the F forces
//            bool f3 = true; int counter = 0;
//            for (auto& s : springs) {
//                std::vector<double> temp1;
//                std::vector<double> temp2;
//                for (int i=0; i<3; i++) {
//                    if (f3) temp1.push_back(s.m1.m * GRAVITY[i]);
//                    temp2.push_back(s.m2.m * GRAVITY[i]);
//                }
//
//                for (int i=0; i<3; i++) {
//                    if(f3) s.m1.F[i] += temp1[i];
//                    s.m2.F[i] += temp2[i];
//                }
//
//                if (s.m1.p.back() < 0) {
//                    std::vector<double> c_pos = {0,0,100'000*s.m1.p[2]*(-1)};
//                    for (int i=0; i<3; i++)
//                        s.m1.F[i] += c_pos[i];
//                }
//
//                if (s.m2.p.back() < 0) {
//                    std::vector<double> c_pos = {0,0,100'000*s.m2.p[2]*(-1)};
//                    for (int i=0; i<3; i++)
//                        s.m2.F[i] += c_pos[i];
//                }
//                f3 = false;
//                if (++counter > 8) break;
//            }
//
//            //iterate over the springs
//            counter = 0;
//            for (auto& s : springs) {
//                double f = s.springForce();
////            std::cout << "origin " << f << std::endl;
//                std::vector<double> temp;
//                double magnitude = 0;
//                for (int i=0; i<3; i++) {
//                    temp.push_back(s.m2.p[i]-s.m1.p[i]);
//                    magnitude += pow(s.m1.p[i]-s.m2.p[i], 2);
//                }
//                std::vector<double> tempUnit(temp);
//                for (int i=0; i<3; i++) {
////                std::cout << magnitude << " " << s.m2.p[i]-s.m1.p[i] << "\n";
//                    if (magnitude <= 0) tempUnit[i] = 0;
//                    else tempUnit[i] /= sqrt(magnitude);
//                }
//                for (int i=0; i<3; i++) {
////                std::cout << f << " " << tempUnit[i] << std::endl;
////                if (c == 3) exit(0);
//                    tempUnit[i] *= f;
//                    s.m1.F[i] -= tempUnit[i];
//                    s.m2.F[i] += tempUnit[i];
//                }
//
//                /**************************************************
//                  Part 4.b.
//                **************************************************/
//                bool flag = true;
//                bool flag2 = true;
//                int mass_append = 2;
//                for (auto& s : springs) {
//                    if (flag2) {
//                        s.m1.update_acceleration();
//                        s.m1.update_velocity(DT);
//                        s.m1.update_position(DT);
//                        flag2 = false;
//                    }
//
//                    s.m2.update_acceleration();
//                    s.m2.update_velocity(DT);
//                    s.m2.update_position(DT);
//
//                    if (c == 50) {
//                        if (flag) {
//                            fs1 << std::fixed << s.m1.p[0] << "," << s.m1.p[1] << "," << s.m1.p.back() << std::endl;
//                            flag = false;
//                        }
//                        std::string name = "mass" + std::to_string(mass_append) + ".csv";
//                        fs2.open(name.c_str(), std::ios_base::app);
////                        std::cout << mass_append << "\n";
//                        fs2 << std::fixed << s.m2.p[0] << "," << s.m2.p[1] << "," << s.m2.p.back() << std::endl;
//                        fs2.flush();
//                        fs2.close();
//                    }
//                    mass_append++;
//                    if(!(mass_append < 9)) break;
//                }
//                if (++counter > 8) break;
//            }
//            f3 = true;
//            for(auto& s : springs) {
//                if (f3) {
//                    s.m1.update_damping();
//                    f3 = false;
//                }
//                s.m2.update_damping();
//            }
//            T += DT;
//
//            if (c==50) c=0;
//            c++;
////            std::cout << "origin " << s1.m2.p.back() << " " << s1.m1.p.back() << std::endl;
//            for (auto& s : springs) {
//                s.m1.F = (std::vector<double>) {0, 0, 0};
//                s.m2.F = (std::vector<double>) {0, 0, 0};
//            }
//
//        }
//        //<end Simulation Loop>
//        fs1.close();
//        fs2.close();
//
//    }
//
//    void spit_results()
//    {
////        std::string filename = "hi.py";
//        std::string command = "python3 /Users/omeromer/Desktop/simulator-main/graph.py";
////        command += filename;
//
//
//        FILE* in = popen(command.c_str(), "r");
//        pclose(in);
//    }
//
//};
//#endif //SIMULATION_SIMULATION_H











//#include <iostream>
//#include "mass.h"
//#include "spring.h"
//#include <algorithm>
//#include <functional>
//#include <fstream>
//#include <iterator>
//
//#ifndef SIMULATION_SIMULATION_H
//#define SIMULATION_SIMULATION_H
//
//
//class Simulation {
//private:
//    std::vector<double> GRAVITY = {0,0,-9.81};
//    double lim = 0;
//    double T = 0;
//    double DT;
//
//    void time_inc() { this->T += this->DT; }
//public:
//    Simulation(double time, double time_d)
//    {
//        this->lim = time;
//        this->DT = time_d;
//
//    }
//
//
//    void simulate(std::vector<Spring> springs, std::vector<Mass> &masses)
//    {
//        std::ofstream fs1("mass1.csv");
//        std::ofstream fs2;
//        for(int trunc=2; trunc < 5; ++trunc) {
//            std::string str = "mass" + std::to_string(trunc) + ".csv";
//            fs2.open(str.c_str(), std::ofstream::out | std::ofstream::trunc);
//            fs2.close();
//        }
//        int c = 0;
//        //<Start Simulation Loop>
//        while (T < lim) {
//            /**************************************************
//              Part 4.a.
//            **************************************************/
//            //compute the F forces
//            bool f3 = true; int counter = 0;
//            for (auto& s : springs) {
//                std::vector<double> temp1;
//                std::vector<double> temp2;
//                for (int i=0; i<3; i++) {
//                    if (f3) temp1.push_back(s.m1->m * GRAVITY[i]);
//                    temp2.push_back(s.m2->m * GRAVITY[i]);
//                }
//
//                for (int i=0; i<3; i++) {
//                    if(f3) s.m1->F[i] += temp1[i];
//                    s.m2->F[i] += temp2[i];
//                }
//
//                if (s.m1->p.back() < 0) {
//                    std::vector<double> c_pos = {0,0,100'000*s.m1->p[2]*(-1)};
//                    for (int i=0; i<3; i++)
//                        s.m1->F[i] += c_pos[i];
//                }
//
//                if (s.m2->p.back() < 0) {
//                    std::vector<double> c_pos = {0,0,100'000*s.m2->p[2]*(-1)};
//                    for (int i=0; i<3; i++)
//                        s.m2->F[i] += c_pos[i];
//                }
//                f3 = false;
//                if (++counter > 4) break;
//            }
//
//            //iterate over the springs
//            counter = 0;
//            for (auto& s : springs) {
//                double f = s.springForce();
////            std::cout << "origin " << f << std::endl;
//                std::vector<double> temp;
//                double magnitude = 0;
//                for (int i=0; i<3; i++) {
//                    temp.push_back(s.m2->p[i]-s.m1->p[i]);
//                    magnitude += pow(s.m1->p[i]-s.m2->p[i], 2);
//                }
//                std::vector<double> tempUnit(temp);
//                for (int i=0; i<3; i++) {
////                std::cout << magnitude << " " << s.m2.p[i]-s.m1.p[i] << "\n";
//                    if (magnitude <= 0) tempUnit[i] = 0;
//                    else tempUnit[i] /= sqrt(magnitude);
//                }
//                for (int i=0; i<3; i++) {
////                std::cout << f << " " << tempUnit[i] << std::endl;
////                if (c == 3) exit(0);
//                    tempUnit[i] *= f;
//                    s.m1->F[i] -= tempUnit[i];
//                    s.m2->F[i] += tempUnit[i];
//                }
//
//                /**************************************************
//                  Part 4.b.
//                **************************************************/
//                bool flag = true;
//                bool flag2 = true;
//                int mass_append = 2;
//                for (auto& s : springs) {
//                    if (flag2) {
//                        s.m1->update_acceleration();
//                        s.m1->update_velocity(DT);
//                        s.m1->update_position(DT);
//                        flag2 = false;
//                    }
//
//                    s.m2->update_acceleration();
//                    s.m2->update_velocity(DT);
//                    s.m2->update_position(DT);
//
//                    if (c == 50) {
//                        if (flag) {
//                            fs1 << std::fixed << s.m1->p[0] << "," << s.m1->p[1] << "," << s.m1->p.back() << std::endl;
//                            flag = false;
//                        }
//                        std::string name = "mass" + std::to_string(mass_append) + ".csv";
//                        fs2.open(name.c_str(), std::ios_base::app);
////                        std::cout << mass_append << "\n";
//                        fs2 << std::fixed << s.m2->p[0] << "," << s.m2->p[1] << "," << s.m2->p.back() << std::endl;
//                        fs2.flush();
//                        fs2.close();
//                    }
//                    mass_append++;
//                    if(!(mass_append < 5)) break;
//                }
//                if (++counter > 5) break;
//            }
//            f3 = true;
//            for(auto& s : springs) {
//                if (f3) {
//                    s.m1->update_damping();
//                    f3 = false;
//                }
//                s.m2->update_damping();
//            }
//            T += DT;
//
//            if (c==50) c=0;
//            c++;
////            std::cout << "origin " << s1.m2.p.back() << " " << s1.m1.p.back() << std::endl;
//            for (auto& s : springs) {
//                s.m1->F = (std::vector<double>) {0, 0, 0};
//                s.m2->F = (std::vector<double>) {0, 0, 0};
//            }
//
//        }
//        //<end Simulation Loop>
//        fs1.close();
//        fs2.close();
//
//    }
//
//
//
//
//
//
//    void spit_results()
//    {
////        std::string filename = "hi.py";
//        std::string command = "python3 /Users/omeromer/Desktop/simulator-main/graph.py";
////        command += filename;
//
//
//        FILE* in = popen(command.c_str(), "r");
//        pclose(in);
//    }
//
//};
//#endif //SIMULATION_SIMULATION_H







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
    std::vector<double> GRAVITY = {0,0,-9.81};
    double lim = 0;
    double T = 0;
    double DT;
    double damping = 1;
    void time_inc() { this->T += this->DT; }
public:
    Simulation(double time, double time_d)
    {
        this->lim = time;
        this->DT = time_d;

    }


    void simulate(std::vector<Spring> springs, std::vector<Mass> &masses)
    {
        std::ofstream fs1("mass1.csv");
        std::ofstream fs2;
        for(int trunc=2; trunc < 9; ++trunc) {
            std::string str = "mass" + std::to_string(trunc) + ".csv";
            fs2.open(str.c_str(), std::ofstream::out | std::ofstream::trunc);
            fs2.close();
        }
        int c = 0;
        //<Start Simulation Loop>
        while (T < lim) {
            /**************************************************
              Part 4.a.
            **************************************************/
            //compute the F forces
            for (auto& m : masses) {
                std::vector<double> temp1;
                for (int i=0; i<3; i++) {
                    temp1.push_back(m.m * GRAVITY[i]);
                }

                for (int i=0; i<3; i++) {
                    m.F[i] += temp1[i];
                }

                if (m.p.back() < 0) {
                    std::vector<double> c_pos = {0,0,100'000*m.p[2]*(-1)};
                    for (int i=0; i<3; i++)
                        m.F[i] += c_pos[i];
                }

//                if (m.p.back() < 0) {
//                    std::vector<double> c_pos = {0,0,100'000*m.p[2]*(-1)};
//                    for (int i=0; i<3; i++)
//                        m.F[i] += c_pos[i];
//                }
            }

            //iterate over the springs
            for (auto& s : springs) {
                double f = s.springForce();
//            std::cout << "origin " << f << std::endl;
                std::vector<double> temp;
                double magnitude = 0;
                for (int i=0; i<3; i++) {
                    temp.push_back(s.m2->p[i]-s.m1->p[i]);
                    magnitude += pow(s.m1->p[i]-s.m2->p[i], 2);
                }
                std::vector<double> tempUnit(temp);
                for (int i=0; i<3; i++) {
//                std::cout << magnitude << " " << s.m2.p[i]-s.m1.p[i] << "\n";
                    if (magnitude <= 0) std::cout << magnitude << "\n";
                    else tempUnit[i] /= sqrt(magnitude); // move outside
                }
                for (int i=0; i<3; i++) {
//                std::cout << f << " " << tempUnit[i] << std::endl;
//                if (c == 3) exit(0);
                    tempUnit[i] *= f;
                    s.m1->F[i] -= tempUnit[i];
                    s.m2->F[i] += tempUnit[i];
                }

                /**************************************************
                  Part 4.b.
                **************************************************/
            }
            int mass_append = 1;
            for (auto& m : masses) {

                m.update_acceleration();
                m.update_velocity(DT, damping);
                m.update_position(DT);

                if (c == 50) {
                    std::string name = "mass" + std::to_string(mass_append) + ".csv";
                    fs2.open(name.c_str(), std::ios_base::app);
//                        std::cout << mass_append << "\n";
                    fs2 << std::fixed << m.p[0] << "," << m.p[1] << "," << m.p.back() << std::endl;
                    fs2.flush();
                    fs2.close();
                }
                mass_append++;
            }
//            for(auto& m : masses) {
//                m.update_damping();
//            }
            T += DT;

            if (c==50) c=0;
            c++;
//            std::cout << "origin " << s1.m2.p.back() << " " << s1.m1.p.back() << std::endl;
            for (auto& m : masses) {
                m.F = (std::vector<double>) {0, 0, 0};
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
