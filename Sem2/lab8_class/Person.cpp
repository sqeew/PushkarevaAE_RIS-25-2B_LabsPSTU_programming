#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

Person::Person(void) {
	name = "";
	age = 0;
}

Person :: ~Person(void) {}

string Person::Get_name() const {
	return name;
}

Person::Person(string n, int a) {
	name = n;
	age = a;
}

Person::Person(const Person& p) {
	name = p.name;
	age = p.age;
}

void Person::Set_name(string n) {
	name = n;
}

void Person::Set_age(int a) {
	age = a;
}

Person& Person::operator=(const Person& p) {
	if (&p == this) return *this;
	name = p.name;
	age = p.age;
	return *this;
}

void Person::show() {
	cout << "\nName: " << name;
	cout << "\nAge: " << age;
	cout << "\n";
}

void Person::input() {
	cout << "\nName: "; cin >> name;
	cout << "\nAge: "; cin >> age;
}