#pragma once
#include <iostream>
#include "Person.h"
using namespace  std;
class Employee :
    public Person
{
public:
    Employee(void);
public:
    ~Employee(void);
    void show();
    void input();
    Employee(string, int, float, string);
    Employee(const Employee&);
    float Get_salary() { return salary; }
    string Get_post() { return post; }
    void Set_salary(float);
    void Set_post(string);
    Employee& operator=(const Employee&);
protected:
    float salary;
    string post;
};

