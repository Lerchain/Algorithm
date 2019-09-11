#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int t;
	vector<int> v;
	while (cin>>t)
	{
		v.push_back(t);
		if (cin.get() == '\n')
			break;
	}
	int k;
	cin >> k;
	int n = v.size();
	vector<float> res(n-k);
	for (int i = 0; i < n - k; i++)
	{
		int sum = 0;
		for (int j = i; j < k+i; j++)
		{
			sum += v[j];
		}
		res[i] = (float)sum / k;
	}
	for (int i = 0; i < n-k; i++)
	{
		printf("%.2f ",res[i]);

	}
}

