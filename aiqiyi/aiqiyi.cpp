#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//void next_permutation(vector<int>& nums)
//{
//	int n = nums.size();
//	int x, y;
//	for (int i = n - 1; i >= 1; i--)
//	{
//		if (nums[i] > nums[i - 1])
//		{
//			x = i - 1;
//			break;
//		}
//	}
//	for (int i = n - 1; i >= 1; i--)
//	{
//		if (nums[x] < nums[i])
//		{
//			y = i;
//			break;
//		}
//	}
//	swap(nums[x], nums[y]);
//	for (int l = x + 1, r = n - 1; l < r; l++, r--)
//	{
//		swap(nums[l], nums[r]);
//	}
//}
bool judge(vector<int>& nums, vector<int>& cmp)
{
	bool flag;
	for (int i = 0; i < cmp.size(); i++)
	{
		flag = cmp[i];
		if (flag&&nums[i] < nums[i + 1])
		{
			return false;
		}
		if (!flag&&nums[i] > nums[i + 1])
			return false;
	}
	return true;
}
int permute(vector<int>& nums ,vector<int>& cmp) {
	//vector<int> end = nums;
	int res = 0;
	/*while (nums != end)
	{
		if (judge(nums, cmp))
		{
			res++;
			res %= 10000007;
		}
		next_permutation(nums);
	}*/
	auto it = nums.begin(), ie = nums.end();
	do
	{
		if (judge(nums, cmp))
		{
			res++;
			res =res%100000007;
		}
	} while (next_permutation(it,ie));
	return res;
}

int main()
{
	int N;
	cin >> N;
	vector<int> cmp(N - 1);
	for (int i = 0; i < N - 1; i++)
	{
		cin >> cmp[i];
	}
	vector<int> nums(N);
	for (int i = 0; i < N; i++)
	{
		nums[i] = i + 1;
	}
	int res = permute(nums, cmp);
	cout << res;
}

