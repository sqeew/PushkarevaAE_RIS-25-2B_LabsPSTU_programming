#include "Receipt.h"
#include <iostream>
#include <string>

using namespace std;

Receipt::Receipt() {
	Number = 0;
	Date = "";
	Amount = 0;
	cout << "Constructor without parameters for an object " << this << endl;
}

Receipt::Receipt(int N, string D, double A) {
	Number = N;
	Date = D;
	Amount = A;
	cout << "Constructor with parameters for an object " << this << endl;
}

Receipt::Receipt(const Receipt& r) {
	Number = r.Number;
	Date = r.Date;
	Amount = r.Amount;
	cout << "Copy constructor for an object " << this << endl;
}

Receipt::~Receipt() {
	cout << "The destructor for the object "<< this << endl;
}

int Receipt::get_Number() {
	return Number;
}

string Receipt::get_Date() {
	return Date;
}

double Receipt::get_Amount() {
	return Amount;
}

void Receipt::set_Number(int N) {
	Number = N;
}

void Receipt::set_Date(string D) {
	Date = D;
}

void Receipt::set_Amount(double A) {
	Amount = A;
}

void Receipt::show() {
	cout << "Number: " << Number << endl;
	cout << "Date: " << Date << endl;
	cout << "Amount: " << Amount << endl;
}
