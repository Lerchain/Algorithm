#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool judge(int x, int y)
{
	vector<int> v;
	for (int i = 2; i <= y; i++)
	{
		if (y%i == 0)
			v.push_back(i);
	}
	for (auto i : v)
		if (x%i == 0)
			return false;
	return true;
}
float F(int n)
{
	int cnt = 0;
	for (int i = 1; i < n; i++)
	{
		if (judge(n, i))
			cnt++;
	}
	if (!cnt)
		return 10000;
	return (float)cnt / n;
}
int main()
{
	int N;
	cin >> N;
	float res = 10000;
	for (int i = 1; i <= N; i++)
	{
		res = min(res, F(i));
	}
	if (res == 10000)
		cout << (float)N;
	else
		cout<< res;
}

