#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int R, C,changedir;
int dir[4][4] = { {1,0},{0,1},{-1,0},{0,-1} };
void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& vis)
{
	if (r >= R || r < 0 || c >= C || c < 0 || vis[r][c])
	{
		changedir = (changedir + 1) % 4;
		return;
	}
	cout << grid[r][c]<<" ";
	vis[r][c] = 1;
	dfs(grid, r + dir[changedir][0], c + dir[changedir][1],vis);
	dfs(grid, r + dir[changedir][0], c + dir[changedir][1], vis);
}
int main()
{
	int n, m;
	cin >> n >> m;
	R = n; C = m;
	vector<vector<bool>> vis(n,vector<bool>(m,0));
	vector<vector<int>> grid(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
		}
	}
	dfs(grid,0,0,vis);
}

