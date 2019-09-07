#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//这题一看就特别眼熟，但我还是有点愁的慌，因为可能不太会做
//思路最先想到的准定会是DFS，每跳到一个点，递归所有弹簧可能的情况，最后比较所有可能的解选最小值。
//但这明显复杂度太高了AC不了。
//数组长度小于1000，也就是O(N^2）就行，动态规划呗。
//艾玛愁得慌动态规划到现在我都有点懵。

int minTimes(vector<int>& v)
{
	int n = v.size();
//	int dp[1005]{INT_MAX};//dp[i]为第i个点的最小次数。
	vector<int> dp(n, INT_MAX);
//dp[i] = max(dp[i-1]+1,dp[i-2]+1,一直到dp[0]+1)，并且得是在v[i-?]能跳到i的情况下；
	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (j + v[j] >= i)
				dp[i] = min(dp[i], dp[j] + 1);
		}
	}
	return dp[n-1];
}
int main()
{
	vector<int> v;
	int t;
	while (cin >> t)
	{
		v.push_back(t);
	}
	int res = minTimes(v);
	cout << res;
}
