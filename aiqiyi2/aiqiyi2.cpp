#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//有一个非常经典的概率问题，是一个袋子里面有若干个红球和若干个蓝球，两个人轮流取出一个球，谁先取到红球谁就赢了，当人的先后顺序和球的数量确定时，双方的胜率都可以由计算得到，这个问题显然是很简单的。

现在有一个进阶版的问题，同样是一个袋子里面有n个红球和m个蓝球，共有A，B，C三人参与游戏，三人按照A，B，C的顺序轮流操作，在每一回合中，A，B，C都会随机从袋子里面拿走一个球，然而真正分出胜负的只有A，B两个人，没错，C就是来捣乱的，他除了可以使得袋子里面减少一个球，没有其他任何意义，而A，B谁 先拿到红球就可以获得胜利，但是由于C的存在，两人可能都拿不到红球，此时B获得胜利。
int main()
{
	int A, B;
	cin >> A >> B;
	vector<vector<float>> dp(A+1,vector<float>(B+1,-1));
	dp[1][0] = 1;
	dp[0][1] = 0;
	dp[1][1] = 1.0 / 2;
	dp[1][2] = 1.0 / 3;
	dp[2][1] = 1.0 / 2;
	dp[2][2] = 2.0 / 3;
	for (int i = 3; i <= A; i++)
	{
		for (int j = 3; j <= B; j++)
		{
			dp[i][j] = max(dp[i - 1][j - 2], dp[i][j - 3]);
		}
	}
	cout<< dp[A][B];

}

#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std; 
void Permutation(vector<vector<int >> &result,vector<int > str,int begin)
{
	if(begin == str.size() - 1)
		result.push_back(str); 
	else
	{ 
		for(int i = begin;i < str.size();i++)
		{
			if(i != begin && str[i] == str[begin])
				continue; 
			swap(str[begin], str[i]); 
			Permutation(result, str, begin+1); 
			swap(str[begin], str[i]);
		}
	}
} vector<vector<int >> Permutation(vector<int > str) {
	vector<vector<int >> result; if (str.size() == 0) return result; Permutation(result, str, 0); sort(result.begin(), result.end()); return result;
} int main() {
	int N; cin >> N; vector<int > str; for (int i = 0; i < N - 1; ++i) {
		int a; cin >> a; str.push_back(a);
	} vector<int > nums; for (int l = 1; l <= N; ++l) {
		nums.push_back(l);
	} vector<vector<int >> result = Permutation(nums); int count = 0; for (int i = 0; i < result.size(); ++i) {
		int flag1 = 0; int flag2 = 0; for (int j = 0; j < result[i].size() - 1; ++j) {
			if (str[j] == 0) {
				if (result[i][j] < result[i][j + 1]) {
					flag1 += 1;
				}
			} if (str[j] == 1) {
				if (result[i][j] > result[i][j + 1]) {
					flag2 += 1;
				}
			}
		} if (flag1 + flag2 == result[i].size() - 1) {
			count++;
		}
	} std::cout << count % 1000000007 << std::endl; return 0;
}
