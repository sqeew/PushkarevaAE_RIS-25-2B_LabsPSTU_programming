#include "Person.h"

Person::Person(void) {
	name = "";
	age = 0;
}

Person::~Person(void) {
}

Person::Person(string N, int A) {
	name = N;
	age = A;
}

Person::Person(const Person& person) {
	name = person.name;
	age = person.age;
}

void Person::set_name(string n) {
	name = n;
}

void Person::set_age(int a) {
	age = a;
}

Person& Person::operator=(const Person& p) {
	if (&p == this) return *this;
	name = p.name;
	age = p.age;
	return *this;
}

istream& operator>>(istream& in, Person& p) {
	cout << "\nName: "; cin >> p.name;
	cout << "\nAge: "; cin >> p.age;
	return in;
}

ostream& operator<<(ostream& out, const Person& p) {
	out << "\nName: " << p.name;
	out << "\nAge: " << p.age;
	out << "\n";
	return out;
}

void Person::show() {
	cout << "\nName: " << name;
	cout << "\nAge: " << age;
	cout << "\n";
}