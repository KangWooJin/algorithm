
//https://www.acmicpc.net/problem/1707

//#include <iostream>
//#include <vector>
//#include <queue>
//
//#define MAXNODE 20001
//#define RED     1
//
//using namespace std;
//
//int K, V, E;
//vector<int> Graph[MAXNODE];
//vector<int> color(MAXNODE, 0);
//
//bool BFS(int start)
//{
//	queue<int> q;
//
//	q.push(start);
//	color[start] = RED;
//
//	while (!q.empty())
//	{
//		int cur = q.front();
//		q.pop();
//
//		for (int i = 0; i < Graph[cur].size(); i++)
//		{
//			int next = Graph[cur][i];
//
//			if (color[next] == 0)
//			{
//				color[next] = ~color[cur];
//				q.push(next);
//			}
//			else
//			{
//				if (color[next] == color[cur])
//					return false;
//			}
//		}
//	}
//
//	return true;
//}
//
//
//int main()
//{
//	cin >> K;
//
//	while (K--)
//	{
//		int src, dst;
//		bool res = true;
//
//		cin >> V >> E;
//
//		for (int i = 1; i <= V; i++)
//			Graph[i].clear();
//		color.assign(V + 1, 0);
//
//		for (int i = 0; i < E; i++)
//		{
//			cin >> src >> dst;
//			Graph[src].push_back(dst);
//			Graph[dst].push_back(src);
//		}
//
//		for (int i = 1; i <= V; i++)
//		{
//			if (color[i] == 0)
//				res &= BFS(i);
//		}
//
//		if (res == true)
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//	return 0;
//}



#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;
const int MAX = 500000;

vector<int> a[20002];
vector<int> check(MAX, 0);

int q[MAX];
int r, f;

bool bfs(int start)
{
	//bfs�� ������ ���⶧���� f,r �ʱ�ȭ
	queue<int> q;
	q.push(start);
	//���� ������ �׷��������� ���δٸ� check���� ��������
	// 1, 0���� ������ �׷����� �������� ������� �̺б׷����� �ƴ�

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (int i = 0; i < a[curr].size(); ++i)
		{
			//���� �������� ���� �������� �� ���� ����
			int next = a[curr][i];

			//�鷶���� Ȯ��
			if (check[next] == -1)
			{
				//�ȵ鷶����� ���� ������ �ٸ������� ���� 0�ΰ�� 1��/ 1�ΰ�� 0����
				check[next] = (check[curr] + 1) % 2;
				q.push(next);
			}
			//������ �鷶�� ���
			else
			{
				//�鷯���� ������ ���� ������ ���� ���� ������ �̺б׷��� �ƴ�
				if ( curr != next && check[next] == check[curr])
				{
					return false;
				}
			}
		}
	}

	return true;

}
int main()
{
	int t; 
	cin >> t;
	while (t--)
	{
		int v, e;
		cin >> v >> e;
		//�̺�Ž�� ���� Ȯ�ο� flag
		bool flag = true;

		//�ʱ�ȭ ������ŭ �ʱ�ȭ
		for (int i = 1; i <= v; ++i)
			a[i].clear();
		//������ �鷶���� Ȯ�� �ʱ�ȭ
		check.assign(v + 1, -1);
		//����� �׷���
		for (int i = 0; i < e; ++i)
		{
			int x, y;
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}



		//�׷����� �������� ��찡 �����Ƿ� ��ü ���� Ȯ��
		for (int i = 1; i <= v; ++i)
		{
			if (check[i] == -1)
			{
				flag &= bfs(i);
			}
		}

		if (flag == true)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

	}

	return 0;
}
