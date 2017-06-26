// https://www.acmicpc.net/problem/1890

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int a[102][102];
long long cnt;

int main()
{
	/*
	int n;
	cin >> n;

	for (int i = 9; i <= n+9; ++i)
	{
		for (int j = 9; j <= n+9; ++j)
		{
			cin >> a[i][j];
		}
	}

	int iCnt = -1;
	int jCnt = -1;
	for (int i = 9; i <= n + 9; ++i)
	{
		iCnt++;
		for (int j = 9; j <= n + 9; ++j)
		{

			for (int k = i - iCnt; k >= 0; k--)
			{
				if (a[k][j] - i == 0)
				{
					cnt++;
				}
			}

			for ( int k = j - )
		}
	}
	*/

	int n;
	cin >> n;

	long long s = 1;
	for (int i = 1; i <= n; ++i)
	{
		s *= i;
	}

	cout << s;

	return 0;
}
