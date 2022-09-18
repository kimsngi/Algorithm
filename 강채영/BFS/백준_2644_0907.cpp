#include <iostream>
#include <queue>
using namespace std;

int n;
int snode, enode;
int m;
int arr[101][101];
int visited[101][101];
int dist[101];

queue <int> q;

void bfs(int node)
{
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int next = 1; next <= n; next++)
		{
			if (arr[now][next] == 0)
			{
				continue;
			}

			if (visited[now][next] > 0)
			{
				continue;
			}

			visited[now][next] = 1;
			dist[next] = dist[now] + arr[now][next];
			q.push(next);
		}
	}

	if (dist[snode] == 1234567890)
	{
		cout << -1;
	}
	else
	{
		cout << dist[snode];
	}
}

int main()
{
	cin >> n;
	cin >> snode >> enode;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		arr[from][to] = 1;
		arr[to][from] = 1;
	}

	for (int y = 0; y < 101; y++)
	{
		dist[y] = 1234567890;
	}

	q.push(enode);
	dist[enode] = 0;
	bfs(enode);
}