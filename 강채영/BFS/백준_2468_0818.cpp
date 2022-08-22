#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int arr[101][101];
int newarr[101][101];
int visited[101][101];
int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };
int cnt;


int lenmax = -1234567890;
int lenmin = 1234567890;
int resultmax = -1234567890;

struct Node
{
	int y;
	int x;
};

void bfs(int y, int x)
{
	queue<Node>q;
	q.push({ y,x });
	visited[y][x] = 1;

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dc[i];
			int nx = now.x + dr[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			{
				continue;
			}
			if (visited[ny][nx] > 0)
			{
				continue;
			}
			if (newarr[ny][nx] == 0)
			{
				continue;
			}

			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny, nx });
		}
	}
}


void reset() 
{
	for (int y = 0; y < n; y++) 
	{
		for (int x= 0; x < n; x++) 
		{
			newarr[y][x] = 0;
			visited[y][x] = 0;
		}
	}
	cnt = 0;
}

int main()
{
	cin >> n;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> arr[y][x];
			if (lenmax < arr[y][x])
			{
				lenmax = arr[y][x];
			}

			if (lenmin > arr[y][x])
			{
				lenmin = arr[y][x];
			}
		}
	}
	// i<lenmax¶ó°í ÇÏ¸é ¹Ý·Ê°¡ »ý±è
	// 2
	// 1 1
	// 1 1
	//  -> 1

	for (int i = lenmin; i <= lenmax; i++)
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				if (arr[y][x] < i)
				{
					newarr[y][x] = 0;
				}
				else
				{
					newarr[y][x] = 1;
				}

			}
		}

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				if (!visited[y][x] && newarr[y][x])
				{
					bfs(y, x);
					cnt++;
				}
			}
		}

		if (resultmax < cnt)
		{
			resultmax = cnt;
		}
		

		reset();
	}

	cout << resultmax;

}