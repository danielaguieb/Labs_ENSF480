
#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <math.h>
#include <cmath>
#include "point.h"
#include "shape.h"

using namespace std;

class Circle : public Shape {
	private:
		double radius;

	public:
		Circle(Point& o, int r, char const* n);
		Circle(int x, int y, int r, char const* n);
		Circle(Circle& source);

		int get_radius();
		void set_radius(int toSet);
		double area();
		double perimeter();
		void display();

};

#endif