
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
	//bfs가 여러번 돌기때문에 f,r 초기화
	queue<int> q;
	q.push(start);
	//서로 인접한 그래프끼리는 서로다른 check값을 가져야함
	// 1, 0으로 인접한 그래프가 같은값을 가질경우 이분그래프가 아님

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (int i = 0; i < a[curr].size(); ++i)
		{
			//현재 정점에서 다음 정점으로 갈 정점 선택
			int next = a[curr][i];

			//들렀는지 확인
			if (check[next] == -1)
			{
				//안들렀을경우 현재 정점과 다른값으로 설정 0인경우 1로/ 1인경우 0으로
				check[next] = (check[curr] + 1) % 2;
				q.push(next);
			}
			//정점을 들렀을 경우
			else
			{
				//들러야할 정점과 현재 정점이 같은 값을 가지면 이분그래프 아님
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
		//이분탐색 여부 확인용 flag
		bool flag = true;

		//초기화 정점만큼 초기화
		for (int i = 1; i <= v; ++i)
			a[i].clear();
		//정점을 들렀는지 확인 초기화
		check.assign(v + 1, -1);
		//양방향 그래프
		for (int i = 0; i < e; ++i)
		{
			int x, y;
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}



		//그래프가 여러개일 경우가 있으므로 전체 정점 확인
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
