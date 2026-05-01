#include <iostream>
#include <map>
using namespace std;

typedef map<int, int> TMap;
typedef TMap::iterator it;

TMap make_map(int n) {
	TMap m;
	int a;
	for (int i = 0; i < n; i++) {
		cout << "?"; cin >> a;
		m.insert(make_pair(i, a));
	}
	return m;
}

int srednee(TMap v) {
	int s = 0;
	for (int i = 0; i < v.size(); i++) {
		s += v[i];
	}
	int n = v.size();
	return s / n;
}

void print_map(TMap m) {
	for (int i = 0; i < m.size(); i++) {
		cout << i << " : " << m[i] << endl;
	}
}

void  zad3(TMap& m,int s, int k) {
	TMap temp;
	for (int i = 0; i < m.size(); i++) {
		if (i == k) temp.insert(make_pair(i, s));
		else temp.insert(make_pair(i, m[i]));
	}
	m.swap(temp);
}

void zad4(TMap& m, int key, int b, int e) {
	if (b < 0) b = 0;
	if (e > m.size()) e = m.size();
	if (e < b) return;
	for (int i = b; i <= e; i++) {
		if (m.find(i) != m.end() && m[i] == key) {
			m.erase(i);
		}
	}
}

void zad5(TMap& m, int sr) {
	TMap temp;
	for (int i = 0; i < m.size(); i++) {
		int t = m[i] - sr;
		temp.insert(make_pair(i, t));
	}
	m.swap(temp);
}

int main() {
	int n, key, b, e;
	cout << "===Zadacha #1===" << endl;
	cout << "N? "; cin >> n;
	TMap m = make_map(n);
	print_map(m);
	int sr = srednee(m);
	cout << "-Srednee znach: " << sr << endl;
	cout << "===Zadanie 3===" << endl;
	cout << "Enter the position: "; cin >> key;
	zad3(m, sr, key);
	print_map(m);

	cout << "===Zadanie 4===" << endl;
	cout << "Enter the key:"; cin >> key;
	cout << "\nEnter the begining: "; cin >> b;
	cout << "\nEnter the ending: "; cin >> e;
	zad4(m, key, b, e);
	print_map(m);

	cout << "===Zadanie 5===" << endl;
	sr = srednee(m);
	zad5(m, sr);
	print_map(m);
}
