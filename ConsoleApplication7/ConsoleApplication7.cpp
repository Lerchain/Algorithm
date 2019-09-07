#include "pch.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	};
};

/*请完成下面这个函数，实现题目要求的功能
******************************开始写代码******************************/
ListNode* partition(ListNode* head, int m) {
	vector<int> v;
	ListNode* p = head;
	while (p)
	{
		v.push_back(p->val);
		p = p->next;
	}
	int n = v.size();
	vector<int> ref,reb;
	for (int i = 0; i < n; i++)
	{
		if (v[i] < m)
			ref.push_back(v[i]);
		else
			reb.push_back(v[i]);
	}
	p = head;
	for (int i = 0; i < ref.size(); i++)
	{
		p->val = ref[i];
		p = p->next;
	}
	for (int i = 0; i < reb.size(); i++)
	{
		p->val = reb[i];
		p = p->next;
	}
	return head;
}
/******************************结束写代码******************************/


int main() {
	ListNode* head = NULL;
	ListNode* node = NULL;
	int m;
	cin >> m;
	int v;
	while (cin >> v) {
		if (head == NULL) {
			node = new ListNode(v);
			head = node;
		}
		else {
			node->next = new ListNode(v);
			node = node->next;
		}
	}
	head = partition(head, m);
	if (head != NULL) {
		cout << head->val;
		node = head->next;
		delete head;
		head = node;
		while (head != NULL) {
			cout << "," << head->val;
			node = head->next;
			delete head;
			head = node;
		}
	}
	cout << endl;
	return 0;
}
