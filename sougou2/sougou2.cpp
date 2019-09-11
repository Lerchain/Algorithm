#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;


int N = 0;
int minTime(map<int, vector<int>> m, int k)
{
	N++;
	vector<int> v(N, 0);
	for (auto x : m)
	{
		vector<int> t = x.second;
		for (int i = 0; i < t.size(); i++)
		{
			v[t[i]]++;
		}
	}
	int start = 0;
	for (int i = 0; i < N; i++)
	{
		if (v[i] == 0)
		{
			start = v[i];
		}
	}
	int res = 0;
	queue<pair<int,int>> q;
	q.push(make_pair(start,0));
	while (!q.empty())
	{
		int cur = q.front().first;
		int curres = q.front().second;
		q.pop();
		res = max(res, curres);
		vector<int> t = m[cur];
		int cnt = 0,cnt2 = 1;
		while (cnt<t.size())
		{
			q.push(make_pair(t[cnt++], curres + cnt2));
			if (cnt%k == 0)
				cnt2++;
		}
	}
	return res;
}
int main()
{
	int k, r;
	cin >> k >> r;
	map<int, vector<int>> m;
	for (int i = 0; i < r; i++)
	{
		int n,f;
		cin >> n;
		N += n-1;
		cin >> f;
		for (int j = 0; j < n-1; j++)
		{
			int t;
			cin >> t;
			m[f].push_back(t);
		}
	}
	int res = minTime(m,k);
	cout << res;
}

