// https://www.acmicpc.net/problem/10844

#include <iostream>
using namespace std;

long long d[101][12];
long long mod = 1000000000;
int main()
{
	int n;
	cin >> n;

	for (int i = 2; i <= 10; ++i)
	{
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			d[i][j] = ((d[i - 1][j - 1] % mod) + (d[i - 1][j + 1] % mod)) % mod;
		}
	}

	long long sum = 0;
	for (int i = 1; i <= 10; ++i)
	{
		sum += d[n][i];
	}

	cout << sum % mod << endl;
	return 0;
}
