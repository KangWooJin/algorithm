// https://www.acmicpc.net/problem/3055

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

char arr[52][52];
int check1[52][52];
int check2[52][52];
int n, m;
int d, s;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

class Point
{
public :
	int x;
	int y;
	int type; //0은 물 1은 도치

	Point(){}
	Point(int xx, int yy,int type)
	{
		x = xx;
		y = yy;
		this->type = type;
	}
};
const int MAX = 1000000;
Point q[MAX];
int r, f;

int ans1 , ans2 ;

void bfs()
{
	while (f < r)
	{
		auto p = q[f];
		f = (f + 1) % MAX;

		
		for (int i = 0; i < 4; ++i)
		{
			int x = p.x + dx[i];
			int y = p.y + dy[i];

			if (x < 0 || x >= n || y < 0 || y >= m)
				continue;

			//물
			if (check1[x][y] == 0 && p.type == 0 && (arr[x][y] == '.' || arr[x][y] == 'S'))
			{
				check1[x][y] = check1[p.x][p.y]+1;
				arr[x][y] = '*';
				q[r] = Point(x, y,0);
				r = (r + 1) % MAX;

			}
			//고슴도치
			if (check2[x][y] == 0 && p.type == 1 && ( arr[x][y] == '.' || arr[x][y] == 'D'))
			{
				if (arr[x][y] == 'D')
				{
					check2[x][y] = check2[p.x][p.y] + 1;
					ans1 = x;
					ans2 = y;
					return;
				}
				check2[x][y] = check2[p.x][p.y] + 1;
				arr[x][y] = 'S';
				q[r] = Point(x, y, 1);
				r = (r + 1) % MAX;
			}
		}
		/*
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << arr[i][j] << " ";
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
	cin >> n >> m;

	ans1 = ans2 = -1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> arr[i][j];
			//물을 먼저찾음
			if (arr[i][j] == '*')
			{
				q[r] = Point(i, j,0);
				check1[i][j] = 1;
				r = (r + 1) % MAX;
			}
			
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			//고슴도치 찾음
			if (arr[i][j] == 'S')
			{
				q[r] = Point(i, j,1);
				check2[i][j] = 1;
				r = (r + 1) % MAX;
			}
		}
	}

	bfs();
	if (ans1 == -1)
		cout << "KAKTUS" << '\n';
	else
		cout << check2[ans1][ans2]-1 << '\n';
	return 0;
}