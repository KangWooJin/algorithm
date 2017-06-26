// https://www.acmicpc.net/problem/2206

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int arr[1002][1002];
int check[1002][1002][2];

int ans = 1234567890;

class Point
{
public :
	int x;
	int y;
	int power;

	Point(){}
	Point(int x, int y, int p)
	{
		this->x = x;
		this->y = y;
		power = p;
	}
};

const int MAX = 1000000;
Point q[MAX];
int r, f;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int n, m;


void bfs()
{
	
}
int main()
{
	



	return 0;
}