
#include "square.h"




Square::Square(Point& o, int sa, char const* n):
	Shape(o, n), 	
	side_a(sa) {}

Square::Square(int x, int y, int sa, char const* n):
	Shape(x, y, n),
	side_a(sa) {}

Square::Square(Square& source):
	Shape(source.origin, source.shapeName),
	side_a(source.side_a) {}


void Square::set_side_a(int toSet){
	side_a = toSet;
}

double Square::area(){
	return side_a * side_a;
}

double Square::perimeter(){
	return side_a * 4;
}

void Square::display(){
	cout << setprecision(2) << fixed;
	
	cout << "Square Name: " << Shape::getName() << "\n"
		 << "X-coordinate: " << origin.get_x() << "\n"
		 << "Y-coordinate: " << origin.get_y() << "\n"
		 << "Side a: " << side_a << "\n"
		 << "Area: " << area() << "\n"
		 << "Perimeter: " << perimeter() << "\n";
}
