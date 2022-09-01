#include <iostream>
#include <vector>
using namespace std;

int n, L, R;
int arr[100][100];
int visited[100][100];

int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

struct Node
{
	int y;
	int x;
};

vector <Node> v;
int sum;
int num;
int result;

void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dr[i];
		int nx = x + dc[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
		{
			continue;
		}

		if (abs(arr[y][x] - arr[ny][nx]) < L || abs(arr[y][x] - arr[ny][nx]) > R)
		{
			continue;
		}

		if (visited[ny][nx] >0)
		{
			continue;
		}

		visited[ny][nx] = 1;
		v.push_back({ ny, nx });
		sum += arr[ny][nx];
		num++;
		dfs(ny, nx);
	}
}

void reset()
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			visited[y][x] = 0;
		}
	}
}

int main()
{
	cin >> n >> L >> R;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> arr[y][x];
		}
	}

	while (1)
	{
		reset();
		int cnt = 0;
		int flag = 0;

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				if (visited[y][x])
				{
					continue;
				}
				visited[y][x] = 1;
				sum = arr[y][x];
				num = 1;

				v.clear();
				v.push_back({ y,x });
				dfs(y, x);

				if (num >=2 )
				{
					flag = 1;
					for (int i = 0; i < v.size(); i++)
					{
						arr[v[i].y][v[i].x] = sum / num;
					}
				}

			}
		}

		if (flag)
		{
			result++;
		}
		else
		{
			break;
		}

	}

	cout << result;
}