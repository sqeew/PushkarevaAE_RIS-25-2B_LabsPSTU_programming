#pragma once
#include <iostream>
using namespace std;
const int MAX_SIZE = 30;
class List{
	int* data;
	int size;
public:
	List();
	List(int s);
	List(int s, int* d);
	List(const List&);
	~List();
	const List& operator=(const List& l);
	int& operator[](int i);
	int operator()() const;
	List operator+(int num) const;;
	List& operator++();
	List operator++(int);
	friend ostream& operator<<(ostream& out, const List&l);
	friend istream& operator>>(istream& in, List& l);
};

