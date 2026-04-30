#pragma once
#include <iostream>
#include <string>

using namespace std;

class Receipt {
	int Number;
	string Date;
	double Amount;
public:
	Receipt();
	Receipt(int, string, double);
	Receipt(const Receipt&);
	~Receipt();
	int get_Number();
	void set_Number(int);
	string get_Date();
	void set_Date(string);
	double get_Amount();
	void set_Amount(double);
	void show();
};
