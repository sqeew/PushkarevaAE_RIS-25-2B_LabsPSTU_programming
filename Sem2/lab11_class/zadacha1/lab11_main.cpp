#include <iostream>
#include <list>
#include <cstdlib>
using namespace std;

typedef list<int> lis;

lis make_list(int n) {
	lis l;
	for (int i = 0; i < n; i++) {
		int a = rand() % 100 - 50;
		l.push_back(a);
	}
	return l;
}

void print_list(lis l) {
	for (int x : l) {
		cout << x << " ";
	}
	cout << endl;
}

int srednee(lis l) {
	int s = 0;
	for (int x : l) {
		s += x;
	}
	int n = l.size();
	return s / n;
}

void zad3(lis& l, int sr, int n) {
	if (n < 0) n = 0;
	if (n >= l.size()) n = l.size() - 1;
	list<int>::iterator it = l.begin();
	for (int i = 0; i < n; i++) {
		++it;
	}
	*it = sr;
}

void zad4(lis& l, int key, int b, int e) {
	if (b < 0) b = 0;
	if (e >= l.size()) e = l.size() - 1;
	if (b > e) return;
	auto it = l.begin();
	for (int i = 0; i < b; i++) ++it;
	for (int i = b; i <= e; i++) {
		list<int>::iterator current = it;
		++it;
		if (*current == key) {
			l.erase(current);
		}
	}
}

void zad5(lis& l, int sr) {
	for (int& x : l) {
		x -= sr;
	}
}

int main() {
	try {
		list<int> l;
		cout << "===Zadacha #1===" << endl;
		int n,k, key, b, e;
		cout << "N? "; cin >> n;
		l = make_list(n);
		print_list(l);
		int sr = srednee(l);
		cout << "===Zadanie #3===" << endl;
		cout << "Enter the position: "; cin >> k;
		zad3(l, sr, k-1);
		print_list(l);
		cout << "===Zadanie #4===" << endl;
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
		cout << "Error!" << endl;
	}
	return 0;
}
