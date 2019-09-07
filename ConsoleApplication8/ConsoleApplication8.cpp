#include "pch.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <string>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
string resolve(string s) {
	int n = s.size();
	vector<int> l, r;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			l.push_back(i);
		if (s[i] == ')')
			r.push_back(i);
	}
	int ls = l.size();
	int rs = r.size();
	if (ls != rs)
		return "";
	for (int i = 0; i < ls; i++)
	{
		int zuo = l.back();
		int you = r.front();
		l.pop_back();
		r.erase(r.begin());
		for (int j = zuo, k = you; j < k; j++, k--)
		{
			while (j < k && (s[j] == '(' || s[j] == ')'))
			{
				j++;
			}
			while (j < k && (s[k] == '(' || s[k] == ')'))
			{
				k--;
			}
			swap(s[j], s[k]);
		}
	}
	string res = "";
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(' || s[i] == ')')
			continue;
		res += s[i];
	}
	return res;
}
/******************************结束写代码******************************/


int main() {
	string res;

	string _expr;
	cin >> _expr;

	res = resolve(_expr);
	cout << res << endl;

	return 0;

}
