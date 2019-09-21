#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int MI = INT_MAX;
int N;
vector<bool> vis(21, 0);
void dfs(int pos, int n, vector<pair<int, int>>& v, int cur, int res)
{
	if (n == N)
	{
		MI = min(MI, res);
		return;
	}
	if (res > MI||vis[pos])
		return;
	int deadtime = v[pos].first;
	cur += v[pos].second;
	if (deadtime < cur)
		res += cur - deadtime;
	vis[pos] = 1;
	for (int i = 0; i < N; i++)
	{
		dfs(i, n + 1, v, cur, res);
	}
	vis[pos] = 0;
}
int main()
{
	cin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	for (int i = 0; i < N; i++)
	{
		vis.clear();
		vis.resize(N, false);
		dfs(i, 0, v, 0, 0);
	}
	cout << MI;
}

