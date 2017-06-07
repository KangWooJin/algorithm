// https://www.acmicpc.net/problem/11055

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int a[1002];
int d[1002];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}



	for (int i = 1; i <= n + 1; ++i)
	{
		d[i] = a[i];

		for (int j = i; j > 1; j--)
		{
			if (d[i] < d[j - 1] + a[i] && a[j - 1] < a[i])
			{
				d[i] = d[j - 1] + a[i];
			}
		}
	}

	int max = -1;
	for (int i = 1; i <= n; ++i)
	{
		if (max < d[i])
			max = d[i];
	}

	cout << max << '\n';

	return 0;
}