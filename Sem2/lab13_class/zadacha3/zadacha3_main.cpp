#include <iostream>
#include "Pair.h"
#include <map>
#include <list>
#include <algorithm>
using namespace std;

typedef multimap<int, Pair> TMap;
typedef TMap::iterator it;

void print_map(TMap m) {
	for (const auto& item : m) {
		cout << item.first << " -> " << item.second << endl;
	}
}

list <Pair> map_to_list(TMap& m) {
	list <Pair> result;
	for (it i = m.begin(); i != m.end(); ++i) {
		result.push_back(i->second);
	}
	return result;
}

TMap list_to_map(const list<Pair>& l) {
	TMap result;
	int key = 0;
	for (const auto& p : l) {
		result.insert(make_pair(key++, p));
	}
	return result;
}

Pair srednee(TMap& m) {
	list<Pair> values = map_to_list(m);
	Pair sum(0, 0);
	for_each(values.begin(), values.end(), [&sum](const Pair& p) {
		sum = sum + p;
		});
	return sum / values.size();
}

void zad3(TMap& m, Pair sr, int n) {
	list<Pair> temp = map_to_list(m);
	if (n < 0) n = 0;
	if (n > temp.size()) n = temp.size();
	auto pos = temp.begin();
	for (int i = 0; i < n; i++) {
		++pos;
	}
	temp.insert(pos, sr);
	m = list_to_map(temp);
}

void zad4(TMap& m, Pair key, int b, int e) {
	for (auto i = m.begin(); i != m.end();) {
		if (i->first >= b && i->first <= e) {
			i = m.erase(i);
		}
		else {
			++i;
		}
	}
}

void zad5(TMap& m, Pair sr) {
	for (auto& x : m) {
		x.second = x.second - sr;
	}
}

int main() {
	cout << "===Zadacha #2===" << endl;
	int n, p, b, e;
	cout << "N? "; cin >> n;
	TMap m;
	Pair par;
	for (int i = 0; i < n; i++) {
		int keyval;
		Pair p;
		cin >> keyval >> p;
		m.insert(make_pair(keyval, p));
	}
	print_map(m);

	cout << "\n===Zadanie 3===" << endl;
	Pair sr = srednee(m);
	cout << "Position? "; cin >> p;
	zad3(m, sr, p);
	print_map(m);

	cout << "\n===Zadanie 4===" << endl;
	Pair key;
	cout << "Enter the key: "; cin >> key;
	cout << "Enter the begining: "; cin >> b;
	cout << "\nEnter the ending: "; cin >> e;
	zad4(m, key, b, e);
	print_map(m);


	cout << "\n===Zadanie 5===" << endl;
	sr = srednee(m);
	zad5(m, sr);
	print_map(m);
	return 0;
}
