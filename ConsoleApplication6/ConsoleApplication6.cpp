
#include "pch.h"
#include "const.h"
#include <iostream>

using namespace std;
class Base
{
private:

public:
	Base(){}
	virtual void test()
	{
		cout << "Base";
	}
};

class Derived:public Base
{
public:
	Derived(){}
	virtual void test() override
	{
		cout << "Derived";
	}
};
int main()
{
	Base *b;
	b = new Derived;
	cout<<typeid(b).name();
	cout << typeid(*b).name();
	cout << endl;
	cout << a;
}

