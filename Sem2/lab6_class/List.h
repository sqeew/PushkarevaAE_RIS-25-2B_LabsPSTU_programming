#pragma once
#include <iostream>
using namespace std;

class Iterator {
	friend class List;
public:
	Iterator() { elem = 0; }
	Iterator(const Iterator& it) { elem = it.elem; }
	bool operator==(const Iterator& it) {return elem == it.elem;}
	bool operator != (const Iterator& it) {return elem != it.elem;}
	void operator ++() { ++elem; }
	void operator --() { --elem; }
	void operator ++(int) { elem++; }
	void operator --(int) { elem--; }
	int& operator *() const { return*elem; }
private:
	int* elem;
};


class List{
public:
	List(int s, int k = 0);
	List(const List& a);
	~List();
	List& operator=(const List& a);
	int& operator[](int index);
	List operator+(const int k);
	int operator() ();
	friend ostream& operator<<(ostream& out, const List& a);
	friend istream& operator>>(istream& in, List& a);
	Iterator first() {return beg;}
	Iterator last() {return end;}
private:
	int size;
	int* data;
	Iterator beg;
	Iterator end;
};

