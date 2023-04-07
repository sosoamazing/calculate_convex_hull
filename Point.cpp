#include<iostream>
#include<ctime>
#include<stdlib.h>
#include"Point.h"

#define N 0xfffffffe

using namespace std;

Point::Point(int op) :x(0), y(0)
{
    if (op > 0)
    {
        cin >> x >> y;
    }
}

bool Point::operator<(const Point& b)
{
    return x != b.x ? (x < b.x) : (y < b.y);
}

ostream& operator << (ostream& os,const Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

Point* get_array(Point* a, int n)
{
    a = new Point[n];
    srand((time(NULL) + clock() + (int)a) % N);
    for (int i = 0; i < n; i++)
    {
        a[i].x = (double)(rand() % 10);
        a[i].y = (double)(rand() % 10);
    }
    return a;
}

bool Point::is_in_left(Point& p, Point& q)
{
    return q.x * y + p.x * p.y + p.y * x - q.x * p.y - x * q.y - y * p.x > 0 ? true : false;
}