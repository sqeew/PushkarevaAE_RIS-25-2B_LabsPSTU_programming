#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include "Dialog.h"
#include "List.h"
#include <string>
using namespace std;

int main() {
	cout << "===Person===" << endl;
	Person* a = new Person;
	a->input();

	cout << "===Employee===" << endl;
	Employee* b = new Employee;
	b->input();

	List l(10);
	Object* p = a;
	l.add(p);
	p = b;
	l.add(p);
	l.show();
	l.del();
	cout << "\nList  size = " << l();
	
	cout << "===Event===" << endl;
	Dialog d;
	d.Excecute();
	
	return 0;
}
