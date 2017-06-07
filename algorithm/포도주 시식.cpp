//https://www.acmicpc.net/problem/2156

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[10001];
int d[10001][3];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; ++i)
	{
		d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
		d[i][1] = d[i - 1][0] + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}

	cout << max(max(d[n][0], d[n][1]), d[n][2]);
	
	return 0;
}
