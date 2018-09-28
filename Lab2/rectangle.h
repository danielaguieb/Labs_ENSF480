
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "point.h"
#include "shape.h"
#include "square.h"

using namespace std;

class Rectangle : public Square {
	protected:
		double side_b;

	public:
		Rectangle(Point& o, double sa, double sb, char const* n);
		Rectangle(double x, double y, double sa, double sb, char const* n);
		Rectangle(Rectangle& source);

		void set_side_a(double toSet);
		void set_side_b(double toSet);
		double get_side_a();
		double get_side_b();
		double area();
		double perimeter();
		void display();
};

#endif