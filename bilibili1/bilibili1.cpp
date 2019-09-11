#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//思路是先求最长公共子序列，然后在此基础上判断需要多少操作
//时间不够了，难受。

int Times(string s1, string s2)
{
	int n1 = s1.size();
	int n2 = s2.size();
	int ns = min(n1, n2);
	int ma = INT_MIN;
	for (int i = 0; i < ns; i++)
	{
		for (int j = 0; j < ns; j++)
		{
			for (int k = 0; k < ns; k++)
			{
				if(s1[j] == s2[k])
			}
		}
	}
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int res = Times(s1, s2);
	cout << res;
}

