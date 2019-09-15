#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
	string reverseParentheses(string s) {
		//设个vector，存每个左括号，再设个vector存每个右括号，最右边的左和最左边的右反转。
		int n = s.size();
		vector<int> l, r;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				l.push_back(i);
			if (s[i] == ')')
				r.push_back(i);
		}
		for (int i = l.size() - 1; i >= 0; i--)
		{
			int posl = l.back();
			l.pop_back();
			int posr;
			for (int j = 0; j < r.size(); j++)
			{
				if (r[j] < posl)
					continue;
				posr = r[j];
				r.erase(find(r.begin(), r.end(), posr));
				break;
			}
			for (int j = posl, k = posr; j < k; j++, k--)
			{
				swap(s[j], s[k]);
			}
		}
		string res = "";
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '(' || s[i] == ')')
				continue;
			res += s[i];
		}
		return res;
	}
};

int main()
{
	Solution S;
	string t = "(u(love)i)";
	cout<<S.reverseParentheses(t);
}