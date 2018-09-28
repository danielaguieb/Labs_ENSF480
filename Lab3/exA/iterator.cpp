// iterator.cpp
// ENSF 480 - Fall 2018 - Lab 3, Ex A
// M. Moussavi: Sept 26, 2018
#include <iostream>
#include <assert.h>
#include "mystring2.h"

using namespace std;


class Vector {
public: 

  class VectIter{
    friend class Vector;
  private:
    Vector *v; // points to a vector object of type T
    int index;    // represents the subscript number of the vector's
                  // array.
  public:
    VectIter(Vector& x);
 
    int operator++(){
    	index++;
    	if(index >= v->size)
    		index = 0;
    	// return *v;
    	// return v*;
    	// return v[index];
    	// return *v[index];
    	return **this;		// the proper way to use the VectIter operator *()
    }
    //PROMISES: increments the iterator's indes and return the 
    //          value of the element at the index position. If
    //          index exceeds the size of the array it will 
    //          be set to zero. Which means it will be circulated
    //          back to the first element of the vector.

    int  operator++(int){
    	int toReturn = **this;
    	index++;
    	if(index >= v->size)
    		index = 0;
    	return toReturn;
    }
    // PRIMISES: returns the value of the element at the index
    //           position, then increments the index. If
    //           index exceeds the size of the array it will 
    //           be set to zero. Which means it will be circulated
    //           back to the first element of the vector.

    int  operator--(){
    	index--;
    	if(index < 0)
    		index = v->size-1;
    	return **this;
    }
    // PROMISES: decrements the iterator index, and return the
    //           the value of the element at the index. If
    //           index is less than zero it will be set to the 
    //           last element in the aray. Which means it will be
    //           circulated to the last element of the vector.

    int  operator--(int){
    	int toReturn = **this;
    	index--;
    	if(index < 0)
    		index = v->size-1;
    	return toReturn;
    }
    // PRIMISES: returns the value of the element at the index
    //           position, then decrements the index. If
    //           index is less than zero it will be set to the 
    //           last element in the aray. Which means it will be
    //           circulated to the last element of the vector.

    int operator *();
    // PRIMISES: returns the value of the element at the current 
    //           index position.
  };

  Vector(int sz); 
  ~Vector();

  int & operator[](int i);
  // PRIMISES: returns existing value in the ith element of 
  //           array or sets a new value to  the ith element in
  //           array. 
  
	void ascending_sort();
  // PRIMISES: sorts the vector values in ascending order. 
	
private:
  int *array;               // points to the first element of an array of T
  int size;               // size of array
  void swap(int&, int &); // swaps the values of two elements in array 
};


void Vector::ascending_sort()
{
	for(int i=0; i< size-1; i++)
		for(int j=i+1; j < size; j++)
			if(array[i] > array[j])
				swap(array[i], array[j]);
}

void Vector::swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int Vector::VectIter::operator *()
{
  return v -> array[index];
}


Vector::VectIter::VectIter(Vector& x)
{
  v = &x;
  index = 0;
}



Vector::Vector(int sz)
{
  size=sz;
  array = new int [sz];
  assert (array != NULL);
}


Vector::~Vector()
{
  delete [] array;
  array = NULL;
}



int & Vector ::operator [] (int i)
{
  return array[i];
}


int main()
{

 Vector x(3);
 x[0] = 999;
 x[1] = -77;
 x[2] = 88;

 Vector::VectIter iter(x);

 cout << "\n\nThe first element of vector x contains: " << *iter; 

 // the code between the  #if 0 and #endif is ignored by
 // compiler. If you change it to #if 1, it will be compiled
 
 #if 1 // testing for int before converting to template
	cout << "\nTesting an <int> Vector: " << endl;;
	
	cout << "\n\nTesting sort";
	x.ascending_sort();
	
	for (int i=0; i<3 ; i++)
		cout << endl << iter++;
	
	cout << "\n\nTesting Prefix --:";
	for (int i=0; i<3 ; i++)
		cout << endl << --iter;
	
	cout << "\n\nTesting Prefix ++:";
	for (int i=0; i<3 ; i++)
		cout << endl << ++iter;	
	
	cout << "\n\nTesting Postfix --";
	for (int i=0; i<3 ; i++)
		cout << endl << iter--;
	
	cout << endl;
 #endif

 #if 0	//testing out how template works with string
	cout << "Testing a <String> Vector: " << endl;
	Vector<Mystring> y(3);
	y[0] = "Bar";
	y[1] = "Foo";
	y[2] = "All";;
	
	Vector<Mystring>::VectIter iters(y);
	
	cout << "\n\nTesting sort";
	y.ascending_sort();
	
	for (int i=0; i<3 ; i++)
		cout << endl << iters++;
	
	cout << "\n\nTesting Prefix --:";
	for (int i=0; i<3 ; i++)
		cout << endl << --iters;
	
	cout << "\n\nTesting Prefix ++:";
	for (int i=0; i<3 ; i++)
		cout << endl << ++iters;
	
	cout << "\n\nTesting Postfix --";
	for (int i=0; i<3 ; i++)
		cout << endl << iters--;
 #endif
	
	
#if 0	//testing how template works with char*
	cout << endl; cout << "Testing a <char *> Vector: " << endl;
	Vector<char*> z(3);
	z[0] = "Orange";
	z[1] = "Pear";
	z[2] = "Apple";;
	
	Vector<char*>::VectIter iterchar(z);
	
	cout << "\n\nTesting sort";
	z.ascending_sort();
	
	for (int i=0; i<3 ; i++)
		cout << endl << iterchar++;
#endif 
	
#endif
	cout << "\nPrgram Terminated Successfully." << endl;
	
	return 0;
}












