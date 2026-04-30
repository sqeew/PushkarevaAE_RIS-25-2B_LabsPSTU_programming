#pragma once
#include <iostream>
using namespace std;
class Pair
{
public:
	Pair(void);
	Pair(int, double);
	Pair(const Pair&);
	Pair& operator=(const Pair&);
	Pair operator+(const int k);
	friend ostream& operator << (ostream& out, const Pair&);
	friend istream& operator >>(istream& in, Pair&);
public:
	virtual ~Pair(void) {};
private:
	int first;
	double second;
};

