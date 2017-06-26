// https://www.acmicpc.net/problem/2133

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

long long d[40];

int main()
{
	int n;
	cin >> n;
	
	d[0] = 1;

	for (int i = 2; i <= n; i+=2)
	{
		d[i] = 3 * d[i - 2];

		for (int j = i - 4; j >= 0; j -= 2)
		{
			d[i] += 2 * d[j];
		}
	}

	cout << d[n] << '\n';
	return 0;
}