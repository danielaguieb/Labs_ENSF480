
#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include "point.h"
#include "shape.h"


using namespace std;

class Square : virtual public Shape {
	protected:
		double side_a;

	public:
		Square(Point& o, double sa, char const* n);
		Square(double x, double y, double sa, char const* n);
		Square(Square& source);

		void set_side_a(double toSet);
		double get_side_a();
		double area();
		double perimeter();
		void display();
};

#endif