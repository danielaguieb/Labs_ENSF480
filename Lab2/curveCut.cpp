
#include "curveCut.h"




CurveCut::CurveCut(Point& o, int sa, int sb, int r, char const* n):
	Circle(o, r, n),
	Rectangle(o, sa, sb, n) {}

CurveCut::CurveCut(int x, int y, int sa, int sb, int r, char const* n):
	Circle(x, y, r, n),
	Rectangle(x, y, sa, sb, n) {}

CurveCut::CurveCut(CurveCut& source):
	Circle(source.origin, source.shapeName),
	Rectangle(source.origin, source.shapeName){}