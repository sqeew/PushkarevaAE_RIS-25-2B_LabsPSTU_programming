#include "Pair.h"
#include <iostream>

using namespace std;
//присваивание
Pair& Pair :: operator=(const Pair& p) {
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
	return *this;
}
//префиксный инкремент
Pair& Pair::operator++() {
	++first;
	return *this;
}

//постфиксный инкремент
Pair Pair::operator++(int) {
	Pair temp = *this;
	second++;
	return temp;
}

//сравнение (больше)
bool Pair::operator>(const Pair&) {
	return first > second;
}

//сравнение (меньше)
bool Pair::operator<(const Pair&) {
	return first < second;
}

//ввод
istream& operator>>(istream& in, Pair& p) {
	cout << "first? "; in >> p.first;
	cout << "second? "; in >> p.second;
	return in;
}

//вывод
ostream& operator<<(ostream& out,const Pair& p) {
	return (out << p.first << " : " << p.second);
}

