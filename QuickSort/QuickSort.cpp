#include "pch.h"
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

list<int> quick_sort(list<int> input)
{
	if (input.empty())
	{
		return input;
	}
	list<int> result;
	result.splice(result.begin(), input, input.begin());
	int const& pivot = *result.begin();
	auto divide_point = partition(input.begin(), input.end(), [&](int x) {return x < pivot; });
	list<int> lower_part;
	lower_part.splice(lower_part.end(), input, input.begin(), divide_point);
	auto new_lower(quick_sort(move(lower_part)));
	auto new_higher(quick_sort(move(input)));
	result.splice(result.end(), new_higher);
	result.splice(result.begin(), new_lower);
	return result;
}
int main()
{
	list<int> l;
	for (int i = 10; i > 0; i--)
	{
		l.push_back(i);
	}
	l = quick_sort(l);
	for (int i = 0; i < 10; i++)
	{
		cout << l.front();
		l.pop_front();
	}
}