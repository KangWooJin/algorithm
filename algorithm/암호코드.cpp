//  https://www.acmicpc.net/problem/2011

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;


int d[5001];

int mod = 1000000;
int main()
{
	string s;

	cin >> s;

	int len = s.length();
	s = " " + s;

	d[0] = 1;

	for (int i = 1; i <= len; ++i)
	{
		int x = s[i] - '0';

		if (1 <= x && x <= 9)
		{
			d[i] = (d[i] + d[i - 1]) %mod ;
		}

		if (i == 1)
			continue;
		if (s[i - 1] == '0')
			continue;

		int num = (s[i - 1] - '0') * 10 + (s[i] - '0');

		if (10 <= num && num <= 26)
		{
			d[i] = (d[i] + d[i - 2])%mod;
		}

	}

	cout << d[len] << '\n';

	return 0;
}