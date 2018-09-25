
#include "shape.h"




Shape::Shape(Point& o, char const* n):
	origin(o) {
	shapeName = new char[strlen(n)+1];
	strcpy(shapeName, n);
}

Shape::Shape(int x, int y, char const* n):
	origin(x,y) {
	shapeName = new char[strlen(n)+1];
	strcpy(shapeName, n);
}

Shape::Shape(Shape& source):origin(source.origin), 
shapeName(new char[strlen(source.shapeName)+1])
{
	if(shapeName == NULL){
		cerr << "Memory not available...";
		exit(1);
	}
	strcpy(shapeName, source.shapeName);
}

Shape::~Shape(){
	origin.point_deleted();
	delete [] shapeName;
}

Shape& Shape::operator=(Shape& rhs)
{
	if(this==&rhs)
		return *this;
	delete [] shapeName;
	shapeName = new char[strlen(rhs.shapeName)+1];
	if(shapeName == NULL){
		cerr << "Memory not available...";
		exit(1);
	}
	strcpy(shapeName, rhs.shapeName);
	origin = rhs.origin;
	return *this;
}

Point& Shape::getOrigin(){
	return origin;
}

// this const might cause issues so worry about it
const char* Shape::getName(){
	return shapeName;
}

void Shape::display(){
	cout << "Shape Name: " << getName() << "\n";
	origin.display();
}

double Shape::distance(Shape& other){
	return origin.distance(other.getOrigin());
}

double Shape::distance(Shape& the_shape, Shape& other){
	return the_shape.getOrigin().distance(other.getOrigin());
}
void Shape::move(double dx, double dy){
	origin.set_x(origin.get_x() + dx);
	origin.set_y(origin.get_y() + dy);
}

