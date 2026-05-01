#include "Pair.h"
#include <iostream>

using namespace std;
//ïðèñâàèâàíèå
Pair& Pair :: operator=(const Pair& p) {
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
	return *this;
}

//ñëîæåíèå
Pair Pair::operator+(const Pair& p) {
	return Pair(first + p.first, second + p.second);
}

//âû÷èòàíèå
Pair Pair:: operator-(const Pair& p) {
	return Pair(first - p.first, second - p.second);
}

//äåëåíèå íà  int
Pair Pair::operator/(const int& x) {
	if (x == 0) return Pair(0, 0);
	return Pair(first / x, second / x);
}

//ïðåôèêñíûé èíêðåìåíò
Pair& Pair::operator++() {
	++first;
	return *this;
}

//ïîñòôèêñíûé èíêðåìåíò
Pair Pair::operator++(int) {
	Pair temp = *this;
	second++;
	return temp;
}

//ñðàâíåíèå (áîëüøå)
bool Pair::operator>(const Pair& other) {
	if (first != other.first)
		return first > other.first;
	return second > other.second;
}

//ñðàâíåíèå (ìåíüøå)
bool Pair::operator<(const Pair& other) const {
	if (first != other.first)
		return first < other.first;
	return second < other.second;
}

//ñðàâíåíèå íà ðàâåíñòâî
bool Pair::operator==(const Pair& other) const {
	return first == other.first && second == other.second;
}

//ââîä
istream& operator>>(istream& in, Pair& p) {
	cout << "first? "; in >> p.first;
	cout << "second? "; in >> p.second;
	return in;
}

//âûâîä
ostream& operator<<(ostream& out, const Pair& p) {
	return (out << "(" << p.first << " : " << p.second << ")");
}
