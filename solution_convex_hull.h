#ifndef SOLUTION_CONVEX_HULL_H

#include<vector>
#include<iostream>
#include"point.h"

using namespace std;


class solution_convex_hull
{
public:
    vector<int> calculate_convex_hull(int l, int r);
    solution_convex_hull();
    ~solution_convex_hull();
    solution_convex_hull(int number);
    void get_convex_hull();
    void print_convex_hull();
private:
    int n;
    Point* a;
    vector<int> ans;
};

#endif
