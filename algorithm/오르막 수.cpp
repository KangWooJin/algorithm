// https://www.acmicpc.net/problem/11057

#include <iostream>
using namespace std;

long long d[1001][12];
long long mod = 10007;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= 10; ++i)
		d[1][i] = 1;

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			for (int k = 1; k <= j; k++)
			{
				d[i][j] += d[i - 1][k];
				d[i][j] %= mod;
			}
		}
	}

	long long sum = 0;
	for (int i = 1; i <= 10; ++i)
		sum += d[n][i];

	cout << sum % mod << endl;


	return 0;
}