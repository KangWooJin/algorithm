// https://www.acmicpc.net/problem/10026

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

char arr[102][102];
int check[102][102];
int check2[102][102];
int n;

int ans1, ans2;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int x, int y, char A, int type)
{

	for (int i = 0; i < 4; ++i)
	{
		int xi = x + dx[i];
		int yi = y + dy[i];

		if (xi < 0 || xi >= n || yi < 0 || yi >= n)
			continue;

		if (type == 1)
		{
			if (check2[xi][yi] == 0)
			{
				if (A == 'R' && (arr[xi][yi] == 'R' || arr[xi][yi] == 'G'))
				{
					check2[xi][yi] = 1;
					dfs(xi, yi, A, type);
				}
				else if (A == 'G' && (arr[xi][yi] == 'R' || arr[xi][yi] == 'G'))
				{
					check2[xi][yi] = 1;
					dfs(xi, yi, A, type);
				}
				else if (arr[xi][yi] == A)
				{
					check2[xi][yi] = 1;
					dfs(xi, yi, A, type);
				}
				
			}
		}
		else
		{
			if (check[xi][yi] == 0 && arr[xi][yi] == A)
			{
				check[xi][yi] = 1;
				dfs(xi, yi, A, type);
			}
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
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (check[i][j] == 0)
			{
				check[i][j] = 1;
				dfs(i, j, arr[i][j],0);
				ans1++;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (check2[i][j] == 0 )
			{
				check2[i][j] = 1;
				dfs(i, j, arr[i][j], 1);
				ans2++;
			}
		}
	}

	cout << ans1 << " " << ans2 << '\n';
	return 0;
}
