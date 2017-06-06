#include <iostream>
using namespace std;


int d[12];

int main()
{
	int tn;
	cin >> tn;

	for (int t = 0; t < tn; ++t)
	{
		int n;
		cin >> n;

		for (int i = 0; i < 12; ++i)
		{
			d[i] = 0;
		}
		d[0] = 1; d[1] = 1; d[2] = 2; 

		for (int i = 3; i <= n; ++i)
		{
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}

		cout << d[n] << endl;
	}

	return 0;
}