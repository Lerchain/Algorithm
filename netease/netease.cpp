#include "pch.h"
#include <iostream>

using namespace std;

bool judge(int t)
{
	string s = "";
	while (t)
	{
		if (t % 2)
			s = "1" + s;
		else
			s = "0" + s;
		t /= 2;
	}
	for (int l = 0, r = s.size() - 1; l < r; l++, r--)
	{
		if (s[l] != s[r])
			return false;
	}
	return true;
}
int main()
{
	int T;
	cin >> T;
	for (int  i = 0; i < T; i++)
	{
		int t;
		cin >> t;
		if (judge(t))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

