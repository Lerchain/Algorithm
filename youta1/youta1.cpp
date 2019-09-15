#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

string Plus(string s,string s2)
{
	int n1 = s.size();
	int n2 = s2.size();
	int jinwei = 0;
	for (int i = n2-1, j = n1-1; i>=0; i--,j--)
	{
		int t = s[j] - '0' + s2[i] - '0' + jinwei;
		jinwei = 0;
		if (t >= 10)
		{
			t %= 10;
			jinwei = 1;
		}
		s[j] = '0' + t;
	}
	if (jinwei)
	{
		if (n1 == n2)
		{
			s = "1" + s;
			jinwei = 0;
		}
		else
		{
			int i = 1;
			while (jinwei)
			{
				if (n1 - n2 - i == -1)
				{
					s = "1" + s;
					break;
				}
				char t = s[n1 - n2 - i];
				if (t == '9')
				{
					jinwei = 1;
					s[n1 - n2 - i] = '0';
				}
				else
				{
					s[n1 - n2 - i] = t + 1;
					jinwei = 0;
				}
				i++;
			}
		}
	}
	return s;
}
int main()
{
	string N;
	int K;
	cin >> N >> K;
	string res = N;
	int i = 2;
	while (i < K)
	{
		res = Plus(res, res);
		i += i;
	}
	i /= 2;
	while (i < K)
	{
		res = Plus(res, N);
		i++;
	}
	cout << res;
}

