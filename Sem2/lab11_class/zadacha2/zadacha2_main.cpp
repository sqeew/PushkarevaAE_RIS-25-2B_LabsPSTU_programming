#include "Pair.h"
#include <iostream>
#include <list>
#include <cstdlib>
using namespace std;

typedef list<Pair>lis;

lis make_list(int n) {
	lis l;
	for (int i = 0; i < n; i++) {
		int a = rand() % 100 - 50;
		double b = (rand() % 100) / 10.0;
		l.push_back(Pair(a, b));
	}
	return l;
}

void print_list(lis l) {
	for (Pair x : l) {
		cout << x << " ";
	}
	cout << endl;
}

Pair srednee(lis l) {
	if (l.empty()) return Pair(0, 0);
	Pair s (0, 0);
	for (Pair x : l) {
		s = x + s;
	}
	int n = l.size();
	return s / n;
}

void zad3(lis& l, Pair sr, int n) {
	if (n < 0) n = 0;
	if (n >= l.size()) n = l.size() - 1;
	list<Pair>::iterator it = l.begin();
	for (int i = 0; i < n; i++) {
		++it;
	}
	*it = sr;
}

void zad4(lis& l, Pair key, int b, int e) {
	if (b < 0) b = 0;
	if (e >= l.size()) e = l.size() - 1;
	if (b > e) return;
	auto it = l.begin();
	for (int i = 0; i < b; i++) ++it;
	for (int i = b; i <= e; i++) {
		list<Pair>::iterator current = it;
		++it;
		if (*current == key) {
			l.erase(current);
		}
	}
}

void zad5(lis& l, Pair sr) {
	for (Pair& x : l) {
		x = x - sr;
	}
}

int main() {
	try {
		list<Pair> l;
		cout << "===Zadacha #2===" << endl;
		int n, k, b, e;
		cout << "N? "; cin >> n;
		l = make_list(n);
		print_list(l);
		Pair sr = srednee(l);
		cout << "===Zadanie #3===" << endl;
		cout << "Enter the position: "; cin >> k;
		zad3(l, sr, k - 1);
		print_list(l);
		cout << "===Zadanie #4===" << endl;
		Pair key;
		cout << "Enter the key: "; cin >> key;
		cout << "Enter the begining: "; cin >> b;
		cout << "Enter the end: "; cin >> e;
		zad4(l, key, b, e);
		print_list(l);
		cout << "===Zadanie #5===" << endl;
		zad5(l, sr);
		print_list(l);
	}
	catch (int) {
		cout << "Error!";
	}
	return 0;
}
