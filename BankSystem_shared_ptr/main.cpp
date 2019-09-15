#include "pch.h"
#include "DataBase.h"
#include <tuple>


class A {
	static int _counter;

public:
	A() {
		++_counter;
	}

	~A() {
		--_counter;
	}

	static int counter() {
		return _counter;
	}
};

int A::_counter = 0;


class Person {
	string name;
	int age;
public:
	void sayHello() const {
		cout << "I'm " << name;
	}
};

void introduce(const Person& p) {
	cout << "This is our new employee\n";
	p.sayHello();


	////////////////

	const string text = "ala ma kota";
	cout << text.front();
	//text += 'R';

}

class C {
public:
	C() { 
		cout << "C()\n"; 
	}
	C(int i, char c) {
		cout << "C(" << i << "," << c << ")\n"; 
	}
	~C() { 
		cout << "~C()\n"; 
	}
};

shared_ptr<C> create() {
	int i;
	char c;
	cin >> i >> c;
	return make_shared<C>(i, c);
}

void f(shared_ptr<C> p) {
	shared_ptr<C> p2 = p;
	//...
}

int main4() {
	shared_ptr<C> ptr = create();

	if (true) {
		shared_ptr<C> ptr2 = ptr;
		//...
		f(ptr2);
	}
	else {
		//...
	}
	//....
	return 0;
}

int main2() {
	vector<double> v = { 4,5,6 };

	//...

	for (int ptr : v) {
		cout << ptr;
	}
	return 0;
}


int main() {
	srand(time(nullptr));
	//odpalamy baze danych wchodzimy do glownego menu za pomoca run, funkcja ta zrobi manMenu-show
	//tylko to robi ta nasza funkcja main
	DataBase::instance.run(); 
	return 0;
	/*Basket b;
	b.products[0] = LEMON;*/

	/*shared_ptr<A> a = make_shared<A>();
	cout << A::counter() << endl;
	shared_ptr<A> b = make_shared<A>();
	cout << A::counter() << endl;
	shared_ptr<A> c = make_shared<A>();
	cout << A::counter() << endl;
	delete a;
	cout << A::counter() << endl;
	shared_ptr<A> d = make_shared<A>();
	cout << A::counter() << endl;
	delete b;
	cout << A::counter() << endl;
	delete d;
	cout << A::counter() << endl;
	delete c;
	cout << A::counter() << endl;*/

	
}