
#include "curveCut.h"




CurveCut::CurveCut(Point& o, double sa, double sb, double r, char const* n):
	Shape(o, n),
	Circle(o, r, n),
	Rectangle(o, sa, sb, n) {
		if(r > sa && r > sb){
			cout << "Error: radius of circle is greater than "
				 << "the smallest length of the rectangle.\n"
				 << "Terminating...";
			exit(1);
		}
	}

CurveCut::CurveCut(double x, double y, double sa, double sb, double r, char const* n):
	Shape(x, y, n),
	Circle(x, y, r, n),
	Rectangle(x, y, sa, sb, n) {
		if(r > sa && r > sb){
			cout << "Error: radius of circle is greater than "
				 << "the smallest length of the rectangle.\n"
				 << "Terminating...";
			exit(1);
		}
}

CurveCut::CurveCut(CurveCut& source):
	Shape(source.origin, source.shapeName),
	Circle(source.origin, source.get_radius(), source.shapeName),
	Rectangle(source.origin, source.get_side_a(), source.get_side_b(), source.shapeName) {
		double r = Circle::get_radius();
		double sa = Rectangle::get_side_a();
		double sb = Rectangle::get_side_b();
		if(r > sa && r > sb){
			cout << "Error: radius of circle is greater than "
				 << "the smallest length of the rectangle.\n"
				 << "Terminating...";
			exit(1);
		}
}

double CurveCut::get_side_a(){
	return Rectangle::get_side_a();
}

double CurveCut::get_side_b(){
	return Rectangle::get_side_b();
}

double CurveCut::get_radius(){
	return Circle::get_radius();
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


