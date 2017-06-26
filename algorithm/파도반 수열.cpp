// https://www.acmicpc.net/problem/9461

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

long long d[101] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, };

int main()
{

	for (int i = 3; i <= 100; ++i)
	{
		d[i] = d[i - 2] + d[i - 3];
	}
	int tn;
	cin >> tn;

	while (tn--)
	{
		int n;
		cin >> n;
		
		cout << d[n] << '\n';
	}
	return 0;
}