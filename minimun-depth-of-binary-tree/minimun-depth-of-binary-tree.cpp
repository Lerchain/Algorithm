#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


class TreeNode
{
public:
	TreeNode(int _val):val(_val),left(nullptr),right(nullptr)
	{
	}
	TreeNode* left, *right;
	int val;
};

class Solution {
public:
	int run(TreeNode *root) {
		M = INT_MAX;	//这里有个有趣的地方，由于测试用例一直在网上提交我都没注意到。
		h = 0;	//这两个私有成员变量是需要每次调用都重设置值的。否则保存的就是多次调用的最小值了。
		if (!root)
			return 0;
		preorder(root);
		return M;
	}
	void preorder(TreeNode* root)
	{
		if (!root)
			return;
		h++;
		if (!root->left && !root->right)
			M = min(M, h);
		preorder(root->left);
		preorder(root->right);
		h--;
	}
private:
	int M = INT_MAX;
	int h = 0;
};

//结果真正难的是自己出的题，
//我觉的这可以转换成dfs，
//遍历一遍数组，使用map<int,TreeNode*>,key存左子树的位置，value存当前的节点，如果左子树是空的当然就不存了，右子树也是同理。
//然后看当前节点i有没有对应的key,它的value就是当前节点的父节点。但不知道是左子树还是右子树，所以用两个map，分别整。
//这样再连接就ok了。
TreeNode* change(vector<int> v)
{
	int n = v.size();
	if(!n)
		return nullptr;
	map<int, TreeNode*> leftchild;
	map<int, TreeNode*> rightchild;
//	TreeNode * dummy = new TreeNode(v[0]);
//	TreeNode * cur = dummy;
	TreeNode* dummy = nullptr;
	for (int  i = 0; i < n; i++)   //忘记了地址是从0开始，直接*2是不对的
	{
		int l = 2 * (i+1), r = 2*(i+1) +1;
		if (v[i] == NULL)
			continue;
		//if(i)
		TreeNode * cur = new TreeNode(v[i]); //经过调试发现这里有问题，新创建的cur是在if框内,明显的作用域问题，多套了个循环就疏忽了。
		if (!i)
			dummy = cur;
		if (l <= n&&v[l-1] != NULL)
		{
			leftchild[l-1] = cur;
		}
		if (r <= n&&v[r-1] != NULL)
		{
			rightchild[r-1] = cur;
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
int main()
{
	TreeNode *p = change({ 1,2 });
	Solution s;
	cout << s.run(p)<<endl;
	TreeNode* q = change({ 1,2,3,4,5,NULL,7,NULL,NULL,10,11 });//唯一的大问题就是NULL其实是0，也就是说数组里不能有0.但是，vector只能容纳int，所以目前还没想出办法。
	cout << s.run(q)<<endl; 
}

