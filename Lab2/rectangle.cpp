
#include "rectangle.h"




Rectangle::Rectangle(Point& o, double sa, double sb, char const* n): 
	Shape(o, n),
	Square(o, sa, n),
	side_b(sb) {}

Rectangle::Rectangle(double x, double y, double sa, double sb, char const* n):
	Shape(x, y, n),
	Square(x, y, sa, n),
	side_b(sb) {}

Rectangle::Rectangle(Rectangle& source):
	Shape(source.origin, source.shapeName),
	Square(source.origin, source.side_a, source.shapeName),
	side_b(source.side_b) {}

void Rectangle::set_side_a(double toSet){
	Square::set_side_a(toSet);
}

void Rectangle::set_side_b(double toSet){
	side_b = toSet;
}

double Rectangle::get_side_a(){
	return Square::get_side_a();
}

double Rectangle::get_side_b(){
	return side_b;
}

double Rectangle::area(){
	return side_a * side_b;
}

double Rectangle::perimeter(){
	return 2*side_a + 2*side_b;
}

void Rectangle::display(){
	cout << setprecision(2) << fixed;
	
	cout << "\nRectangle Name: " << Shape::getName() << "\n"
		 << "X-coordinate: " << origin.get_x() << "\n"
		 << "Y-coordinate: " << origin.get_y() << "\n"
		 << "Side a: " << side_a << "\n"
		 << "Side b: " << side_b << "\n"
		 << "Area: " << area() << "\n"
		 << "Perimeter: " << perimeter() << "\n";
}