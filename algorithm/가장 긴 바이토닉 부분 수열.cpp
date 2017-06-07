// https://www.acmicpc.net/problem/11054

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int a[1002];
int d[1002];
int d2[1002];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}



	//감소
	for (int i = n; i >= 1 ; --i)
	{
		d[i] = 1;

		for (int j = i+1; j <= n; j++)
		{
			if (d[i] < d[j] + 1 && a[j] < a[i])
			{
				d[i] = d[j] + 1;
			}
		}
	}

	//증가
	for (int i = 1; i <= n ; ++i)
	{
		d2[i] = 1;

		for (int j = i; j > 1; j--)
		{
			if (d2[i] < d2[j - 1] + 1 && a[j - 1] < a[i])
			{
				d2[i] = d2[j - 1] + 1;
			}
		}
	}

	int max = -1;
	for (int i = 1; i <= n; ++i)
	{
		if (max < d[i] + d2[i] - 1)
			max = d[i] + d2[i] - 1;

	}
	cout << max << '\n';
	return 0;

}