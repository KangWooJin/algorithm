// https://www.acmicpc.net/problem/2579

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int a[301];
int d[301][3];
int d2[301];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	/*
	for (int i = 1; i <= n; ++i)
	{
		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}
	


	cout << max(d[n][1], d[n][2]) << '\n';
	*/

	for (int i = 1; i <= n; ++i)
	{
		d2[i] = d2[i - 2] + a[i];

		if (d2[i] < d2[i - 3] + a[i - 1] + a[i])
		{
			d2[i] = d2[i - 3] + a[i - 1] + a[i];
		}
	}

	cout << d2[n] << '\n';

	return 0;
}