#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
	string s, a;
	cin >> s >> a;
	map<char, int> M;
	for (int i = 0; i < a.size(); i++)
	{
		M[a[i]]++;
	}
	vector<int> v;
	for (int i = 0; i < s.size(); i++)
	{
		if (M.find(s[i])!=M.end())
			v.push_back(i);
	}
	int minsize = 10086;
	string res = "";
	for (int i = 0; i < v.size(); i++)
	{
		string lres = "";
		bool flag = 0;
		int cnt = 0;
		map<char, int> m = M;
		for (int j = v[i]; j < s.size(); j++)
		{
			if (m.find(s[j]) != m.end())
			{
				m.erase(s[j]);
				flag = 1;
			}
			if (flag)
				lres += s[j];
			if (++cnt>minsize||m.empty())
				break;
		}
		if (m.empty()&&cnt < minsize)
		{
			minsize = cnt;
			res = lres;
		}
	}
	cout << res;
}

