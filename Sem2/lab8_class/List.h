#pragma once
#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include <iostream>


struct Node {
	Object* data;
	Node* next;
};

class List{
public:
	List(int);
public:
	List();
	~List();
	List(const List& a);
	void add();
	void add(Object* p);
	void del();
	void show();
	void ShowName(int k);
	int operator()();
protected:
	Node* head;
	int cur;
	int size;
};

