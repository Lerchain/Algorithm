#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		map<string, int> m;
		int n = words.size();
		int cnt = 0;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			v[i] = i;
			cnt += words[i].size();
		}
		do
		{
			string t = "";
			for (int i = 0; i < n; i++)
			{
				t += words[v[i]];
			}
			m[t]++;
		} while (next_permutation(v.begin(), v.end()));
		vector<int> res;
		int ss = s.size();
		for (int i = 0; i <= ss - cnt; i++)
		{
			string t = s.substr(i, cnt);
			if (m[t])
				res.push_back(i);
		}
		return res;
	}
};

int main()
{
	Solution S;
	string s = "wordgoodgoodgoodbestword";
	vector<string> words = { "word","good","best","good" };
	vector<int> res = S.findSubstring(s, words);
	for (auto x : res)
	{
		cout << x << " ";
	}
}
