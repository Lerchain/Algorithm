#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int N;
string res = "";
int flag = 0;
void dg(string s, int n,string t)
{
	if (n == N)
	{
		res = s;
		return;
	}
	int ch = t[n];
	if (ch == '(')
	{
		flag++;
		dg(s, n + 1, t);
	}
	else if (flag&&ch != ')')
	{
		dg(s, n + 1, t);
	}
	else if (flag&&ch == ')')
	{
		flag --;
		dg(s, n + 1, t);
	}
	else if (ch == '<')
	{
		if (s == "")
			dg(s, n + 1, t);
		else
		{
			s = s.substr(0, s.size() - 1);
			dg(s, n + 1, t);
		}
	}
	else
		dg(s + t.substr(n,1), n + 1, t);
}
string change(string t)
{
	N = t.size();
	dg("",0,t);
	return res;
}
int main()
{
	string t;
	cin >> t;
	t = change(t);
	cout << t;

}

