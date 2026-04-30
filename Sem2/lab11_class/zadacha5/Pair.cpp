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

//сложение
Pair Pair::operator+(const Pair& p) {
	return Pair(first + p.first, second + p.second);
}

//вычитание
Pair Pair:: operator-(const Pair& p) const {
	return Pair(first - p.first, second - p.second);
}

//деление на  int
Pair Pair::operator/(const int& x) {
	if (x == 0) return Pair(0, 0);
	return Pair(first / x, second / x);
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
bool Pair::operator>(const Pair& other) const {
	if (first != other.first)
		return first > other.first;
	return second > other.second;
}

//сравнение (меньше)
bool Pair::operator<(const Pair& other) const {
	if (first != other.first) return first < other.first;
	return second < other.second;
}

//сравнение на равенство
bool Pair::operator==(const Pair& other) const {
	return first == other.first && second == other.second;
}

//ввод
istream& operator>>(istream& in, Pair& p) {
	cout << "first? "; in >> p.first;
	cout << "second? "; in >> p.second;
	return in;
}

//вывод
ostream& operator<<(ostream& out, const Pair& p) {
	return (out << "(" << p.first << " : " << p.second << ")");
}