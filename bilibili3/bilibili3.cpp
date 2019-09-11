#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int CNT;
vector<vector<string>> split(char a, char b, string s)
{
	int n = s.size();
	int pre = 0;
	vector<string> v;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == a)
		{
			v.push_back(s.substr(pre, i - pre));
			pre = i + 1;
		}
	}
	v.push_back(s.substr(pre, n - pre));
	vector<vector<string>> res;
	int vn = v.size();
	for (int i = 0; i < vn; i++)
	{
		string t = v[i];
		if (find(t.begin(),t.end(),b) == t.end())
			continue;
		vector<string> vs;
		int spre = 0;
		for (int j = 0; j < t.size(); j++)
		{
			if (t[j] == b)
			{
				vs.push_back(t.substr(spre, j - spre));
				spre = j + 1;
			}
		}
		vs.push_back(t.substr(spre, t.size() - spre));
		if (vs[0] != ""&& vs[1] != "")
		{
			res.push_back(vs);
			CNT++;
		}
	}
	return res;
}
int main()
{
	char a, b;
	string s;
	cin >> a >> b >> s;
	vector<vector<string>> res = split(a,b,s);
	cout << CNT << endl;
	for (auto x : res)
	{
		for (auto y : x)
		{
			cout << y << " ";
		}
		cout << endl;
	}
}

