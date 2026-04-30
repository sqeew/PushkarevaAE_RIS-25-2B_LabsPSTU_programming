#include "Receipt.h"
#include <iostream>
#include <string>

using namespace std;

Receipt make_receipt() {
	int i;
	string s;
	double d;
	cout << "Enter the Number: ";
	cin >> i;
	cout << "Enter the Date: ";
	cin >> s;
	cout << "Enter the Amount: ";
	cin >> d;
	Receipt r(i, s, d);
	return r;
}

void print_receipt(Receipt r) {
	r.show();
}

void main() {
	Receipt r1; // without parametrs
	r1.show();

	Receipt r2(67, "15.07.2018", 1245.73); // with parametrs
	r2.show();

	Receipt r3 = r2; // copy
	r3.set_Number(42);
	r3.set_Date("8.04.2024");
	r3.set_Amount(212.344);
	print_receipt(r3);
	r1 = make_receipt();
	r1.show();
}
