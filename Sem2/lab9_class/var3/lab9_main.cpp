#include "List.h"
#include "error.h"
#include <iostream>

using namespace std;
int main() {

	try {
		List x(30);
		x[0] = 1;
		x[1] = 2;
		x[2] = 3;
		x[3] = 4;
		x[4] = 5;
		x[5] = 6;
		List y;
		cout << x;
		cout << "Number?";
		int i;
		cin >> i;
		cout << "x[" << i << "] = " << x[i] << endl;
		y = x + 3;
		cout << y;
		++x;
		cout << "Size of x: " << x() << endl;
	}
	catch (Error& e) {
		e.what();
	}
	return 0;
}
