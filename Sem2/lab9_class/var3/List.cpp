#include "List.h"
#include "error.h"

List::List(int s) {
	size = s;
	if (size > MAX_SIZE) throw MaxSizeError();
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = 0;
	}
}

List::List(int s, int* d) {
	size = s;
	if (size > MAX_SIZE) throw MaxSizeError();
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = d[i];
	}
}

List::List(const List& l) {
	size = l.size;
	if (size > MAX_SIZE) throw MaxSizeError();
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = l.data[i];
	}
}

List::~List() {
	delete[] data;
}

const List& List::operator=(const List& l) {
	if (this != &l) {
		delete[] data;
		size = l.size;
		if (size > MAX_SIZE) throw MaxSizeError();
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = l.data[i];
		}
	}
	return *this;
}

ostream& operator<<(ostream& out, const List& l) {
	if (l.size == 0) out << "Empty!\n";
	else {
		for (int i = 0; i < l.size; i++) {
			out << l.data[i] << " ";
		}
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, List& l) {
	for (int i = 0; i < l.size; i++) {
		cout << ">";
		in >> l.data[i];
	}
	return in;
}

int& List :: operator[](int i) {
	if (i < 0) throw IndexError1();
	if (i >= size) throw IndexError2();
	return data[i];
}

int List::operator()() const {
	return size;
}

List& List::operator++() {
	if (size >= MAX_SIZE) throw MaxSizeError();
	int newValue;
	cout << "Enter value to add to the end: ";
	cin >> newValue;
	int* newData = new int[size + 1];
	for (int i = 0; i < size; i++) {
		newData[i] = data[i];
	}
	newData[size] = newValue;
	delete[]data;
	data = newData;
	size++;
	return *this;
}

List List::operator+(int num) const {
	List result(size);
	for (int i = 0; i < size; i++) {
		result.data[i] = data[i] + num;
	}
	return result;
}