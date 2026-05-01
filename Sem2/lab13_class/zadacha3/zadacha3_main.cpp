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
	if (n < 0) n = 0;
	if (n >= m.size()) n = m.size() - 1;
	auto it = m.begin();
	for (int i = 0; i < n; i++) ++it;
	int old_key = it->first;
	m.erase(it);
	m.insert(make_pair(old_key, sr));
}

void zad4(TMap& m, const Pair& key, int b, int e) {
	list<pair<int, Pair>> temp;
	for (const auto& item : m) {
		temp.push_back(item);
	}
	if (b < 0) b = 0;
	if (e >= temp.size()) e = temp.size() - 1;
	if (b > e) return;
	auto first = temp.begin();
	advance(first, b);
	auto last = temp.begin();
	advance(last, e + 1);
	auto new_end = remove_if(first, last, [key](const pair<int, Pair>& item) {
		return item.second == key;
		});
	temp.erase(new_end, last);
	m.clear();
	for (const auto& item : temp) {
		m.insert(item);
	}
}

void zad5(TMap& m, Pair sr) {
	for (auto& x : m) {
		x.second = x.second - sr;
	}
}

int main() {
	cout << "===Zadacha #3===" << endl;
	int n, p, b, e;
	cout << "N? "; cin >> n;
	TMap m;
	Pair par;
	for (int i = 0; i < n; i++) {
		int keyval;
		Pair pi;
		cout << "Enter the key and the value: ";
		cin >> keyval >> pi;
		m.insert(make_pair(keyval, pi));
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

	cout << "===Sorting...===" << endl;
	list<Pair> temp_list = map_to_list(m);
	temp_list.sort();
	for (const auto& x : temp_list) cout << x << " ";
	cout << endl;
	temp_list.reverse();
	for (const auto& x : temp_list) cout << x << " ";
	cout << endl;
	return 0;
}