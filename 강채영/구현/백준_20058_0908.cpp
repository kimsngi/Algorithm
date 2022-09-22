#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int N, Q;
int arr[100][100];
int rotatedArr[100][100];
int visited[100][100];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int n;



struct Node
{
	int y;
	int x;
};

queue <Node> q;

int dfs(int y, int x)
{
	visited[y][x] = 1;
	int ans = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dr[i];
		int nx = x + dc[i];

		if (ny < 0 || nx < 0 || ny >= n|| nx >= n)
		{
			continue;
		}

		if (!visited[ny][nx] && arr[ny][nx] > 0)
		{
			ans += dfs(ny, nx);
		}
	}

	return ans;
}

int IceBiggest()
{
	int ice = 0;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (arr[y][x] > 0 && !visited[y][x])
			{
				ice = max(ice, dfs(y,x));
			}
		}
	}

	return ice;
}

long long IceSum()
{
	long long sum = 0;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			sum += arr[y][x];
		}
	}

	return sum;
}


void rotate(int y, int x, int level)
{
	int a = pow(2, level);

	for (int row = 0; row < a; row++) {
		for (int col = 0; col < a; col++) {
			rotatedArr[row][col] = arr[y + a - 1 - col][x + row];
		}
	}

	for (int row = 0; row < a; row++) {
		for (int col = 0; col < a; col++) {
			arr[y + row][x + col] = rotatedArr[row][col];
		}
	}

}

void melt()
{
	q = queue<Node>();
	for (int y = 0; y <n; y++)
	{
		for (int x = 0; x <n; x++)
		{
			int cnt = 0;
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dr[i];
				int nx = x + dc[i];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				{
					continue;
				}
				if (arr[ny][nx] > 0)
				{
					cnt++;
				}
			}

			if (cnt < 3)
			{
				q.push({ y,x });
			}
		}
	}

	while (!q.empty())
	{
		Node a = q.front();
		q.pop();
		if (arr[a.y][a.x] > 0)
		{
			arr[a.y][a.x]--;
		}
	}
}

void solution(int level)
{
	for (int y = 0; y < n; y += pow(2, level))
	{
		for (int x = 0; x < n; x += pow(2, level))
		{
			rotate(y, x, level);
		}
	}

	melt();

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			rotatedArr[y][x] = 0;
		}
	}

}

int main()
{
	cin >> N >> Q;
	n = pow(2,N);
	
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> arr[y][x];
		}
	}

	for (int i = 1; i <= Q; i++)
	{
		int level = 0;
		cin >> level;
		solution(level);
	}

	cout << IceSum() << endl;
	cout << IceBiggest();

}