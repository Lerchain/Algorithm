#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int findMax(int k, vector<vector<int>>& grid)
{
	int r = grid.size(), c = grid[0].size();
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (grid[r][c] == k)
			{
				dfs();
			}
		}
	}
}
vector<int> colorSort(vector<vector<int>>& grid)
{
	int R = grid.size();
	if (!R)
		return {};
	int C = grid[0].size();
	map<int, int> m;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			m[grid[i][j]]++;
		}
	}
	vector<pair<int, int>> v;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		v.push_back(make_pair(it->first, it->second));
	}
	sort(v.begin(), v.end(), [&](pair<int, int> x, pair<int, int> y) {
		if (x.second == y.second)
		{
			int c1 = x.first,c2 = y.first;
			return findMax(c1,grid)>findMax(c2,grid);
		}
		return x.second > y.second; 
	});
	int n = v.size();
	vector<int> res(n);
	for (int i = 0; i < n; i++)
	{
		res[i] = v[i].first;
	}

	return res;
}
int main()
{
	int m, n;
	cin >> m >> n;
	vector<vector<int>> grid(m,vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}
	vector<int> res = colorSort(grid);
	for(auto x:res)
		cout << x <<" ";
	return 0;
}

