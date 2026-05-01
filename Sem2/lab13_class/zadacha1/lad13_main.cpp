#include "Pair.h"
#include "list"
#include <iostream>
#include <algorithm>
using namespace std;
typedef list<Pair> TList;
Pair w;
TList make_list(int n) {
	Pair a;
	TList l;
	for (int i = 0; i < n; i++) {
		cin >> a;
		l.push_back(a);
	}
	return l;
}

void print_list(TList l) {
	for (Pair x : l) {
		cout << x << endl;
	}
	cout << endl;
}

Pair srednee(TList l) {
	if (l.empty()) return Pair(0, 0);
	Pair s(0, 0);
	for (Pair x : l) {
		s = x + s;
	}
	int n = l.size();
	return s / n;
}

void zad3(TList& l, Pair sr, int n) {
	if (n < 0) n = 0;
	if (n >= l.size()) n = l.size() - 1;
	auto it = l.begin();
	advance(it, n);
	replace(it, next(it), *it, sr);
}

void zad4(TList& l, const Pair key, int b, int e) {
	if (b < 0) b = 0;
	if (e >= l.size()) e = l.size() - 1;
	if (b > e) return;

	auto first = l.begin();
	advance(first, b);

	auto last = l.begin();
	advance(last, e + 1);

	auto new_end = remove_if(first, last, [key](const Pair& p) {
		return p == key;
		});

	l.erase(new_end, last);
}

void zad5(TList& l, const Pair& sr) {
	for (auto& p : l) {
		p = p - sr;
	}
}

int main() {
	cout << "===Zadacha #1===" << endl;
	int n, p, b, e;
	cout << "N? "; cin >> n;
	TList l;
	l = make_list(n);
	print_list(l);

	cout << "\n===Zadanie 3===" << endl;
	Pair sr = srednee(l);
	cout << "Position? "; cin >> p;
	zad3(l, sr, p);
	print_list(l);

	cout << "\n===Zadanie 4===" << endl;
	Pair key;
	cout << "Enter the key: "; cin >> key;
	cout << "Enter the begining: "; cin >> b;
	cout << "\nEnter the ending: "; cin >> e;
	zad4(l, key, b, e);
	print_list(l);


	cout << "\n===Zadanie 5===" << endl;
	sr = srednee(l);
	zad5(l, sr);
	print_list(l);

	cout << "\n===Sorting...===" << endl;
	l.sort();
	print_list(l);
	l.reverse();
	print_list(l);
	return 0;
}
