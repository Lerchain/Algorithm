#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int N;
	cin >> N;
	string res = "";
	bool flag = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i & 1)
		{
			res = res + "A";
		}
		else
		{
			if (!flag)
			{
				res = res + "B";
				flag = 1;
			}
			else
			{
				res = res + "C";
				flag = 0;
			}
		}
	}
	cout << res;
}

