//https://www.acmicpc.net/problem/1012

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int arr[52][52];
int check[52][52];
int cnt;
int n, m;

int dx[] = { 0, 0 ,-1, 1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int x, int y)
{
	check[x][y] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int xi = dx[i]+x;
		int yi = dy[i]+y;

		if (xi < 0 || xi > n || yi < 0 || yi > m)
			continue;

		if (check[xi][yi] == 0 && arr[xi][yi] == 1)
			dfs(xi, yi);
	}
}

int main()
{
	int t;

	cin >> t;

	while (t--)
	{
		int k;

		cin >> n >> m >> k;

		//√ ±‚»≠
		cnt = 0;
		for (int i = 0; i < 52; ++i)
		{
			for (int j = 0; j < 52; ++j)
			{
				arr[i][j] = 0;
				check[i][j] = 0;
			}
		}

		for (int i = 0; i < k; ++i)
		{
			int x, y;
			cin >> x >> y;

			arr[x][y] = 1;
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (check[i][j] == 0 && arr[i][j] == 1)
				{
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}