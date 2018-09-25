
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
		Rectangle(Point& o, int sa, int sb, char const* n);
		Rectangle(int x, int y, int sa, int sb, char const* n);
		Rectangle(Rectangle& source);

		void set_side_a(int toSet);
		void set_side_b(int toSet);
		double area();
		double perimeter();
		void display();
};

#endif