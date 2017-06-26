// https://www.acmicpc.net/problem/2225

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

long long d[201][201];
int mod = 1000000000;

int main()
{
	int n, k;
	cin >> n >> k;


	d[0][0] = 1;

	for (int i = 1; i <= k; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			for (int k = 0; k <= j; ++k)
			{
				d[i][j] += d[i - 1][j - k];
				d[i][j] %= mod;

			}
		}
	}

	cout << d[k][n];

	return 0;
}