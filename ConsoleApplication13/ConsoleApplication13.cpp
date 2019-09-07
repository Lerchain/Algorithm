#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//这题的思路是每一行我都用一个vector来存，最后汇总起来
string change(string s, int row)
{
	int n = s.size();
	vector<string> v(n);
	int cnt = 0;	//记录s的下标
	bool flag = 0; //循环终止条件
	while (1)
	{
		for (int i = 0; i < row; i++)	
		{
			v[i] = v[i] + s[cnt];
			cnt++;
			if (cnt == n)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
		for (int i = row - 2; i > 0; i--)	//稍注意一下这里循环开始条件与结束条件都要少一个，因为拐点只有一个值嘛。
		{
			v[i] = v[i] + s[cnt];
			cnt++;
			if (cnt == n)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}
	string res = "";
	for (int i = 0; i < row; i++)
		res = res + v[i];
	return res;
}
int main()
{
	string s;
	int r;
	cin >> s >> r;
	string res = change(s, r);
	cout << res;
}
