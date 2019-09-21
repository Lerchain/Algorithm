#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<char, vector<char>> m;
vector<string> res;

void dg(string s, int pos,string t)
{
	int n = s.size();
	if (pos == n)
	{
		res.push_back(t);
		return;
	}
	char num = s[pos];
	for (auto x : m[num])
	{
		dg(s, pos + 1, t + x);
	}
}
int main()
{
	m['2'] = { 'a','b','c' };
	m['3'] = { 'd','e','f' };
	m['4'] = { 'g','h','i' };
	m['5'] = { 'j','k','l' };
	m['6'] = { 'm','n','o' };
	m['7'] = { 'p','q','r','s' };
	m['8'] = { 't','u','v' };
	m['9'] = { 'w','x','y','z' };
	sring s;
	cin >> s;
	dg(s, 0);
	cout << "[";
	for (auto x : res)
		cout << x << ", ";
	cout << "]";
}