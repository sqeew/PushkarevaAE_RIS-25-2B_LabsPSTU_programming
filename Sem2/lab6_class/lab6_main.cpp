#include "List.h"
#include <iostream>
using namespace std;

int main(){
	List a(5);
	cout << a << "\n";
	cin >> a;
	cout << a << "\n";
	a[2] = 100;
	cout << a << "\n";
	List b(10);
	cout << b << "\n";
	b = a;
	cout << b << "\n";
	List c(10);
	c = b + 100;
	cout << c << "\n";
	cout << "\nthe length of a = " << a() << endl;

	cout << *(a.first()) << endl;
	Iterator i = a.first();
	i++;
	cout << *i << endl;
	for (i = a.first(); i != a.last(); i++) cout << *i << "  ";

	return 0;
}
