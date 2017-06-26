// https://www.acmicpc.net/problem/2468

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int arr[102][102];
int check[102][102];
int n;

int maxx;
int ans;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int x, int y, int h)
{
	
	check[x][y] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int xi = x + dx[i];
		int yi = y + dy[i];

		if (xi < 0 || xi >= n || yi < 0 || yi >= n)
			continue;

		if (check[xi][yi] == 0 && arr[xi][yi] > h)
		{
			dfs(xi, yi, h);
		}
	}
}
int main()
{

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
			if (maxx < arr[i][j])
			{
				maxx = arr[i][j];
			}
		}
	}
	for (int k = 0; k <= 100; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				check[i][j] = 0;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				
				if (check[i][j] == 0 && arr[i][j] > k)
				{
					dfs(i, j, k);
					cnt++;
				}
			}

			
		}
		if (ans < cnt)
			ans = cnt;
	}

	cout << ans << '\n';
	return 0;
}