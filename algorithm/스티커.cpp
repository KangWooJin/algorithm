//https://www.acmicpc.net/problem/9465

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[100001][2];
int d[100001][3];

int main()
{
	int tn;
	cin >> tn;

	while (tn--)
	{
		int n;
		cin >> n;

		for (int j = 0; j < 2; ++j)
		{
			for (int i = 1; i <= n; ++i)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			d[i][0] = max(max(d[i - 1][0], d[i - 1][1]), d[i - 1][2]);
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + arr[i][0];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + arr[i][1];
		}

		cout << max(max(d[n][0], d[n][1]), d[n][2]) << '\n';
	}

	return 0;
}