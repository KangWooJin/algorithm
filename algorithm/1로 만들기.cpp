/**

https://www.acmicpc.net/problem/1463

*/

#include <iostream>
#include <algorithm>
using namespace std;

int d[1000001];

/* 

top-down 


int dfs(int n)
{
	if (n == 1)
	{
		return 0;
	}

	if (d[n] > 0)
	{
		return d[n];
	}

	d[n] = dfs(n - 1) + 1;

	if (n % 2 == 0)
	{
		int temp = dfs(n / 2) + 1;
		d[n] = min(temp, d[n]);
	}

	if (n % 3 == 0)
	{
		int temp = dfs(n / 3) + 1;
		d[n] = min(temp, d[n]);
	}

	return d[n];

}
int main()
{
	int n;
	cin >> n;

	cout << dfs(n) << endl;


	return 0;
}

*/

/* bottom up*/

int main()
{
	int n;
	cin >> n; 

	d[1] = 0;

	for (int i = 2; i <= n; ++i)
	{
		d[i] = d[i - 1] + 1;

		if (i % 2 == 0)
		{
			d[i] = min(d[i], d[i / 2] + 1);
		}

		if (i % 3 == 0)
		{
			d[i] = min(d[i], d[i / 3] + 1);
		}
	}

	cout << d[n];
	return 0;
}