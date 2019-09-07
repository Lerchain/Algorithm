#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
	TreeNode(int v) :val(v), left(nullptr), right(nullptr)
	{
	}
	int val;
	TreeNode* left;
	TreeNode* right;
};


TreeNode* constructTree(vector<vector<int>>& v)
{
	int n = v.size();
	if (!n)
		return nullptr;
	vector<bool> a(n,0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			if (v[i][j] != -1)
				a[v[i][j]] = 1;
		}
	}
	int rootNum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
			rootNum = i;
	}
	TreeNode* root = new TreeNode(v[rootNum][0]);
	TreeNode* p = root;
	queue<pair<TreeNode*,int>> q;
	q.push(make_pair(root,rootNum));
	while (!q.empty())
	{
		TreeNode* cur = q.front().first;
		int num = q.front().second;
		q.pop();
		if (v[num][1]!= -1)
		{
			int leftnum = v[num][1];
			cur->left = new TreeNode(v[leftnum][0]);
			q.push(make_pair(cur->left, leftnum));
		}
		if (v[num][2] != -1)
		{
			int rightnum = v[num][2];
			cur->right = new TreeNode(v[rightnum][0]);
			q.push(make_pair(cur->right, rightnum));
		}
	}
	return root;
}

bool judge(TreeNode* root)
{
	if (!root)
		return false;
	queue<pair<TreeNode*,int>> q;
	q.push(make_pair(root,0));
	int presum = 0, cursum = 0, preh = 0, curh = 0;
	while (!q.empty())
	{
		TreeNode* cur = q.front().first;
		curh = q.front().second;
		q.pop();
		if (curh > preh)
		{
			preh = curh;
			if (cursum < presum)
				return false;
			presum = cursum;
			cursum = 0;
		}
		cursum += cur->val;
		if (cur->left)
			q.push(make_pair(cur->left, curh + 1));
		if (cur->right)
			q.push(make_pair(cur->right, curh + 1));
	}
	if (cursum < presum)
		return false;
	return true;
}
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		vector<vector<int>> v(N, vector<int>(3, 0));
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cin >> v[j][k];
			}
		}
		TreeNode* root = constructTree(v);
		if (judge(root))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
