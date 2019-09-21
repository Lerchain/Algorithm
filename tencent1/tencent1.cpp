#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	if (n <= 2)
	{
		cout << 0;
		return 0;
	}
	vector<int> v(n + 1);
	v[3] = 1;
	int cnt = 1;
	for (int i = 4; i <= n; i++)
	{
		v[i] = v[i - 1] + cnt;
		cnt++;
	}
	cout << v[n];
	return 0;
}

