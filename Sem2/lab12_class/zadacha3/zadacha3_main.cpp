#include "Pair.h"
#include "List.h"
#include <iostream>

using namespace std;
int main() {
	cout << "===Zadacha #3===" << endl;
	int n, p, b, e;
	cout << "N? "; cin >> n;
	List <Pair> v(n);
	v.print();
	Pair sr = v.srednee();
	cout << "Srednee: " << sr << endl;

	cout << "===Zadanie 3===" << endl;
	cout << "Enter the position: "; cin >> p;
	v.zad3(sr, p);
	v.print();

	cout << "\n===Zadanie 4===" << endl;
	Pair key;
	cout << "Enter the key: "; cin >> key;
	cout << "Enter the begining: "; cin >> b;
	cout << "Enter the ending: "; cin >> e;
	v.zad4(key, b, e);
	v.print();

	cout << "\n===Zadanie 5===" << endl;
	sr = v.srednee();
	v.zad5(sr);
	v.print();
	return 0;
}
