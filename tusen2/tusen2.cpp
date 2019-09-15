#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int res = -1;
int N;


bool isPrime(string l, int c, string r)
{
	string t = l;
	t[c] = r[c];
	int num = stoi(t);
	for (int i = 2; i < num; i++)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}
void dfs(vector<int>& diff, vector<int>& vis, int n, int changenum, string l, string r)
{
	if (n == N)
	{
		res = n;
	}
	if (vis[changenum] || !isPrime(l, changenum, r))
	{
		return;
	}
	diff.erase(find(diff.begin(), diff.end(), changenum));
	vis[changenum] = 1;
	for (auto x : diff)
	{
		dfs(diff, vis, n + 1, x, l, r);
	}
	vis[changenum] = 0;
}
bool judge(pair<string, string> p)
{
	string l = p.first, r = p.second;
	if (l.size() != r.size())
		return false;
	vector<int> diff;
	for (int i = 0; i < l.size(); i++)
	{
		if (l[i] != r[i])
		{
			diff.push_back(i);
		}
	}
	N = diff.size();
	vector<int> temp = diff, mi(N);
	vector<int> vis(l.size(), 0);
	for (int i = 0; i < diff.size(); i++)
	{
		diff = temp;
		vis.clear();
		vis.resize(l.size());
		dfs(diff, vis, 1, diff[i], l, r);
		if (diff.size() < mi.size())
			mi = diff;
	}
	int z = N - mi.size();
	for (int i = 0; i < mi.size(); i++)
	{

	}
	if (res != -1)
		return true;
	return false;
}
int main()
{
	int n;
	cin >> n;
	vector<pair<string, string>> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	for (auto x : v)
	{
		res = -1;
		if (judge(x))
			cout << res << endl;
		else
			cout << -1 << endl;
	}
}

