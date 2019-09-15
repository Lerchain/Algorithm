#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

//没时间了，字符串分割函数还没做，转换函数也没做好。

vector<string> change(vector<float>& v)
{
	string res = "";
	vector<string> v{ "什", "佰", "仟", "万", "亿" };
	map<int, string> m;
	m[0] = "零";
	m[1] = "壹";
	m[2] = "贰";
	m[3] = "叁";
	m[4] = "肆";
	m[5] = "伍";
	m[6] = "陆";
	m[7] = "柒";
	m[8] = "捌";
	m[9] = "玖";
	unsigned cnt = 0;
	int n = v.size();
	vector<string> ans(n);
	for (int i = 0; i < n; i++)
	{
		string res = "\"]";
		float N = v[i];
		if (N == int(N))
		{
			res = "整" + ans;
		}
		bool flag = 0, flag2 = 0;
		while (N)
		{
			int n = N % 10;
			N /= 10;
			if (!flag)
			{
				if (n)
					res = to_string(n) + res;
				flag = 1;
			}
			else
			{
				if (n)
					res = to_string(n) + v[cnt] + res;
				cnt++;
				if (cnt == 5)
				{
					cnt = 0;
				}
				if (cnt == 4 && !flag2)
				{
					cnt = 0;
					flag2 = 1;
				}
				else if (cnt == 3 && flag2)
				{
					cnt = 4;
					flag2 = 0;
				}
			}
		}

	}
}
int main()
{
	string s;
	cin >> s;
	vector<float> v = split(s.substr(1, s.size() - 2));
	vector<string> res = change(v);
	cout << "[";
	for (auto x : res)
	{
		cout << x << ",";
	}
	cout << "]";
}