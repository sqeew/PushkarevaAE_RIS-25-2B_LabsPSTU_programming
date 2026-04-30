#include "List.h"
#include "Pair.h"
#include <iostream>
using namespace std;

int main() {
	List<int>A(5, 0);
	cin >> A;
	cout << A << endl;

	List<int>B(10, 1);
	cout << B << endl;

	B = A;
	cout << B << endl;

	cout << A[2] << endl;
	cout << "size = " << A() << endl;

	B = A + 10;
	cout << B << endl;

	cout << "+++Pair+++" << endl;
	Pair p;
	cin >> p;
	cout << p << endl;

	int k;
	cout << "k? "; cin >> k;
	Pair t;
	t = p + k;
	cout << t;
	return 0;
}
