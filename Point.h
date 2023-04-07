#ifndef POINT_H

#include<iostream>

using namespace std;

class Point 
{
public:
	Point(int op = 0);
	bool operator<(const Point& p);
	friend ostream& operator<<(ostream& os,const Point& p);
	friend Point* get_array(Point* a, int n);
	bool is_in_left(Point& p, Point& q);
private:
	double x, y;
};
#endif // !POINT_H
