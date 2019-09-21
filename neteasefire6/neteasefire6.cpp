#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <string>
using namespace std;
int main()
{
	string t;
	vector<string> v(1,""), prev(1,"");
	int curx = 0, cury = 0 , prex = 0,prey = 0;
	while (cin>>t)
	{
		if (t != "undo")
			prev = v;
		if (t == "i" || t == "o" || t == "a")
		{
			string s;
			getline(cin, s);
			s.erase(0, s.find_first_not_of(" "));
			if (t == "i")
			{
				if (cury == 0)
				{
					v[curx] = s;
				}
				else
				{
					string ori = v[curx];
					string l = ori.substr(0, curx), r = ori.substr(curx, ori.size() - curx);
					v[curx] = l + s + r;
				}
				prey = cury;
				cury = cury + s.size() - 1;
			}
			else if (t == "a")
			{
				if (cury == 0)
				{
					v[curx] = s;
				}
				else
				{
					string ori = v[curx];
					string l = ori.substr(0, curx + 1), r = ori.substr(curx + 1, ori.size() - curx - 1);
					v[curx] = l + s + r;
				}
				prey = cury;
				cury = cury + s.size();
			}
			else
			{
				v.push_back(s);
				for (int i = v.size() - 1; i > curx; i--)
				{
					swap(v[i], v[i - 1]);
				}
				prex = curx;
				curx++;
				prey = cury;
				cury = s.size();
			}
		}
		else if (t == "dd")
		{
			for (int i = curx; i < v.size() - 1; i++)
			{
				v[i] = v[i + 1];
			}
			v.pop_back();
			if (curx == v.size())
				curx - 1;
			cury = 0;
		}
		else if (t == "d")
		{
			int n;
			cin >> n;
			if (cury + n - 1 >= v[curx].size())
			{
				v[curx] = v[curx].substr(0, cury);
				prey = cury;
				cury++;
			}
			else
			{
				string l = v[curx].substr(0, cury), r = v[curx].substr(cury + n, v[curx].size() - cury - n + 1);
				v[curx] = l + r;
			}
		}
		else if (t == "g")
		{
			int x, y;
			cin >> x >> y;
			x--; y--;
			prex = curx;
			if (x >= v.size())
				curx = v.size() - 1;
			else
				curx = x;
			prey = cury;
			if (y >= v[curx].size())
				cury = v[curx].size() - 1;
			else
				cury = y;
		}
		else if (t == "undo")
		{
			curx = prex;
			cury = prey;
			v = prev;
			prex = curx;
			prey = cury;
			prev = v;
		}
		else if (t == "redo")
		{
			curx = prex;
			cury = prey;
			v = prev;
		}
		else
		{
			break;
		}
	}
	for (auto x : v)
		cout << x << endl;
}

