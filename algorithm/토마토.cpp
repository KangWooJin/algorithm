#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int a[1002][1002];
int c[1002][1002];


const int MAX = 1000000;

int q[MAX][2];
int f=0,r=0;

int ans;

void bfs()
{
	while (f < r)
	{

		int x = q[f][0];
		int y = q[f][1];
		f = (f + 1) % MAX;

		ans = ans > a[x][y] ? ans : a[x][y];

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (a[nx][ny] == 0)
			{
				q[r][0] = nx;
				q[r][1] = ny;
				r = (r + 1) % MAX;
				a[nx][ny] = a[x][y]+1;
			}
		}
	}
}

int main()
{

	int n, m;
	cin >> m >> n;

	for (int i = 0; i <= m+1; ++i)
	{
		a[0][i] = -9;
		a[n + 1][i] = -9;
	}

	for (int i = 0; i <= n+1; ++i)
	{
		a[i][0] = -9;
		a[i][m + 1] = -9;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
			{
				q[r][0] = i;
				q[r][1] = j;
				r = (r + 1) % MAX;
			}
		}
	}

	
	bfs();

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (a[i][j] == 0)
				ans = 0;
		}
	}
	cout << ans - 1 << '\n';

	return 0;
}