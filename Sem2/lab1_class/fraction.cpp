#include <iostream>
#include <cmath>;
#include "fraction.h"
using namespace std;

void fraction::Init(int F, double S){
	first = F, second = S;
}

void fraction::Read() {
	cout << "\nfirst?"; cin >> first;
	cout << "\nsecond?"; cin >> second;
}

void fraction::Show(){
	cout << "\nfirst=" << first;
	cout << "\nsecond=" << second;
	cout << "\n";
}
double fraction::Cost(){
	return  first * second;
}