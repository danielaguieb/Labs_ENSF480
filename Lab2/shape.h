
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <cmath>
#include <string.h>
#include "point.h"

using namespace std;

class Shape {
	protected: 
		Point origin;
		char* shapeName;

	public:
		Shape(Point& o, char const* n);
		Shape(int x, int y, char const* n);
		Shape(Shape& source);
		~Shape();
		Shape& operator =(Shape& rhs);
		Point& getOrigin();
		const char* getName();
		void display();
		double distance(Shape& other);
		static double distance(Shape& the_shape, Shape& other);
		void move(double dx, double dy);

};

#endif