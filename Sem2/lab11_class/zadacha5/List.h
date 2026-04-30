#pragma once
#include <iostream>
#include <queue>
#include <list>

using namespace std;

template <class T>
class List {
public:
	List(int n);
	List(const List<T>& a);
	~List();
	List& operator=(const List<T>& a);
	void print();
	T srednee();
	void zad3(const T& sr, int n);
	void zad4(const T& key, int b, int e);
	void zad5(const T& sr);
	int size() const { return len; }
	bool empty() const { return pq.empty(); }
private:
	int len;
	priority_queue<T> pq;
};

template <class T>
List<T>::List(int n) {
	len = n;
	T temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		pq.push(temp);
	}
}

template <class T>
List<T>::List(const List<T>& a) {
	len = a.len;
	// копируем через list
	list<T> temp_list;
	priority_queue<T> temp_queue = a.pq;
	while (!temp_queue.empty()) {
		temp_list.push_back(temp_queue.top());
		temp_queue.pop();
	}
	for (const T& val : temp_list) {
		pq.push(val);
	}
}


template <class T>
List<T>::~List() {}

template <class T>
List<T>& List<T>::operator=(const List<T>& a) {
	if (this == &a) return *this;
	len = a.len;
	while (!pq.empty()) pq.pop();
	list<T> temp_list;
	priority_queue<T> temp_queue = a.pq;
	while (!temp_queue.empty()) {
		temp_list.push_back(temp_queue.top());
		temp_queue.pop();
	}
	for (const T& val : temp_list) {
		pq.push(val);
	}
	return *this;
}

template <class T>
void List<T>::print() {
	priority_queue<T> temp = pq;
	while (!temp.empty()) {
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << endl;
}

template <class T>
T List<T>::srednee() {
	if (pq.empty()) return T(0, 0);

	priority_queue<T> temp = pq;
	T sum = T(0, 0);
	int count = 0;

	while (!temp.empty()) {
		sum = sum + temp.top();
		temp.pop();
		count++;
	}

	return sum / count;
}

template <class T>
void List<T>::zad3(const T& sr, int n) {
	if (n < 0) return;
	if (n >= len) return;
	list<T> temp_list;
	priority_queue<T> temp_queue = pq;

	while (!temp_queue.empty()) {
		temp_list.push_back(temp_queue.top());
		temp_queue.pop();
	}
	auto it = temp_list.begin();
	for (int i = 0; i < n; i++) ++it;
	*it = sr;
	while (!pq.empty()) pq.pop();
	for (const T& val : temp_list) {
		pq.push(val);
	}
}

template <class T>
void List<T>::zad4(const T& key, int b, int e) {
	if (b < 0) b = 0;
	if (e >= len) e = len - 1;
	if (b > e) return;
	list<T> temp_list;
	priority_queue<T> temp_queue = pq;
	while (!temp_queue.empty()) {
		temp_list.push_back(temp_queue.top());
		temp_queue.pop();
	}
	auto it = temp_list.begin();
	for (int i = 0; i < b; i++) ++it;
	for (int i = b; i <= e; i++) {
		auto current = it;
		++it;
		if (*current == key) {
			temp_list.erase(current);
			e--;
			len--;
		}
		if (it == temp_list.end()) break;
	}
	while (!pq.empty()) pq.pop();
	for (const T& val : temp_list) {
		pq.push(val);
	}
}

template <class T>
void List<T>::zad5(const T& sr) {
	list<T> temp_list;
	priority_queue<T> temp_queue = pq;
	while (!temp_queue.empty()) {
		temp_list.push_back(temp_queue.top() - sr);
		temp_queue.pop();
	}
	while (!pq.empty()) pq.pop();
	for (const T& val : temp_list) {
		pq.push(val);
	}
}

template <class T>
list<T> copy_queue_to_list(priority_queue<T> q) {
	list<T> result;
	while (!q.empty()) {
		result.push_back(q.top());
		q.pop();
	}
	return result;
}

template <class T>
priority_queue<T> copy_list_to_queue(const list<T>& lst) {
	priority_queue<T> result;
	for (const T& val : lst) {
		result.push(val);
	}
	return result;
}