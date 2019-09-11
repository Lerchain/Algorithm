#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//1153721298

string change(unsigned N)
{
	string res = "";
	vector<char> v{ 'S', 'B', 'Q', 'W', 'Y' };
	unsigned cnt = 0;
	bool flag = 0,flag2 = 0;
	while (N)
	{
		int n = N % 10;
		N /= 10;
		if (!flag)
		{
			if(n)
				res = to_string(n) + res;
			flag = 1;
		}
		else
		{
			if (n)
				res = to_string(n) + v[cnt] + res;
			cnt++;
			if (cnt == 5 )
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
	return res;
}
int main()
{
	unsigned N;
	cin >> N;
	string res = change(N);
	cout << res;
}