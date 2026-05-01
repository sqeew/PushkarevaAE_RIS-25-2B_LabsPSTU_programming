#pragma once
#include <iostream>
#include <list>

using namespace std;

template <class T>
class List {
public:
	List(int n);
	List(int s, T k);
	List(const List<T>& a);
	~List();
	void print();
	T srednee();
	void zad3(const T& sr, int n);
	void zad4(const T& key, int b, int e);
	void zad5(const T& sr);
	friend ostream& operator<<(ostream& out, const List<T>& a) {
		for (int i = 0; i < a.size; ++i) {
			out << a.data[i] << " ";
		}
		return out;
	}

	friend istream& operator>>(istream& in, List<T>& a) {
		for (int i = 0; i < a.size; ++i) {
			in >> a.data[i];
		}
		return in;
	}
private:
	int size;
	T* data;
};

template <class T>
List<T>::List(int n) {
	size = n;
	data = new T[size];
	for (int i = 0; i < size; i++) {
		cout << i << ": ";
		cin >> data[i];
		cout << endl;
	}
}

template <class T>
List<T>::List(int s, T k) {
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++) {
		data[i] = k;
	}
}

template <class T>
List<T>::List(const List& a) {
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++) {
		data[i] = a.data[i];
	}
}

template <class T>
List<T>::~List() {
	delete[] data;
	data = 0;
}

template <class T>
void List<T>::print() {
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

template <class T>
T List<T>::srednee() {
	if (size == 0) return T(0, 0);
	T s = T(0, 0);
	for (int i = 0; i < size; i++) {
		s = s + data[i];
	}
	return s / size;
}

template <class T>
void List<T>::zad3(const T& sr, int n) {
	if (n < 0) n = 0;
	if (n >= size) n = size - 1;
	data[n] = sr;
}

template <class T>
void List<T>::zad4(const T& key, int b, int e) {
	if (b < 0) b = 0;
	if (e >= size) e = size - 1;
	if (b > e) return;

	int newSize = 0;
	T* newData = new T[size];

	for (int i = 0; i < size; i++) {
		if (i < b || i > e || !(data[i] == key)) {
			newData[newSize++] = data[i];
		}
	}

	delete[] data;
	data = newData;
	size = newSize;
}

template <class T>
void List<T>::zad5(const T& sr) {
	for (int i = 0; i < size; i++) {
		data[i] = data[i] - sr;
	}
}
