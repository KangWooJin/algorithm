// https://www.acmicpc.net/problem/7562

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int arr[302][302];
int check[302][302];
int s1, s2, e1, e2;
int n;

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };


class Point
{
public :
	int x;
	int y;

	Point(){}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

const int MAX = 2000000;
Point q[MAX];
int r, f;

void bfs()
{
	while ( f<r)
	{
		Point p = q[f];
		f = (f + 1) % MAX;

		if (p.x == e1 && p.y == e2)
		{
			break;
		}

		for (int i = 0; i < 8; ++i)
		{
			int x = p.x + dx[i];
			int y = p.y + dy[i];

			if (x < 0 || x > n-1 || y < 0 || y>n-1)
				continue;

			if (check[x][y] == 0)
			{
				check[x][y] = check[p.x][p.y] + 1;
				Point temp(x, y);
				q[r] = temp;
				r = (r + 1) % MAX;

				

			}
		}
		/*
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << check[i][j] << " ";
			}
			cout << '\n';
		} 
		cout << '\n';
		*/
	}
}
int main()
{
	//freopen("out.txt", "w", stdout);
	int t;
	
	cin >> t;

	while (t--)
	{
		for (int i = 0; i < 302; ++i)
		{
			for (int j = 0; j < 302; ++j)
			{
				check[i][j] = 0;
				arr[i][j] = 0;
			}
		}

		cin >> n >> s1 >> s2 >> e1 >> e2;
		f = r = 0;

		q[r] = Point(s1, s2);
		r = (r + 1) % MAX;
		
		check[s1][s2] = 1;
		bfs();
		
		cout << check[e1][e2]-1 << '\n';

	}

	return 0;
}