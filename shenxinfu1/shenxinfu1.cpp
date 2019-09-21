#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;


class TreeNode
{
public:
	TreeNode(char _val) :val(_val), left(nullptr), right(nullptr)
	{
	}
	TreeNode* left, *right;
	char val;
};

TreeNode* change(vector<char> v)
{
	int n = v.size();
	if (!n)
		return nullptr;
	map<int, TreeNode*> leftchild;
	map<int, TreeNode*> rightchild;
	TreeNode* dummy = nullptr;
	for (int i = 0; i < n; i++)   
	{
		int l = 2 * (i + 1), r = 2 * (i + 1) + 1;
		if (v[i] == '#')
			continue;
		//if(i)
		TreeNode * cur = new TreeNode(v[i]); 
		if (!i)
			dummy = cur;
		if (l <= n && v[l - 1] != '#')
		{
			leftchild[l - 1] = cur;
		}
		if (r <= n && v[r - 1] != '#')
		{
			rightchild[r - 1] = cur;
		}
		if (leftchild[i])
		{
			leftchild[i]->left = cur;
		}
		else if (rightchild[i])
		{
			rightchild[i]->right = cur;
		}
	}
	return dummy;
}
void preorder(TreeNode* root)
{
	if (!root)
	{
		cout << '#' << endl;
		return;
	}
	cout << root->val << endl;
	preorder(root->left);
	preorder(root->right);
}
int main()
{
	int n;
	cin >> n;
	vector<char> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	TreeNode* root = change(v);
	preorder(root);
	string s;
	auto it = s.end() - 2;

}

