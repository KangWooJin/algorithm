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

	//모든 정점 무한대로 설정
	for (int i = 1; i <= n; ++i)
	{
		dist[i] = inf;
	}

	//시작하는 정점 초기화
	dist[start] = 0;

	// 마지막 정점은 방문하지 않음
	for (int k = 0; k < n - 1; ++k)
	{
		int min = inf + 1;
		int x = -1;

		//방문하지 않았으면서 정점이 최소인것을 찾음
		for (int i = 1; i <= n; ++i)
		{
			if (check[i] == false && min > dist[i])
			{
				//최소값
				min = dist[i];
				//정점의 위치
				x = i;
			}
		}

		//정점 방문 체크
		check[x] = true;

		//해당 정점에서 갈수 있는 정점만큼 탐색
		for (int i = 0; i < a[x].size(); ++i)
		{
			//x->to의 정점으로 이동
			int y = a[x][i].to;
			//이동하려는 정점의 가중치 > 현재 나의 가중치 + 이동하려는 정점의 간선의 가중치
			if (dist[y] > dist[x] + a[x][i].cost)
			{
				dist[y] = dist[x] + a[x][i].cost;
			}
		}
	}

	cout << dist[end] << '\n';

	return 0;
}