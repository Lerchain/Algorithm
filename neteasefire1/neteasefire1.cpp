#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), [](pair<int,int> x, pair<int,int> y) {
		int xw = x.first, xh = x.second;
		int yw = y.first, yh = y.second;
		if (xw*xh > yw*yh)
			return false;
		if (xw*xh < yw*yh)
			return true;
		float mx = min((float)xw / xh, (float)xh / xw);
		float my = min((float)yw / yh, (float)yh / yw);
		if (mx > my)
			return false;
		if (mx < my)
			return true;
		return xw < yw;
	});
	for (auto x : v)
	{
		cout << x.first << " " << x.second << " ";
	}
}

