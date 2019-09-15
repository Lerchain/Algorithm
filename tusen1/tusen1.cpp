#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int find(vector<string>& grid)
{
	int R = grid.size();
	if (!R)
		return 0;
	int C = grid[0].size();
	int res = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (grid[i][j] == '0' || i - 1 < 0 || i + 1 >= R || j - 1 < 0 || j + 1 >= C || grid[i - 1][j] == '0' || grid[i + 1][j] == '0' || grid[i][j - 1] == '0' || grid[i][j + 1] == '0')
				continue;
			res++;
		}
	}
	return res;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (int i = 0; i < n; i++)
	{
		cin >> grid[i];
	}
	cout << find(grid);
}
