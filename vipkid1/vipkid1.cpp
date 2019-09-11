#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	int t;
	while (cin >> t)
	{
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	int res = 0;
	for (int l = 0, r = v.size() - 1; l < r;)
	{
		if (v[l] + v[r] == 0)
		{
			res++;
			l++;
		
		}
		else if (v[l] + v[r] < 0)
		{
			l++;
		}
		else
		{
			r--;
		}
	}
	cout << res;
}

