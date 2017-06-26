// https://www.acmicpc.net/problem/11048

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int a[1002][1002];
int d[1002][1002];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			d[i][j] = max(max(d[i - 1][j], d[i - 1][j - 1]), d[i][j - 1]) + a[i][j];
		}
	}

	cout << d[n][m] << '\n';
	return 0;
}