
#include "curveCut.h"




CurveCut::CurveCut(Point& o, double sa, double sb, double r, char const* n):
	Circle(o, r, n),
	Rectangle(o, sa, sb, n) {
		if(r > sa && r > sb){
			cout << "Error: radius of circle is greater than " <<
				 << "the smallest length of the rectangle.\n"
				 << "Terminating...";
			exit(1);
		}
		Shape(o, n);
	}

CurveCut::CurveCut(double x, double y, double sa, double sb, double r, char const* n):
	Circle(x, y, r, n),
	Rectangle(x, y, sa, sb, n) {
		if(r > sa && r > sb){
			cout << "Error: radius of circle is greater than " <<
				 << "the smallest length of the rectangle.\n"
				 << "Terminating...";
			exit(1);
		}
		Shape:(x, y, n);
}

CurveCut::CurveCut(CurveCut& source):
	Circle(source.origin, source.shapeName),
	Rectangle(source.origin, source.shapeName) {
		double r = Circle::get_radius();
		double sa = Rectangle::get_side_a();
		double sb = Rectangle::get_side_b();
		if(r > sa && r > sb){
			cout << "Error: radius of circle is greater than "
				 << "the smallest length of the rectangle.\n"
				 << "Terminating...";
			exit(1);
		}
		Shape(source.origin, source.shapeName);
}

double CurveCut::area(){
	double rect_a = Rectangle::area();
	double circ_a = Circle::area();

	return rect_a - (circ_a/4);
}

double CurveCut::perimeter(){
	double rect_p = Rectangle::perimeter();
	double circ_p = Circle::perimeter();
	double circ_r = Circle::get_radius();

	return rect_p - (2*circ_r) + (circ_p/4);
}

void CurveCut::display(){
	cout << setprecision(2) << fixed;

	cout << "CurveCut Name: " << Shape::getName() << "\n"
		 << "X-coordinate: " << origin.get_x() << "\n"
		 << "Y-coordinate: " << origin.get_y() << "\n"
		 << "Width: " << Rectangle::get_side_a() << "\n"
		 << "Length: " << Rectangle::get_side_b() << "\n"
		 << "Radius of the cut:" << Circle::get_radius() << "\n";
}


