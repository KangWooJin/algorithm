// https://www.acmicpc.net/problem/2589

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int arr[52][52];
int check[52][52];

int n, m;

class Point
{
public :
	int x;
	int y;

	Point(){}
	Point(int xx, int yy)
	{
		x = xx;
		y = yy;
	}
};

const int MAX = 1000000;
Point q[MAX];
int r, f;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int maxx;

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

			if (arr[x][y] == 1 && check[x][y] == 0)
			{
				check[x][y] = check[p.x][p.y] + 1;
				q[r] = Point(x, y);
				r = (r + 1) % MAX;
			}
		}
	}
}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char z;
			cin >> z;

			if (z == 'W')
			{
				arr[i][j] = 0;
			}
			else
				arr[i][j] = 1;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			r = f = 0;

			memset(&check, 0, sizeof(check));

			if (arr[i][j] == 1)
			{
				q[r] = Point(i, j);
				r = (r + 1) % MAX;
				check[i][j] = 1;
				bfs();
			}

			if (maxx < check[q[f-1].x][q[f-1].y]-1)
			{
				maxx = check[q[f-1].x][q[f-1].y]-1;
			}
		}

	}

	cout << maxx << '\n';
	

	return 0;
}