#include "pch.h"
#include <iostream>
#include <string>
#include "源.cpp"
#define pii pair<int,int>

using namespace std;

class A
{
	static const int a = 1;
	static const string b;
};

const int add(int i)
{
	return i + 1;
}
const string A::b = "1";

using pif = pair<int,float>;
int main()
{
	int *a = new int[10];
	free(a);
	int *b = (int*)malloc(sizeof(int));
	delete b;
    int c = 1;
	const int d = c;
	int e = 5, f = 6;
	const int sb = e * f;
	cout << sb;
	cout << lala<<endl;
	cout << add(2);
}
