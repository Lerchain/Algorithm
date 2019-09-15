#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

//啊啊啊啊啊啊啊啊啊啊啊好气啊
//一他妈考试结束自己调试就知道错哪了
//笨死了做两道题能做俩点，还他妈没做对，太弟弟了啊啊啊。
vector<vector<int>> group(vector<pair<float, float>>& v,int d)
{
	int n = v.size();
	map<int, vector<int>> m;
	for (int i = 0; i < n; i++)
	{
		float x1 = v[i].first;
		float y1 = v[i].second;
		for (int j = 0; j < n; j++)
		{
			float x2 = v[j].first;
			float y2 = v[j].second;
			if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) > d)
				continue;
			m[i].push_back(j);
		}
	}
	vector<bool> vis(n, 0);
	vector<vector<int>> res;
	for (int i = 0; i < n; i++)
	{
		if (vis[i])
			continue;
		queue<int> q;
		set<int> s;
		q.push(i);
		while (!q.empty())
		{
			int num = q.front();
			q.pop();
			s.insert(num);
			vector<int> t = m[num];
			vis[num] = 1;
			for (int i = 0; i < t.size(); i++)
			{
				if (vis[t[i]])
					continue;
				vis[t[i]] = 1;
				s.insert(t[i]);
				q.push(t[i]);
			}
		}
		res.push_back(vector<int>(s.begin(), s.end()));
	}
	return res;
}
int main()
{
	float d;
	int N;
	cin >> d >> N;
	vector<pair<float, float>> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	vector<vector<int>> res = group(v,d);
	for (auto x : res)
	{
		for (auto y : x)
		{
			cout << y << " ";
		}
		cout << endl;
	}
}

