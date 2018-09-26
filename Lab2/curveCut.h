
#ifndef CURVECUT_H
#define CURVECUT_H
#include <iostream>
#include <math.h>
#include <cmath>
#include "point.h"
#include "shape.h"
#include "square.h"
#include "rectangle.h"
#include "circle.h"

class CurveCut : public Circle, public Rectangle {
	private:

	public:
		CurveCut(Point& o, double sa, double sb, double r, char const* n);
		CurveCut(double x, double y, double sa, double sb, double r, char const* n);
		CurveCut(CurveCut& source);

		double area();
		double perimeter();
		void display();

};

#endif