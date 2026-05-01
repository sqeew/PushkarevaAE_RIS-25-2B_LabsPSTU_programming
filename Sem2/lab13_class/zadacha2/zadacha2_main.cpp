#include <iostream>
#include <queue>
#include <list>
#include <algorithm>
#include "Pair.h"
using namespace std;

typedef priority_queue<Pair> TQueue;

void print_queue(TQueue q) {
    list<Pair> temp;
    while (!q.empty()) {
        temp.push_back(q.top());
        q.pop();
    }
    for (const auto& x : temp) cout << x << " ";
    cout << endl;
}

list<Pair> q_to_list(TQueue q) {
    list<Pair> result;
    while (!q.empty()) {
        result.push_back(q.top());
        q.pop();
    }
    return result;
}

TQueue list_to_q(const list<Pair>& l) {
    TQueue result;
    for (const auto& x : l) result.push(x);
    return result;
}

Pair srednee(TQueue q) {
    list<Pair> temp = q_to_list(q);
    if (temp.empty()) return Pair(0, 0);
    Pair sum(0, 0);
    for_each(temp.begin(), temp.end(), [&sum](const Pair& p) {
        sum = sum + p;
        });
    return sum / temp.size();
}

void zad3(TQueue& q, const Pair& sr, int n) {
    list<Pair> temp = q_to_list(q);
    if (n < 0) n = 0;
    if (n >= temp.size()) n = temp.size() - 1;
    auto it = temp.begin();
    advance(it, n);
    *it = sr;
    q = list_to_q(temp);
}

void zad4(TQueue& q, const Pair& key, int b, int e) {
    list<Pair> temp = q_to_list(q);

    if (b < 0) b = 0;
    if (e >= temp.size()) e = temp.size() - 1;
    if (b > e) return;

    auto first = temp.begin();
    advance(first, b);
    auto last = temp.begin();
    advance(last, e + 1);

    auto new_end = remove_if(first, last, [key](const Pair& p) {
        return p == key;
        });

    temp.erase(new_end, last);
    q = list_to_q(temp);
}

void zad5(TQueue& q, const Pair& sr) {
    list<Pair> temp = q_to_list(q);

    for_each(temp.begin(), temp.end(), [sr](Pair& p) {
        p = p - sr;
        });

    q = list_to_q(temp);
}

int main() {
    cout << "===Zadacha #2===" << endl;
    int n, p, b, e;
    cout << "N? "; cin >> n;
    TQueue q;
    Pair par;
    for (int i = 0; i < n; i++) {
        cin >> par;
        q.push(par);
    }
    print_queue(q);

    cout << "\n===Zadanie 3===" << endl;
    Pair sr = srednee(q);
    cout << "Position? "; cin >> p;
    zad3(q, sr, p);
    print_queue(q);

    cout << "\n===Zadanie 4===" << endl;
    Pair key;
    cout << "Enter the key: "; cin >> key;
    cout << "Enter the begining: "; cin >> b;
    cout << "\nEnter the ending: "; cin >> e;
    zad4(q, key, b, e);
    print_queue(q);


    cout << "\n===Zadanie 5===" << endl;
    sr = srednee(q);
    zad5(q, sr);
    print_queue(q);
    
    cout << "===Sorting...===" << endl;
    list<Pair> temp = q_to_list(q);
    temp.sort();
    for (const auto& x : temp) cout << x << " ";
    cout << endl;
    return 0;
}