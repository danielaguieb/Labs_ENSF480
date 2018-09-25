
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
		Square(Point& o, int sa, char const* n);
		Square(int x, int y, int sa, char const* n);
		Square(Square& source);

		void set_side_a(int toSet);
		double area();
		double perimeter();
		void display();
};

#endif