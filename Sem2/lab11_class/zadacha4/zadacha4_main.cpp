#include "Pair.h"
#include <iostream>
#include <queue>
#include <list>

using namespace std;

typedef priority_queue<Pair> q;
typedef list<Pair> l;

q make_pqueue(int n) {
	q s;
	Pair p;
	for (int i = 0; i < n; i++) {
		cin >> p;
		s.push(p);
	}
	return s;
}

void print_pqueue(q s) {
	q temp = s;
	while (!temp.empty()) {
		cout << temp.top() << ' ';
		temp.pop();
	}
	cout << endl;
}

Pair srednee(q s) {
	if (s.empty()) return Pair(0, 0);
	Pair sum(0, 0);
	int count = 0;
	while (!s.empty()) {
		sum = sum + s.top();
		s.pop();
		count++;
	}
	return sum / count;
}

q list_to_pqueue(const l& lst) {
    q result;
    for (const Pair& p : lst) {
        result.push(p);
    }
    return result;
}


void zad3(q& s, const Pair& sr, int n) {
    if (n < 0) return;
    l temp_list;
    q temp_queue = s;
    while (!temp_queue.empty()) {
        temp_list.push_back(temp_queue.top());
        temp_queue.pop();
    }
    if (n < temp_list.size()) {
        auto it = temp_list.begin();
        for (int i = 0; i < n; i++) ++it;
        *it = sr;
    }
    s = list_to_pqueue(temp_list);
}

void zad4(q& s, const Pair& key, int b, int e) {
    if (b < 0) b = 0;
    l temp_list;
    q temp_queue = s;
    while (!temp_queue.empty()) {
        temp_list.push_back(temp_queue.top());
        temp_queue.pop();
    }
    if (e >= temp_list.size()) e = temp_list.size() - 1;
    if (b > e) return;
    auto it = temp_list.begin();
    for (int i = 0; i < b; i++) ++it;
    for (int i = b; i <= e; i++) {
        auto current = it;
        ++it;
        if (*current == key) {
            temp_list.erase(current);
            e--;
        }
        if (it == temp_list.end()) break;
    }
    s = list_to_pqueue(temp_list);
}

void zad5(q& s, const Pair& sr) {
    l temp_list;
    q temp_queue = s;
    while (!temp_queue.empty()) {
        temp_list.push_back(temp_queue.top() - sr);
        temp_queue.pop();
    }
    s = list_to_pqueue(temp_list);
}

int main() {
	Pair p;
	q s;
	int n;
    cout << "===Zadacha #4===" << endl;
	cout << "N? "; cin >> n;
	s = make_pqueue(n);
	print_pqueue(s);
    cout << "===Zadanie 3===" << endl;
    int pos;
    cout << "Position to replace: "; cin >> pos;
    Pair newValue;
    cout << "Enter new value (first second): "; cin >> newValue;
    zad3(s, newValue, pos);
    print_pqueue(s);
    cout << "===Zadanie 4===" << endl;
    Pair key;
    int b, e;
    cout << "Enter key to delete (first second): "; cin >> key;
    cout << "Start index (b): "; cin >> b;
    cout << "End index (e): "; cin >> e;
    zad4(s, key, b, e);
    print_pqueue(s);
    cout << "===Zadanie 5===" << endl;
    Pair sr;
    cout << "Enter value to subtract (first second): "; cin >> sr;
    zad5(s, sr);
    print_pqueue(s);

	return 0;
}
