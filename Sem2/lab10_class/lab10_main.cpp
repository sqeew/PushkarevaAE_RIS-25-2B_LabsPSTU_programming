#include "Pair.h"
#include <iostream>
#include <fstream>
#include "file_work.h"
using namespace std;

int main() {
	Pair p, p1, p2, n, searchVal;
	int m, c;
	char file_name[30];
	do {
		cout << "\n1. Make file";
		cout << "\n2. Print file";
		cout << "\n3. Delete elements bigger than N";
		cout << "\n4. Add recird to file";
		cout << "\n5. Change record in file";
		cout << "\n6. Add const to Pair";
		cout << "\n7. Add K records after N";
		cout << "\n0. Exit\n";
		cin >> c;
		switch (c) {
		case 1:
			cout << "file name?"; cin >> file_name;
			m = make_file(file_name);
			if (m < 0) cout << "Cant't make file";
			break;
		case 2:
			cout << "file name?"; cin >> file_name;
			m = print_file(file_name);
			if (m == 0) cout << "Empty file\n";
			if (m < 0) cout << "Can't read the file\n";
			break;
		case 3:
			cout << "file name?"; cin >> file_name;
			cout << "\nN? ";cin >> n;
			m = del_file(file_name, n);
			if (m < 0) cout << "Can't read the file";
			break;
		case 4:
			int num;
			cout << "file name?"; cin >> file_name;
			cout << "\nN? "; cin >> num;
			cout << "New pair: ";
			cin >> p1;
			m = add_file(file_name, num, p1);
			if (m < 0) cout << "Can't read the file";
			if (m == 0) m = add_end(file_name, p1);
			break;
		case 5:
			cout << "file name?"; cin >> file_name;
			cout << "\nN? "; cin >> num;
			cout << "New pair: ";
			cin >> p2;
			m = change_file(file_name, num, p2);
			if (m < 0) cout << "\nCan't read the file";
			if (m == 0) cout << "\nNot such record";
			break;
		case 6:
			int L;
			cout << "file name? "; cin >> file_name;
			cout << "Search value: "; cin >> searchVal;
			cout << "Increase by L (count): "; cin >> L;
			m = increase_by_value(file_name, searchVal, L);
			if (m < 0) cout << "Can't read file\n";
			break;
		case 7:
			int N, K;
			cout << "file name? "; cin >> file_name;
			cout << "After record number N: "; cin >> N;
			cout << "How many records to add (K): "; cin >> K;
			m = add_after_n(file_name, N, K);
			if (m < 0) cout << "Can't read file\n";
			break;
		}
	} while (c != 0);
	return 0;
}
