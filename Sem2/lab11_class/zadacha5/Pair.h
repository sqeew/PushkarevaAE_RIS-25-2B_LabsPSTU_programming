#pragma once
#include <iostream>
using namespace std;
class Pair {
	int first;
	double second;
public:
	Pair() { first = 0; second = 0; };
	Pair(int a, double b) { first = a; second = b; }
	Pair(const Pair& p) { first = p.first; second = p.second; }
	~Pair() {};
	int get_first() { return first; }
	double get_second() { return second; }
	void set_first(int a) { first = a; }
	void set_second(double b) { second = b; }
	//перегруженные
	Pair& operator=(const Pair&);
	Pair operator+(const Pair&);
	Pair operator-(const Pair&) const;
	Pair operator/(const int&);
	Pair& operator++();
	Pair operator++(int);
	bool operator==(const Pair& other) const;
	bool operator>(const Pair&) const;
	bool operator<(const Pair&) const;
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
};