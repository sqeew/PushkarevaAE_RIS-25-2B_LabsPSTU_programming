#pragma once
#include "Person.h"
class Student :
    public Person
{
public:
    Student(void);
public:
    ~Student(void);
    Student(string, int, int);
    Student(const Student&);
    int get_year() { return year; }
    void set_year(int);
    void reset_year(int);
    Student& operator=(const Student&);
    friend istream& operator>>(istream& in, Student& s);
    friend ostream& operator<<(ostream& out, const Student& s);
protected:
    int year;
};

