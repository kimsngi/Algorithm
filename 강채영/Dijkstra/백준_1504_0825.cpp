#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cntNode, cntEdge;
int aNode, bNode;
int dist[801] = { 0, };
int ans;

struct Node
{
	int to;
	int cost;
};

vector<Node> v[801];

bool operator < (Node a, Node b)
{
	if (a.cost < b.cost)
	{
		return false;
	}
	if (a.cost > b.cost)
	{
		return true;
	}
	return false;
}

void dijkstra(int now)
{
	priority_queue<Node> pq;
	pq.push({ now, 0 });
	
	for (int i = 1; i <= cntNode; i++)
	{
		dist[i] = 1234567890;
	}
	dist[now] = 0;

	while (!pq.empty())
	{
		Node now = pq.top();
		pq.pop();

		if (dist[now.to] < now.cost)
		{
			continue;
		}

		for (int i = 0; i < v[now.to].size(); i++)
		{
			Node next = v[now.to][i];

			int nextcost = dist[now.to] + next.cost;

			if (dist[next.to] <= nextcost)
			{
				continue;
			}
			dist[next.to] = nextcost;
			pq.push({ next.to, next.cost });
		}
	}
}

int main()
{
	cin >> cntNode >> cntEdge;

	for (int i = 0; i < cntEdge; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	}

	cin >> aNode >> bNode;

	int flag1 = 0;
	int flag2 = 0;

	int a = 0;
	int b = 0;

	dijkstra(1);



	if (dist[aNode] == 1234567890)
	{
		flag1++;
	}
	else
	{
		a = dist[aNode];
	}

	if (dist[bNode] == 1234567890)
	{
		flag2++;
	}
	else
	{
		b = dist[bNode];
	}
	

	dijkstra(aNode);

	if (dist[bNode] == 1234567890)
	{
		flag1++;
		flag2++;
	}
	else
	{
		a += dist[bNode];
		b += dist[bNode];
	}
	
	
	dijkstra(bNode);

	if (dist[cntNode] == 1234567890)
	{
		flag1++;
	}
	else
	{
		a += dist[cntNode];
	}


	dijkstra(aNode);

	if (dist[cntNode] == 1234567890)
	{
		flag2++;
	}
	else
	{
		b += dist[cntNode];
	}

	if (flag1 > 0 && flag2 > 0)
	{
		ans = -1;
	}
	else
	{
		ans = min(a, b);
	}

	cout << ans;
}
