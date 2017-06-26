#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

int dist[1001];
int check[1001];

vector<vector<int>> V;

class Edge
{
public :
	int to;
	int cost;

	Edge(int t, int c){
		to = t;
		cost = c;

	}
};

vector<Edge> a[1001];
int inf = 100000000;
int main()
{
	int n, m;
	int start, end;
	
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int vv, ww, tt;
		cin >> vv >> ww >> tt;
		vector<int> temp;
		temp.push_back(vv);
		temp.push_back(ww);
		temp.push_back(tt);
		V.push_back(temp);
		
	}

	for (int i = 0; i < V.size(); ++i)
	{
		a[V[i][0]].push_back(Edge(V[i][1], V[i][2]));
	}

	cin >> start >> end;

	//��� ���� ���Ѵ�� ����
	for (int i = 1; i <= n; ++i)
	{
		dist[i] = inf;
	}

	//�����ϴ� ���� �ʱ�ȭ
	dist[start] = 0;

	// ������ ������ �湮���� ����
	for (int k = 0; k < n - 1; ++k)
	{
		int min = inf + 1;
		int x = -1;

		//�湮���� �ʾ����鼭 ������ �ּ��ΰ��� ã��
		for (int i = 1; i <= n; ++i)
		{
			if (check[i] == false && min > dist[i])
			{
				//�ּҰ�
				min = dist[i];
				//������ ��ġ
				x = i;
			}
		}

		//���� �湮 üũ
		check[x] = true;

		//�ش� �������� ���� �ִ� ������ŭ Ž��
		for (int i = 0; i < a[x].size(); ++i)
		{
			//x->to�� �������� �̵�
			int y = a[x][i].to;
			//�̵��Ϸ��� ������ ����ġ > ���� ���� ����ġ + �̵��Ϸ��� ������ ������ ����ġ
			if (dist[y] > dist[x] + a[x][i].cost)
			{
				dist[y] = dist[x] + a[x][i].cost;
			}
		}
	}

	cout << dist[end] << '\n';

	return 0;
}