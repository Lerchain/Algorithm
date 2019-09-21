#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int MI = 2147483647;
	for (int i = 0; i < n; i++)
	{
		if (i > MI)
			continue;
		for (int j = 0; j < m; j++)
		{
			if (i + j > MI)
				break;
			if ((n - i)*(m - j) <= k)
			{
				MI = min(MI, i + j);
				break;
			}
		}
	}
	cout << MI;
}
