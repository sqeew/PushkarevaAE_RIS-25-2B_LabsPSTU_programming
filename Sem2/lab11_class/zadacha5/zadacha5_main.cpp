#include "Pair.h"
#include <iostream>
#include <queue>
#include <list>
#include "List.h"

using namespace std;

int main() {
    cout << "===Zadacha #5===" << endl;
    int n;
    cout << "N? "; cin >> n;
	List<Pair>q(n);
	q.print();
    Pair sr = q.srednee();

    cout << "=== Zadanie #3 ===" << endl;
    int pos;
    cout << "Enter position to replace: "; cin >> pos;
    q.zad3(sr, pos);
    cout << "After replacement:" << endl;
    q.print();

    cout << "\n=== Zadanie #4 ===" << endl;
    Pair key;
    int b, e;
    cout << "Enter key (first second): "; cin >> key;
    cout << "Enter start index (b): "; cin >> b;
    cout << "Enter end index (e): "; cin >> e;
    q.zad4(key, b, e);
    cout << "After deletion:" << endl;
    q.print();

    sr = q.srednee();
    cout << "\n=== Zadanie #5 ===" << endl;
    cout << "Srednee for subtraction: " << sr << endl;
    q.zad5(sr);
    cout << "After subtraction:" << endl;
    q.print();

	return 0;
}
