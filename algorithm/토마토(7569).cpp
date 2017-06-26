//https://www.acmicpc.net/problem/7569

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int arr[102][102][102];
int check[102][102][102];

int n, m, height;

class Point
{
public :
	int x;
	int y;
	int h;

	Point(){}
	Point(int hh, int xx, int yy)
	{
		x = xx; y = yy; h = hh;
	}
};

const int MAX = 1000000;
Point q[MAX];
int r, f;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int dh[] = { 1, -1 };

int ans;

void bfs()
{
	while (f < r)
	{
		Point p = q[f];
		f = (f + 1) % MAX;

		for (int i = 0; i < 4; ++i)
		{
			int x = p.x + dx[i];
			int y = p.y + dy[i];

			if (x < 0 || x >= n || y < 0 || y >= m)
				continue;

			if (arr[p.h][x][y] == 0)
			{
				arr[p.h][x][y] = arr[p.h][p.x][p.y] + 1;
				q[r] = Point(p.h, x, y);
				r = (r + 1) % MAX;
			}

		}

		for (int i = 0; i < 2; ++i)
		{
			int h = p.h + dh[i];
			
			if (h < 0 || h >= height )
				continue;

			if (arr[h][p.x][p.y] == 0)
			{
				arr[h][p.x][p.y] = arr[p.h][p.x][p.y] + 1;
				q[r] = Point(h, p.x, p.y);
				r = (r + 1) % MAX;
			}
		}
	}
}
int main()
{
	cin >> m >> n >> height;

	int cnt = 0;

	for (int k = 0; k < height; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> arr[k][i][j];
				
				if (arr[k][i][j] == 1)
				{
					q[r] = Point(k, i, j);
					r = (r + 1) % MAX;
				}
				else if (arr[k][i][j] == 0)
				{
					cnt++;
				}
			}
		}
	}

	bfs();
	
	ans = arr[q[f-1].h][q[f-1].x][q[f-1].y]-1;

	for (int k = 0; k < height; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (arr[k][i][j] == 0)
					ans = -1;
			}
		}
	}

	if (cnt == 0)
	{
		ans = 0;
	}

	cout << ans << '\n';
	

	return 0;
}