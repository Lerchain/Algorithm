#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int M, N;
	cin >> N >> M;
	vector<vector<int>> g(M, vector<int>(3));
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> g[i][j];
	}
	int mi = min({ g[0][0],g[0][1],g[0][2] });
	bool order = 0;
	if (mi == g[0][0])
	{
		if (g[0][1] > g[0][2])
			order = 1;
	}
	else if (mi == g[0][1])
	{
		if (g[0][0] > g[0][2])
		{
			order = 1;
			swap(g[0][0], g[0][1]);
		}
		else
		{
			swap(g[0][0], g[0][1]);
			swap(g[0][1], g[0][2]);
		}
	}
	else
	{
		if (g[0][0] < g[0][1])
		{
			order = 1;
			sort(g[0].begin(), g[0].end());
		}
		else
		{
			swap(g[0][0], g[0][1]);
			swap(g[0][1], g[0][2]);
		}
	}
	for (int i = 1; i < g.size(); i++)
	{
		if (!order)
		{
			sort(g[i].begin(), g[i].end());
		}
		else
		{
			sort(g[i].begin(), g[i].end());
			swap(g[i][1], g[i][2]);
		}
	}
	for (auto x : g)
		cout << x[0] << " " << x[1] << " " << x[2] << endl;
}

