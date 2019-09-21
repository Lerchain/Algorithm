#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int res = 10086;
char E;
string S;
void dfs(int pos, vector<pair<pair<char, char>, int>>& v, string s, int cnt)
{
	if (v[pos].first.second == E)
	{
		if (res > cnt)
		{
			res = cnt;
			S = s;
		}
		return;
	}
	string t = s.substr(0, s.size() - 2);
	if (find(t.begin(), t.end(), v[pos].first.second) != t.end())
		return;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].first.first == v[pos].first.second)
		{
			string t = " " + s;
			t = t + v[pos].first.second;
			dfs(i, v, s + " " + t, cnt + v[i].second);
		}
	}
}
int main()
{
	vector<pair<pair<char, char>, int>> v = {
		make_pair(make_pair('A','B'),12),make_pair(make_pair('C','D'),3),
		make_pair(make_pair('B','C'),10),make_pair(make_pair('D','E'),4),
		make_pair(make_pair('C','F'),6),make_pair(make_pair('F','A'),16),
		make_pair(make_pair('E','F'),2),make_pair(make_pair('B','F'),7),
		make_pair(make_pair('C','E'),5) };

	int n = v.size();
	char b, e;
	cin >> b >> e;
	E = e;
	vector<int> begin;
	for (int i = 0; i < n; i++)
	{
		if (v[i].first.first == b)
			begin.push_back(i);
	}
	for (int i = 0; i < begin.size(); i++)
	{
		string t = "";
		t += v[begin[i]].first.first;
		t += " ";
		t += v[begin[i]].first.second;
		t = t + " ";
		dfs(begin[i], v, t, v[begin[i]].second);
	}
	cout << res << endl;
	cout << S;
}