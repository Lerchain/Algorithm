#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

void quicksort(vector<int>& v, int l, int r)
{
	if (l >= r)
		return;
	int orl = l, orr = r;
	int pivot = v[l++];
	vector<int> lhs, rhs;
	while (l <= r)
	{
		while (l <= r&&v[l] < pivot)
		{
			lhs.push_back(v[l++]);
		}
		while (l<=r&&v[r]>pivot)
		{
			rhs.push_back(v[r--]);
		}
		if (l <= r)
		{
			lhs.push_back(v[r--]);
			rhs.push_back(v[l++]);
		}
	}
	int ln = lhs.size();
	auto lit = lhs.begin();
	for (int i = orl; i < orl+ ln; i++)
	{
		v[i] = *lit++;
	}
	v[orl+ln] = pivot;
	auto rit = rhs.begin();
	for (int i = orl+ln+1; i <= orr; i++)
	{
		v[i] = *rit++;
	}
	quicksort(v, orl, pivot - 1);
	quicksort(v, pivot + 1, orr);
}

int main()
{
	vector<int> v{1,3,5,2,9,4,8,6,7,0};
	//int j = 0;
	/*for (int i = 10; i >0; i--)
	{
		v[j++] = i;
	}*/
	quicksort(v,0,9);
	for (int i = 0; i < 10; i++)
	{
		cout << v[i] << " ";
	}
}

