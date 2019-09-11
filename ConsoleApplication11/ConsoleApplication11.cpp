#include "pch.h"
#include <stdio.h> 
#include"pch.h"
#include <iostream>
using namespace std;

void Swap(int* a, int* b)
{
	int *p = a;
	a = b;
	b = p;
}

class re
{
	int& a;//这也只是因为类未被创建。
};

class em
{

};
int main()
{
	int a = 5;
	int b = 6;
	Swap(&a, &b);//a,b不会变显而易见。
	cout << a << b<<endl;
	const char* p = "abc";
	cout<<sizeof(re)<<" "<<sizeof(em)<<endl;
	int &&i = 1;
	cout << i << endl;
	int j = i;
	i = j;
	cout << j <<endl;

	int* n = new int[10000];
	delete[] n;

}