#include "pch.h"
#include <iostream>
#include <stack>
using namespace std;
template<typename T>
class Queue
{
	stack<T> a, b;
public:
	Queue(){}
	Queue(const Queue& x):a(x.a),b(x.b){}
	Queue& operator=(const Queue& x)
	{
		a = x.a;
		b = x.b;
	}
	void push(T x)
	{
		a.push(x);
	}
	void pop()
	{
		if (b.empty())
		{
			while (!a.empty())
			{
				T temp = a.top();
				a.pop();
				b.push(temp);
			}
		}
		b.pop();
	}
	T top()
	{
		if (b.empty())
		{
			while (!a.empty())
			{
				T temp = a.top();
				a.pop();
				b.push(temp);
			}
		}
		return b.top();
	}
};
int main()
{
	Queue<int> t;
	for (int i = 0; i < 10; i++)
	{
		t.push(i * 2);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << t.top()<<endl;
		t.pop();
	}
}

