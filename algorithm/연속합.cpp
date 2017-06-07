//https://www.acmicpc.net/problem/1912

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int a[100000];
int d[100000];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	d[1] = a[1];

	for (int i = 1; i <= n; ++i)
	{
		d[i] = max(a[i], d[i - 1]+a[i]);
	}
	
	int m = INT_MIN;
	for (int i = 1; i <= n; ++i)
	{
		if (m < d[i])
			m = d[i];
	}

	cout << m << '\n';

	return 0;
}