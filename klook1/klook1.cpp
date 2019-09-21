#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{
	string s;
	cin >> s;
	int sum = 0;
	bool flag = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (!flag && s[i] == '6')
		{
			s[i] = '9';
		}
		sum = sum * 10 + s[i] - '0';
	}
	cout << sum;
}
