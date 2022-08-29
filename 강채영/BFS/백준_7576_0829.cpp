#include <iostream>
#include <queue>
using namespace std;

int m, n;
int arr[1001][1001];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int result;

struct Node
{
	int y;
	int x;
};

queue <Node> q;

void bfs()
{
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dr[i];
			int nx = now.x + dc[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			{
				continue;
			}

			// 토마토가 안들어 있을 때 
			if (arr[ny][nx] == -1)
			{
				continue;
			}

			if (arr[ny][nx] == 0)
			{
				arr[ny][nx] = arr[now.y][now.x] + 1;
				q.push({ ny, nx });
			}
			
		}
	}
}

int main()
{
	cin >> m>>n;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> arr[y][x];
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (arr[y][x] == 1)
			{
				q.push({ y,x });
			}
		}
	}

	bfs();

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (arr[y][x] == 0)
			{
				result = -1;
			}
			else
			{
				result = max(result, arr[y][x]);
			}
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (arr[y][x] == 0)
			{
				result = -1;
			}
		}
	}

	if (result == -1)
	{
		cout << -1;
	}
	else
	{
		cout << result - 1;
	}
}