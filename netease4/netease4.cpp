#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//啊啊啊啊啊啊啊！网易的第4题啊！再给我5分钟不到啊就能调试好了啊啊啊啊！哎。
bool judge(int k, vector<string>& grid, int r, int c)
{
	int R = grid.size();
	int C = grid[0].size();
	for (int i = r ; i < r+k ; i++)
	{
		for (int j = c-k; j < c; j++)
		{
			if (i < 0 || i >= R || j < 0 || j >= C)
				return false;
			if (grid[i][j] == '1')
				return false;
		}
	}
	for (int i = r; i < r + k; i++)
	{
		for (int j = c+k+1; j < c+2*k; j++)
		{
			if (i < 0 || i >= R || j < 0 || j >= C)
				return false;
			if (grid[i][j] == '1')
				return false;
		}
	}
	for (int i = r+2*k; i < r + 3*k; i++)
	{
		for (int j = c - k; j < c; j++)
		{
			if (i < 0 || i >= R || j < 0 || j >= C)
				return false;
			if (grid[i][j] == '1')
				return false;
		}
	}
	for (int i = r+2*k; i < r + 3*k; i++)
	{
		for (int j = c + k + 1; j < c + 2 * k; j++)
		{
			if (i < 0 || i >= R || c < 0 || c >= C)
				return false;
			if (grid[i][j] == '1')
				return false;
		}
	}
	for (int i = r; i < r + 3 * k; i++)
	{
		for (int j = c; j < c+k; j++)
		{
			if (i < 0 || i >= R || j < 0 || j >= C)
				return false;
			if (grid[i][j] == '0')
				return false;
		}
	}
	for (int i = r+k; i < r + 2 * k; i++)
	{
		for (int j = c-k; j < c + 2* k; j++)
		{
			if (i < 0 || i >= R || j < 0 || j >= C)
				return false;
			if (grid[i][j] == '0')
				return false;
		}
	}
	return true;
}
vector<int> maxSquare(vector<string>& grid)
{
	int R = grid.size();
	if (!R)
		return { -1,-1,-1,-1 };
	int C = grid[0].size();
	vector<int> res(4, -1);
	int M = 0;
	for (int i = 0; i < R; i++)
	{
		int cnt1 = 0;
		bool flag = 0;
		for (int j = 0; j < C; j++)
		{
			if (grid[i][j] == '1')
			{
				cnt1++;
			}
			else
			{
				if (cnt1 > M&&judge(cnt1, grid, i, j - cnt1))
				{
					M = cnt1;
					res[0] = i + 1;
					res[1] = j - cnt1;
					res[2] = i + 1 + cnt1+1;
					res[3] = j+1;
				}
				cnt1 = 0;
			}
		}
	}
	return res;
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n >> m;
		vector<string> grid(n);
		for (int j = 0; j < n; j++)
		{
			cin >> grid[j];
		}
		vector<int> res = maxSquare(grid);
		for (auto x:res)
		{
			cout << x << " ";
		}
		cout << endl;
	}
}

