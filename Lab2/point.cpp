
#include "point.h"




int Point::pointCounter = 0;
int Point::p_idPool = 1000;

Point::Point(double xcord, double ycord){
	x = xcord;
	y = ycord;
	id = new_id_needed();
	pointCounter++;
}

Point::Point(Point& source){
	x = source.x;
	y = source.y;
	id = new_id_needed();
	pointCounter++;
}

Point& Point::operator =( Point& rhs){
	if(this != &rhs){
		x = rhs.x;
		y = rhs.y;
	}
	return *this;

}

void Point::display(){
	cout << setprecision(2) << fixed;

	cout << "X-coordinate: " << x << "\n";
	cout << "Y-coordinate: " << y << "\n";
}

void Point::set_x(double toSetTo){
	x = toSetTo;
}

void Point::set_y(double toSetTo){
	y = toSetTo;
}

const double Point::get_x(){
	return x;
}

const double Point::get_y(){
	return y;
}

const int Point::get_id(){
	return id;
}

/*------------------------------------------------------------*/

int Point::counter(){
	return pointCounter;
}

double Point::distance(Point& other){
	double x_dist = x - other.get_x();
	double y_dist = y - other.get_y();

	return sqrt(pow(x_dist, 2) + pow(y_dist, 2));
}

double Point::distance(Point a, Point b){
	double x_dist = a.get_x() - b.get_x();
	double y_dist = a.get_y() - b.get_y();

	return sqrt(pow(x_dist, 2) + pow(y_dist, 2));
}

void Point::point_deleted(){
	pointCounter--;
}

// whenever a new point is made, it needs a new id
// so, we up the counter and retun a fresh id
int Point::new_id_needed(){
	return ++p_idPool;
}