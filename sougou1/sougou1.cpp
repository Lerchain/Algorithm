#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;
	vector<string> guize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> guize[i];
	}
	//vector<string> guolv(M);
	for (int i = 0; i < M; i++)
	{
		string t;
		cin >> t;
		bool flag = 0;
		for (int j = 0; j < N; j++)
		{
			if (t == guize[j])
			{
				flag = 1;
				cout << "1" << " ";
			}
			string cmp = guize[j];
			int n = cmp.size();
			int cnt = 0;
			for (int k = 0; k < cmp.size(); k++)
			{
				if (cmp[k] == '.')
					cnt++;
			}
			if (cmp[0] == '*')
			{
				string temp = "";
				int c = 0;
				for (int k = t.size() - 1; k >= 0; k--)
				{
					temp = t[k] + temp;
					if (t[k] == '.')
						c++;
					if (c == cnt)
					{
						break;
					}
				}
				if ("*"+temp == cmp)
				{
					flag = 1;
					cout << "1 ";
					break;
				}
			}
			if (cmp[n - 1] == '*')
			{
				string temp = "";
				int c = 0;
				for (int k = 0; k < t.size(); k++)
				{
					temp = temp + t[k];
					if (t[k] == '.')
						c++;
					if (c == cnt)
					{
						break;
					}
				}
				if (temp + "*" == cmp)
				{
					flag = 1;
					cout << "1 ";
					break;
				}
			}
		}
		if(!flag)
		cout << "0 ";
	}
}

