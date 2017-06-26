
//https://www.acmicpc.net/problem/1707

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

vector<int> a[20000];

int main()
{
	int t; 
	cin >> t;
	while (t--)
	{
		int v, e;
		cin >> v >> e;

		for (int i = 0; i < e; ++i)
		{
			int x, y;
			cin >> x >> y;

			a[x].push_back(y);
			a[y].push_back(x);
		}
	}

	return 0;
}