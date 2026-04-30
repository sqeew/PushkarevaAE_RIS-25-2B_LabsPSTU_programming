#include "Person.h"
#include "Student.h"
#include <iostream>

using namespace std;

void f1(Person& p) {
	p.set_name("Luka");
	cout << p;
}

Person f2() {
	Student s("Neru", 16, 2009);
	return s;
}

void main() {
	int add;
	cout << "\n===Class person===" << endl;
	Person someone;
	cin >> someone;
	cout << someone;
	Person another("Hatsune Miku", 16);
	cout << another;
	someone = another;
	cout << someone;

	cout << "===Class student===" << endl;
	Student newby;
	cin >> newby;
	cout << newby;
	cout << "\nEnter the number of years you want to increase the year: "; cin >> add;
	newby.reset_year(add);
	cout << newby;
	cout << "\nEnter the year for reset:"; cin >> add;
	newby.set_year(add);
	cout << newby;

	cout << "\n===Base class functions===" << endl;
	f1(newby);
	someone = f2();
	cout << someone;
}
