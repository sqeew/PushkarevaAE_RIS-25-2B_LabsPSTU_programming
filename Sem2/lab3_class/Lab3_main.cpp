#include "Pair.h"
#include <iostream>

using namespace std;

void main() {
	Pair a;
	Pair b;
	cin >> a;
	cin >> b;
	++a;
	b++;
	if (a > a) {
		cout << "in a: first > second" << endl;
	}
	else {
		cout << "in a: first < second" << endl;
	}
	if (b < b) {
		cout << "in b: first < second" << endl;
	}
	else {
		cout << "in b: first > second" << endl;
	}

	cout << "a = (" << a <<")" << endl;
	cout << "b = (" << b << ")" << endl;
}
