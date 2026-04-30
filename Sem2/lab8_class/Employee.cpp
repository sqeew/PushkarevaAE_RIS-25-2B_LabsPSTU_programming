#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(void) :Person() {
	salary = 0.0;
	post = "";
}

Employee::~Employee(void) {}

Employee::Employee(string n, int a, float s, string p) : Person(n,a){
	salary = s;
	post = p;
}

Employee::Employee(const Employee& E) {
	name = E.name;
	age = E.age;
	salary = E.salary;
	post = E.post;
}

void Employee::Set_salary(float s) {
	salary = s;
}

void Employee::Set_post(string p) {
	post = p;
}

Employee& Employee::operator=(const Employee& e) {
	if (&e == this) return *this;
	name = e.name;
	age = e.age;
	salary = e.salary;
	post = e.post;
	return *this;
}

void Employee::show() {
	cout << "\nNAME: " << name;
	cout << "\nAGE: " << age;
	cout << "\nSALARY: " << salary;
	cout << "\nPOST: " << post;
	cout << "\n";
}

void Employee::input() {
	cout << "\nNAME: "; cin >> name;
	cout << "\nAGE: "; cin >> age;
	cout << "\nSALARY: "; cin >> salary;
	cout << "\nPOST: "; cin >> post;
}