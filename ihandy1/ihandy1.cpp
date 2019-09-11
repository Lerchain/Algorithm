
#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> v(N,0);
	for (int i = 0; i < M; i++)
	{
		int s,e;
		cin >> s>>e;
		for (int i = s; i < e; i++)
			v[i]++;
	}
	int res = 0;
	for (int i = 0; i < N; i++)
	{
		if (v[i] & 1)
			res++;
	}
	return res;
}

