#include "Pair.h"

Pair::Pair() {
	first = 0; second = 0.0;
}

Pair::Pair(int a, double b) {
	first = a; second = b;
}

Pair::Pair(const Pair& p) {
	first = p.first; second = p.second;
}

Pair::~Pair() {}

Pair Pair :: operator =(const Pair& p) {
	if (&p == this) return *this;
	first = p.first; second = p.second;
	return *this;
}

Pair& Pair::operator++() {
	++first;
	return *this;
}

Pair Pair::operator++(int) {
	Pair temp = *this;
	second++;
	return temp;
}

bool Pair::operator>(const Pair& other) const {
	if (first != other.first)
		return first > other.first;
	return second > other.second;
}


bool Pair::operator<(const Pair& other) const {
	if (first != other.first)
		return first < other.first;
	return second < other.second;
}

ostream& operator<<(ostream& out, const Pair& p) {
	out << p.first << " : " << p.second << "\n";
	return out;
}

istream& operator>>(istream& in, Pair& p) {
	cout << "first?"; in >> p.first;
	cout << "second?"; in >> p.second;
	return in;
}

fstream& operator << (fstream& fout, const Pair& p) {
	fout << p.first << " " << p.second << "\n";
	return fout;
}

fstream& operator >> (fstream& fin, Pair& p) {
	fin >> p.first;
	fin >> p.second;
	return fin;
}

bool Pair :: operator==(const Pair& other) const {
	return first == other.first && second == other.second;
}