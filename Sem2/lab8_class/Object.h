#pragma once
#include <string>
using namespace std;
class Object{
public:
	Object(void);
	virtual void show() = 0;
	virtual void input() = 0;
	virtual string Get_name() const = 0;
	virtual ~Object(void);
};

