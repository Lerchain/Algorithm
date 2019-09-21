#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, s;
	cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int sum = 0;
	int res = -1;
	int cnt = 0;
	for (int i = 0, l = 0; i < n; i++)
	{
		sum += v[i];
		cnt++;
		while (sum > s)
		{
			sum -= v[l];
			cnt--;
		}
		res = max(res, cnt);
	}
	cout << res;
}

