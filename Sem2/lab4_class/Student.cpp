#include "Student.h"

Student::Student(void) :Person() {
	year = 0;
}

Student::~Student(void) {
}

Student::Student(string n, int a, int  y) :Person(n, a) {
	year = y;
}

Student::Student(const Student& s) {
	name = s.name;
	age = s.age;
	year = s.year;
}

void Student::set_year(int y) {
	year = y;
}

void Student::reset_year(int addYear) {
	year += addYear;
}

Student& Student::operator=(const Student& s) {
	if (&s == this) return  *this;
	name = s.name;
	age = s.age;
	year = s.year;
	return *this;
}

istream& operator>>(istream& in, Student& s) {
	cout << "\nName: "; in >> s.name;
	cout << "\nAge: "; in >> s.age;
	cout << "\nYear: "; in >> s.year;
	return in;
}

ostream& operator<<(ostream& out, const Student& s) {
	out << "\nName: " << s.name;
	out << "\nAge: " << s.age;
	out << "\nYear: " << s.year;
	return out;
}
