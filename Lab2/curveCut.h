
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
		CurveCut(Point& o, int sa, int sb, int r, char const* n);
		CurveCut(int x, int y, int sa, int sb, int r, char const* n);
		CurveCut(CurveCut& source);

		int area();
		int perimeter();
		void display();

};

#endif