#pragma once
#include "Pair.h"
#include <iostream>
#include <fstream>
using namespace std;

int make_file(const char* f_name) {
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream) return -1;
	int n;
	Pair p;
	cout << "How many? "; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		stream << p << "\n";
	}
	stream.close();
	return n;
}

int print_file(const char* f_name) {
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p; int i = 0;
	while (stream >> p) {
		cout << p << "\n";
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, Pair n){
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	int i = 0; Pair p;
	while (stream >> p) {
		if (stream.eof()) break;
		i++;
		if (!(p>n)){
			temp << p << "\n";
		}
	}
	stream.close();
	temp.flush();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int add_file(const char* f_name, int k, Pair pp) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p; int i = 0, l = 0;
	while (stream >> p) {
		if (stream.eof()) break;
		i++;
		if (i == k) {
			temp << pp << "\n";
			l++;
		}
		temp << p << "\n";
	}
	stream.close();
	temp.flush();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}

int add_end(const char* f_name, Pair pp) {
	fstream stream(f_name, ios::out | ios::app);
	if (!stream) return -1;
	stream << pp << "\n";
	stream.close();
	return 1;
}

int change_file(const char* f_name, int k, Pair pp) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p; int i = 0, l = 0;
	char x;
	while (stream >> p) {
		if (stream.eof()) break;
		i++;
		if (i == k) {
			cout << p << " - is changing... Continue[y/n]?\n";
			cin >> x;
			if (x == 'n' || x == 'N') break;
			temp << pp << "\n";
			l++;
		}
		else temp << p << "\n";
	}
	stream.close();
	temp.flush();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}

int increase_by_value(const char* f_name, Pair searchValue, int L) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);

	if (!stream) return -1;

	Pair p;
	int changed = 0;

	while (stream >> p) {
		if (stream.eof()) break;
		if (p == searchValue) { 
			for (int i = 0; i < L; i++) {
				++p;
			}
			changed++;
		}
		temp << p << "\n";
	}
	stream.close();
	temp.flush();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return changed;
}

int add_after_n(const char* f_name, int N, int K) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p;
	int count = 0;
	int added = 0;
	while (stream >> p) {
		if (stream.eof()) break;
		count++;
		temp << p << "\n";
		if (count == N) {

			for (int i = 0; i < K; i++) {
				Pair newPair;
				cout << "New pair #" << (i + 1) << " (first second): ";
				cin >> newPair;
				temp << newPair << "\n";
				added++;
			}
		}
	}
	stream.close();
	temp.flush();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return added;
}

