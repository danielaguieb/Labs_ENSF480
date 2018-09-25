
#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


class Point{
	private:
		double x;
		double y;
		int id;

		int new_id_needed();

	public:	
		static int pointCounter;
		static int p_idPool;

		Point(double xcord, double ycord);
		Point(Point& source);
		Point& operator =(Point& rhs);
		void display();
		void set_x(double toSetTo);
		void set_y(double toSetTo);
		const double get_x();
		const double get_y();
		const int get_id();

		int counter();
		static double distance(Point a, Point b);
		double distance(Point& other);
		void point_deleted();

};

#endif