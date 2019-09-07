#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int maxTimes(int k, vector<int>& v)
{
	int n = v.size();
	int month[30]{};
	for (int i = 0; i < n; i++)
	{
		int t = v[i] - 1;
		for (int j = t-k; j <= t+k; j++)
		{
			if (j < 0 || j >= 30)
				continue;
			month[j] = -1;
		}
	}
	int res = n;
	//bool flag = 0;
	for (int i = 0; i < 30; )
	{
		if (month[i] != -1)
		{
			res++;
			i += k + 1;
		}
		if (month[i] == -1)
		{
			i++;
		}
	}
	return res;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int K, M;
		cin >> K >> M;
		vector<int> v(M);
		for (int j = 0; j < M; j++)
		{
			cin >> v[j];
		}
		int m = maxTimes(K, v);
		cout << m << endl;
	}
}

