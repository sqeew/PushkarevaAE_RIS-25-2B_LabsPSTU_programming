#include "List.h"
#include <iostream>
using namespace std;
int main() {
	try {
		List x(6);
		List y;
		cout << x;
		cout << "Number?";
		int i;
		cin >> i;
		cout << x[i] << endl;
		List z = x + 3;
		cout << z << endl;
		++x;
		cout << x << endl;
	}
	catch (int) {
		cout << "Error!" << endl;
	}
	return 0;
}
