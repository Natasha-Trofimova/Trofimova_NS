#ifndef LIB_H
#define LIB_H
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
#include "pch.h"
using namespace std;

class Coordinates {
    public:
    int x;
    int y;
    int z = 0;
};

class Object : public Coordinates {
    public:
    int way = 0;
    vector <int> path_x, path_y;
    Object () {};
    Object (int p_x, int p_y);
    void path_print ();
    void random_walk ();
    void step_on (int p_x, int p_y);
    void current_pos_check ();
    int distance_check (int obj_x, int obj_y);
};

class UserEquipment : public Object {
    private:
    double latitude;
    double longitude;
    double R = 6371;
    public:
    vector <double> lat, lon;
    UserEquipment() : Object () {};
    UserEquipment(int p_x, int p_y);
    void path_print();
    void random_walk();
    void step_on (int p_x, int p_y);
    void current_pos_check();
};
#endif