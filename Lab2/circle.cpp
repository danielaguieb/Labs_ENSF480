
#include "circle.h"




Circle::Circle(Point& o, double r, char const* n):
	Shape(o, n),
	radius(r) {}

Circle::Circle(double x, double y, double r, char const* n):
	Shape(x, y, n),
	radius(r) {}

Circle::Circle(Circle& source):
	Shape(source.origin, source.shapeName),
	radius(source.radius) {}

double Circle::get_radius(){
	return radius;
}

void Circle::set_radius(double toSet){
	radius = toSet;
}

double Circle::area(){
	return M_PI * pow(radius, 2);
}

double Circle::perimeter(){
	return 2 * M_PI * radius;
}

void Circle::display(){
	cout << setprecision(2) << fixed;
	
	cout << "Circle Name: " << Shape::getName() << "\n"
		 << "X-coordinate: " << origin.get_x() << "\n"
		 << "Y-coordinate: " << origin.get_y() << "\n"
		 << "Radius: " << radius << "\n"
		 << "Area: " << area() << "\n"
		 << "Perimeter: " << perimeter() << "\n";
}
