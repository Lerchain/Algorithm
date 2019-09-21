#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<vector<int>>& v)
{
	int n = v.size();
	int prePos[2] = { -1,-1 };
	int res = 0;
	for (int i = 0; i < n; i++) 
	{
		vector<int> t = v[i];
		int curM = -1, curPos = -1;
		for (int j = 0; j < 5; j++)
		{
			if (curM < v[i][j])
			{
				curM = v[i][j];
				curPos = j;
			}
		}
		if (curPos == 4)
		{
			prePos[0] = -1; prePos[1] = -1;
		}
		else if (curPos == prePos[0] || curPos == prePos[1])
		{

		}
		else
		{
			prePos[0] = prePos[1];
			prePos[1] = curPos;
		}
		res += curM;
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(5));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> v[i][j];
		}
	}
	int res = getMax(v);
	cout << res;
}

