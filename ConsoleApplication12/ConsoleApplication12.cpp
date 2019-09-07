#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
//首先题目要求求最小时间。

int minSecond(string s)
{
	int n = s.size();
	map<char, int> m;
	if (n == 1)	//如果只有一个字符，那最小就是0
		return 0;
	if (n == 2)//如果只有俩字符，那就是二进制的10。
		return 2;
	m[s[0]] = 1;
	m[s[1]] = 0;
	for (int i = 2; i < n; i++) //由于只有前两位不符合正常规律，所以如果超过两个了，那么接下来的递增就好
	{
		if (m[s[i]])
			continue;
		int curmax = 0;
		for (auto x : m)	//为了让每个字符记录的都是最小值当前可能的最小值。
			curmax = max(curmax, x.second);
		m[s[i]] = curmax+1;
	}
	int cnt = m.size();	//统计字符串中到底有多少不同字符。
	//这个cnt就代表几进制了。
	int minNum = 0;	//由于字符串小于10，所以最大也不会超过int的范围
	for (int i = 0; i < n; i++)//遍历一遍字符串，每一位都有对应的数字。
	{
		minNum += m[s[i]] * pow(cnt, n - 1 - i);//cnt进制转化为10进制
	}
	return minNum;
}
int main()
{
	string s;
	cin >> s;
	int res = minSecond(s);
	cout << res;
}

