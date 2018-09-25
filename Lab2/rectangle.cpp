
#include "rectangle.h"




Rectangle::Rectangle(Point& o, int sa, int sb, char const* n): 
	Square(o, sa, n), 
	side_b(sb) {}

Rectangle::Rectangle(int x, int y, int sa, int sb, char const* n):
	Square(x, y, sa, n),
	side_b(sb) {}

Rectangle::Rectangle(Rectangle& source):
	Square(source.origin, source.side_a, source.shapeName),
	side_b(source.side_b) {}

void Rectangle::set_side_a(int toSet){
	Square::set_side_a(toSet);
}

void Rectangle::set_side_b(int toSet){
	side_b = toSet;
}

double Rectangle::area(){
	return side_a * side_b;
}

double Rectangle::perimeter(){
	return 2*side_a + 2*side_b;
}

void Rectangle::display(){
	cout << setprecision(2) << fixed;
	
	cout << "Rectangle Name: " << Shape::getName() << "\n"
		 << "X-coordinate: " << origin.get_x() << "\n"
		 << "Y-coordinate: " << origin.get_y() << "\n"
		 << "Side a: " << side_a << "\n"
		 << "Side b: " << side_b << "\n"
		 << "Area: " << area() << "\n"
		 << "Perimeter: " << perimeter() << "\n";
}