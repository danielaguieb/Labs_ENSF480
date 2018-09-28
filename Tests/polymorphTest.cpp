
#include <iostream>

using namespace std;

class Base {
public:
	void fun(){
		cout << "Base fun\n";
	}
};

class Derive : public Base {
public:
	void fun(){
		cout << "Derive fun\n";
	}
};

class Base2 {
public:
	virtual void fun(){
		cout << "Base2 fun\n";
	}
};

class Derive2 : public Base2 {
public:
	// implied virtual even without the tag
	virtual void fun(){
		cout << "Derive2 fun\n";
	}
};

class PV {
public:
	void virtual bar() = 0;
};

void PV::bar(){
		cout << "Base bar\n";
}

class DerivePV : public PV {
public:
	virtual void bar(){
		cout << "DerivePV bar\n";
	}
};


class D_Base {
private:
	char * ch;
public:
	D_Base(){
		ch = new char[10];
		cout << "D_Base allocated mem\n";
	}
	virtual ~D_Base() = 0;
	// {
	// 	delete ch;
	// 	cout << "D_Base destructed mem\n";
	// }
};

D_Base::~D_Base()
	{
		delete ch;
		cout << "D_Base destructed mem\n";
	}

class D_Derived : public D_Base {
private:
	char * ch2;
public:
	D_Derived(){
		ch2 = new char[10];
		cout << "D_Derived allocated mem\n";
	}
	virtual ~D_Derived(){
		delete ch2;
		cout << "D_Derived destructed mem\n";
	}
};

int main() {

	#if 0
	PV *pv = new DerivePV();
	pv -> bar();
	pv -> PV::bar();
	#endif

	// D_Base *db = new D_Base();
	D_Base *dd = new D_Derived();

	// delete db;
	delete dd;

	#if 0
	Base b;
	Derive d;

	// should print out base one
	b.fun();
	// should print derived one
	d.fun();

	Base2 b2;
	Derive2 d2;

	// same as above?
	b2.fun();
	d2.fun();


	Base *bptr = &b;
	Base *dptr = &d;

	// NO
	// Derive *x = &b;

	// outputs same as case 1
	// "Base fun"
	// "Derive fun"
	bptr -> fun();
	dptr -> fun();


	Base2 *bptr2 = &b2;
	Base2 *dptr2 = &d2;

	// outputs same as case 1
	// "Base fun"
	// "Derive fun"
	bptr2 -> fun();
	dptr2 -> fun();

	#endif

	return 0;
}