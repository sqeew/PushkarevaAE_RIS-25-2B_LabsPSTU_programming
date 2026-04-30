#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person
{
public:
	Person(void);
public:
	virtual ~Person(void); //деструктор
	Person(string, int); //конструктор с параметрами
	Person(const Person&); //конструктор копирования
	string get_name() { return name; } //селекторы
	int get_age() { return age; }
	void set_name(string); //модификаторы
	void set_age(int);
	Person& operator=(const Person&); //перегрузка оператора присваинвания?
	friend istream& operator>>(istream& in, Person& p);
	friend ostream& operator<<(ostream& out, const Person& p);
protected:
	string name;
	int age;
};

