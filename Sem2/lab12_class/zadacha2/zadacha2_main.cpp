#include <iostream>
#include <map>
#include "Pair.h"
using namespace std;

typedef map<int, Pair>TMap;
typedef TMap::iterator it;

TMap make_map(int n) {
	TMap m;
	Pair a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		m.insert(make_pair(i, a));
	}
	return m;
}

void print_map(TMap m) {
	for (int i = 0; i < m.size(); i++) {
		cout << i << " : " << m[i] << endl;
	}
}

Pair srednee(TMap m) {
	Pair s = m[0];
	for (int i = 1; i < m.size(); i++) {
		s = s + m[i];
	}
	int n = m.size();
	return s / n;
}

void  zad3(TMap& m, Pair s, int k){
	TMap temp;
	for (int i = 0; i < m.size(); i++) {
		if (i == k) temp.insert(make_pair(i, s));
		else temp.insert(make_pair(i, m[i]));
	}
	m.swap(temp);
}

void zad4(TMap& m, Pair key, int b, int e) {
	if (b < 0) b = 0;
	if (e > m.size()) e = m.size();
	if (e < b) return;
	for (int i = b; i <= e; i++) {
		if (m.find(i) != m.end() && m[i] == key) {
			m.erase(i);
		}
	}
}

void zad5(TMap& m, Pair sr) {
	TMap temp;
	for (int i = 0; i < m.size(); i++) {
		Pair t = m[i] - sr;
		temp.insert(make_pair(i, t));
	}
	m.swap(temp);
}


int main() {
	cout << "===Zadacha #2===" << endl;
	int n, p, b, e;
	cout <<"N? "; cin >> n;
	map<int, Pair> m = make_map(n);
	print_map(m);
	Pair sr = srednee(m);
	cout << "Srednee: " << sr << endl;

	cout << "===Zadanie 3===" << endl;
	cout << "Enter the position: "; cin >> p;
	zad3(m, sr, p);
	print_map(m);

	cout << "\n===Zadanie 4===" << endl;
	Pair key;
	cout << "Enter the key: "; cin >> key;
	cout << "\nEnter the begining: "; cin >> b;
	cout << "\nEnter the ending: "; cin >> e;
	zad4(m, key, b, e);
	print_map(m);

	cout << "\n===Zadanie 5===" << endl;
	sr = srednee(m);
	cout << "Srednee: " << sr << endl;
	zad5(m, sr);
	print_map(m);
	return 0;
}
