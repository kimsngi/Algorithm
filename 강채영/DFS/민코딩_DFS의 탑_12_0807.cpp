#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[100][100];
int visited[100][100];
int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };
int max_y = -123456789;
int max_x = -123456789;
int min_y = 123456789;
int min_x = 123456789;
int area;
int result[100];
int t;


void dfs(int y, int x)
{

	visited[y][x] = 1;
	area = 0;
		
	if (max_y < y)
	{
		max_y = y;
	}
	if (max_x < x)
	{
		max_x = x;
	}

	if (min_y > y)
	{
		min_y = y;
	}
	if (min_x > x)
	{
		min_x = x;
	}


	for (int i = 0; i < 4; i++)
	{
		int ny = y + dr[i];
		int nx = x + dc[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
		{
			continue;
		}

		if (visited[ny][nx] == 1)
		{
			continue;
		}

		if (arr[ny][nx] == 0)
		{
			continue;
		}

		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
}

int main()
{
	cin >> n >> m;
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
			if (arr[y][x] == 0)
			{
				continue;
			}
			if (visited[y][x] == 1)
			{
				continue;
			}
			dfs(y, x);
			area = ((max_y - min_y + 2) + (max_x - min_x + 2)) * 2;
			result[t] = area;
			t++;

			max_y = -123456789;
			max_x = -123456789;
			min_y = 123456789;
			min_x = 123456789;
		}
	}
	
	int max = -123456789;

	for (int i = 0; i < 100; i++)
	{
		if (result[i] > max)
		{
			max = result[i];
		}
	}

	cout << max;
	
}