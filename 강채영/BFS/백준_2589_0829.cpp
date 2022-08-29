#include <iostream>
#include <queue>
using namespace std;

int h;
int w;

char map[50][50];
int visited[50][50];
int dist[50][50];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int maxlength;

struct Node
{
	int y;
	int x;
};

int bfs(int y, int x)
{
	queue<Node> q;
	q.push({ y,x });
	visited[y][x] = 1;
	dist[y][x] = 1;
	

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dr[i];
			int nx = now.x + dc[i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w)
			{
				continue;
			}

			if (map[ny][nx] == 'L' && !visited[ny][nx])
			{
				visited[ny][nx] = 1;
				dist[ny][nx] = dist[now.y][now.x] + 1;
				q.push({ ny,nx });
				if (maxlength < dist[ny][nx])
				{
					maxlength = dist[ny][nx];
				}
				
			}
		}
	}
	return maxlength - 1; //경로 중에서도 최댓값을 골라야함

}

void reset()
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			visited[y][x] = 0;
			dist[y][x] = 0;
		}
	}

	maxlength = 0;
}

int main()
{
	cin >> h >> w;
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			cin >> map[y][x];
		}
	}

	int maxval = -1;

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (map[y][x] == 'L')
			{
				int result = bfs(y, x);
				maxval = max(result, maxval);
				reset(); //값들을 reset해주어야 함
			}
		}
	}

	cout << maxval;
}