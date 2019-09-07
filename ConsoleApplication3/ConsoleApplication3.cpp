#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000;
int dx[8]{ -1, 0, 0, 1 };
int dy[8]{ 0, -1, 1, 0 };
int shortestPath(vector<vector<int>>& grid) {
	using pii = pair<int, int>;
	int n = grid.size();
	int m = grid[0].size();
	if (grid[0][0] || grid[n - 1][m - 1])
		return 0;
	vector<vector<int>> d(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			d[i][j] = INF;
		}
	}
	queue<pii> q;
	q.push(pii(0, 0));
	d[0][0] = 1;
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		if (r == n - 1 && c == m - 1)
			return d[r][c];
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = r + dx[i];
			int y = c + dy[i];
			if (x >= 0 && x < n && y >= 0 && y<m && !grid[x][y] && d[x][y] > d[r][c] + 1)
			{
				q.push(pii(x, y));
				d[x][y] = d[r][c] + 1;
			}
		}
	}
	return 0;
}
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> grid(n, vector<int>(m, 0));
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		grid[x][y] = 1;
	}
	int res = shortestPath(grid);
	cout << res;
}
