#include "pch.h"
#include <iostream>
#include <string>

//问：从1-4中选取3个不重复的数字，打印出所有的顺序。最后打印出个数。

//这题真的很简单，然后当时devcpp这个ide就是编译不了。坑啊。就是显示to_string（）没有这个方法，我也是服。

//其实最后就只是错在了vis[num],判断应该最先判断。
using namespace std;
int cnt;
int vis[5];

string tostring(int n)//有点难受，我发现我还真不会实现to_string的实现。
{
	char t[2] = { '0' + n,'\0' };
	return t;	//原来char[]和string是相等的（结尾有\0），可以自动转化的
}
void dfs(int n, string s, int num)
{
	if (vis[num])
		return;						
	if (n > 3)
		return;
	if (n == 3)
	{
		cout << s << " ";
		cnt++;
		return;
	}
	vis[num] = 1;
	for (int i = 1; i <= 4; i++)
	{
		dfs(n + 1, s + tostring(i), i);
	}
	vis[num] = 0;
}

int main()
{
	for (int i = 1; i <= 4; i++)
	{
		memset(vis, 0, sizeof(vis));
		dfs(1,tostring(i), i);
	}
	cout << endl;
	cout << cnt;
}
