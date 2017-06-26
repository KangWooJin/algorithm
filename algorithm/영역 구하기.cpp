// https://www.acmicpc.net/problem/2583

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int arr[102][102];
int check[102][102];
int n, m, k;

vector<int> ans;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int c;

void dfs(int x, int y)
{
	if (check[x][y] == 0)
		c++;

	check[x][y] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int xi = x + dx[i];
		int yi = y + dy[i];

		if (xi < 0 || xi > n-1 || yi < 0 || yi > m-1)
			continue;

		if (check[xi][yi] == 0 && arr[xi][yi] == 0)
		{
			dfs(xi, yi);
		}
	}
}
int main()
{

	cin >> m >> n >> k;
	
	for (int z = 0; z < k; ++z)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = x1; i < x2; ++i)
		{
			for (int j = y1; j < y2; ++j)
			{
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			c = 0;
			if (check[i][j] == 0 && arr[i][j] == 0)
			{
				dfs(i, j);
				ans.push_back(c);
			}
		}
	}


	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << '\n';
	return 0;
}