#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int cntNode, cntEdge;
int snode;

struct Edge
{
	int to;
	int cost;
};

bool operator<(Edge A, Edge B)
{
	if (A.cost < B.cost) return false;
	if (A.cost > B.cost) return true;

	if (A.to < B.to) return false;
	if (A.to > B.to) return true;

	return false;
}

vector <Edge> v[20001];
int dist[20001];
int visited[20001];

void dijkstra(int node)
{

	priority_queue<Edge> pq;

	for (int i = 1; i <= cntNode; i++)
	{
		dist[i] = 1234567890;
	}

	dist[node] = 0;
	pq.push({ node,0 });

	while (!pq.empty())
	{
		Edge now = pq.top();
		pq.pop();

		if (dist[now.to] < now.cost)
		{
			continue;
		}

		for (int i = 0; i < v[now.to].size(); i++)
		{
			Edge next = v[now.to][i];

			int nextcost = dist[now.to] + next.cost;

			if (dist[next.to] <= nextcost)
			{
				continue;
			}

			dist[next.to] = nextcost;
			pq.push({ next.to, nextcost });
		}
	}
	for (int i = 1; i <= cntNode; i++)
	{
		if (dist[i] == 1234567890)
		{
			cout << "INF" << endl;
		}
		else
		{
			cout << dist[i] << endl;
		}
		
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> cntNode >> cntEdge;
	cin >> snode;
	for (int i = 0; i < cntEdge; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
	}

	dijkstra(snode);	
}