#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int INF = 1000000;
int dx[4]{ -1, 0, 0, 1 };
int dy[4]{ 0, -1, 1, 0 };
int shortestPath(vector<string>& grid) {
	int n = grid.size();
	int m = grid[0].size();
	int startx, starty, endx, endy;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == 'S')
			{
				startx = i;
				starty = j;
			}
			if (grid[i][j] == 'E')
			{
				endx = i;
				endy = j;
			}
		}
	}
	vector<vector<int>> d(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			d[i][j] = INF;
		}
	}
	queue<pair<int, int>> q;
	q.push(pair<int, int>(startx, starty));
	d[startx][starty] = 1;
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		if (r == endx && c == endy)
			return d[r][c];
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = r + dx[i];
			int y = c + dy[i];
			if (x == n)
				x = 0;
			if (y == m)
				y = 0;
			if (x == -1)
				x = n-1;
			if (y == -1)
				y = m - 1;
			if (grid[x][y] != '#' && d[x][y] > d[r][c] + 1)
			{
				q.push(pair<int, int>(x, y));
				d[x][y] = d[r][c] + 1;
			}
		}
	}
	return -1;
}
class B
{
public:
	const int a;
	B(int v):a(v){}
	void show()
	{
		cout << a;
	}
};
int main()
{
	/*int N;
	cin >> N;
	vector<string> grid(N);
	for (int i = 0; i < N; i++)
	{
		cin >> grid[i];
	}
	int res = shortestPath(grid);
	cout << res;*/
	B b(10);
	b.show();
}
