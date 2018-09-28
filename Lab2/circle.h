
#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <math.h>
#include <cmath>
#include "point.h"
#include "shape.h"

using namespace std;

class Circle : virtual public Shape {
	private:
		double radius;

	public:
		Circle(Point& o, double r, char const* n);
		Circle(double x, double y, double r, char const* n);
		Circle(Circle& source);

		double get_radius();
		void set_radius(double toSet);
		double area();
		double perimeter();
		void display();

};

#endif