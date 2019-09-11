#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

//滑动窗口
int C = 1000000001;
int main()
{
	int N;
	cin >> N;
	int sum = 0;
	int res = 0;
	int j = 1;
	for (int i = 1; i <= C; i++)
	{
		if (i > N)
		{
			cout << res;
			break;
		}
		sum += i;
		while (sum >= N)
		{
			if (sum == N)
				res++;
			sum -= j;
			j++;
		}
	}
}
