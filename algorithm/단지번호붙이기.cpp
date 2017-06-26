//https://www.acmicpc.net/problem/2667

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

int arr[27][27];
int check[27][27];
vector<int> ans;
int n;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int c;

void dfs(int x, int y)
{
	if (check[x][y] == 0)
		c = c + 1;

	check[x][y] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int xi = x + dx[i];
		int yi = y + dy[i];

		if (xi <0 || xi > n || yi < 0 || yi > n)
			continue;

		if (check[xi][yi] == 0 && arr[xi][yi] == 1)
		{
			dfs(xi, yi);
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
			char c;
			cin >> c;

			arr[i][j] = c - '0';
		}
	}
	
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			c = 0;
			if (check[i][j] == 0 && arr[i][j] == 1)
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