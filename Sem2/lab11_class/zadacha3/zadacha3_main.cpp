#include "Pair.h"
#include "List.h"
#include <iostream>
using namespace std;

int main() {
	cout << "===Zadacha #3===" << endl;
	List<Pair> l(5, Pair(0,0));
	l[0] = Pair(10, 1.5);
	l[1] = Pair(20, 2.5);
	l[2] = Pair(30, 3.5);
	l[3] = Pair(20, 4.5);
	l[4] = Pair(50, 5.5);
	l.print();
	Pair sr = l.srednee();
	cout << "===Zadanie #3===" << endl;
	int k;
	cout << "Enter the position: "; cin >> k;
	l.zad3(sr, k - 1);
	l.print();
	cout << "===Zadanie #4===" << endl;
	Pair key;
	cout << "Enter the key (first second): "; cin >> key;
	int b, e;
	cout << "Enter the begining: "; cin >> b;
	cout << "Enter the end: "; cin >> e;
	l.zad4(key, b, e);
	l.print();
	cout << "===Zadanie #5===" << endl;
	l.zad5(sr);
	l.print();
	return 0;
}
