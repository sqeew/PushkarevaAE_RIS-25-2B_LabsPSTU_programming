#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Vector.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	int add;
	Vector v(3);
	Person a;
	cin >> a;
	Student s;
	cin >> s;
	Object* p = &a;
	v.Add(p);
	p = &s;
	v.Add(p);
	cout << v;
	cout << "\nEnter the number of years you want to increase the year: "; cin >> add;
	s.reset_year(add);
	cout << s;
	cout << "\nEnter the year for reset:"; cin >> add;
	s.set_year(add);
	cout << s;
	return 0;
}
