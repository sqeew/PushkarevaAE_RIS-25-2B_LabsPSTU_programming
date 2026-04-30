#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Pair
{
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair();
	Pair operator =(const Pair&);
	Pair& operator++();
	Pair operator++(int);
	bool operator==(const Pair& other) const;
	bool operator>(const Pair& other) const;
	bool operator<(const Pair& other) const;
	friend ostream& operator<<(ostream& out, const Pair& p);
	friend istream& operator>>(istream& in, Pair& p);
	friend fstream& operator<<(fstream&fout, const Pair& p);
	friend fstream& operator>>(fstream&fin, Pair& p);
private:
	int first;
	double second;
};

