#include "Pair.h"

Pair::Pair(void) {
	first = 0;
	second = 0.0;
}

Pair::Pair(int a, double b) {
	first = a;
	second = b;
}

Pair::Pair(const Pair& p) {
	first = p.first;
	second = p.second;
}

Pair& Pair::operator=(const Pair& p) {
	first = p.first;
	second = p.second;
	return *this;
}

Pair Pair::operator+(const int k) {
	int fk = first + k;
	double sk = second + k;
	Pair temp(fk, sk);
	return temp;
}

ostream& operator<<(ostream& out, const Pair& p) {
	out << p.first << ":" << p.second;
	return out;
}

istream& operator>>(istream& in, Pair& p) {
	cout << "\nfirst? "; in >> p.first;
	cout << "\nsecond? "; in >> p.second;
	return in;
}

