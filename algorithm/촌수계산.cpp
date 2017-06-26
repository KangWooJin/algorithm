// https://www.acmicpc.net/problem/2644

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr[102];
int check[102];

int n;
int s, e;
int ans = -1;
bool flag = true;

void dfs(int start, int end, int c)
{
	if (start == end)
	{
		ans = c;
		flag = false;
		return;
	}

	if (!flag)
		return;

	check[start] = 1;

	for (int i = 0; i < arr[start].size(); ++i)
	{
		if (check[arr[start][i]] == 0)
		{
			dfs(arr[start][i], end,c+1);
		}
	}
}
int main()
{
	cin >> n;
	cin >> s >> e;
	int k;
	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	dfs(s, e, 0);


	cout << ans << '\n';

	return 0;
}