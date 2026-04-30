#pragma once
#include "Object.h"
#include <string>
using namespace std;
class Person :
    public Object
{
public:
    Person(void);
public:
    virtual ~Person(void);
    void show();
    void input();
    Person(string, int);
    Person(const Person&);
    virtual string Get_name() const override;
    int Get_age() { return age; }
    void Set_name(string);
    void Set_age(int);
    Person& operator=(const Person&);
protected:
    string name;
    int age;
};

