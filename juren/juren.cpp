#include "pch.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
#define PI 3.1415926;
int main()
{
	float b = sqrt(2) / 2;
	float a = asinf(b)*180/PI;
	cout << a << endl;
	int i = 1;
	i = i++;
	cout << i;
}

