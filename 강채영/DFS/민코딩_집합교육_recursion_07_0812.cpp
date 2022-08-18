#include <iostream>
using namespace std;

int height, width;
int arr[20][20];
int dr[] = { 1,1,1 };
int dc[] = { -1,0,1 };
int visited[20][20];
int sum;
int maxval = -123456789;


void dfs(int y, int x)
{
	if (y == height-1)
	{
		if (maxval < sum)
		{
			maxval = sum;
		}

		return;
	}

	for (int i = 0; i < 3; i++)
	{
		int ny = y + dr[i];
		int nx = x + dc[i];

		if (ny < 0 || nx < 0 || ny >= height || nx >= width)
		{
			continue;
		}

		if (visited[ny][nx] > 0)
		{
			continue;
		}

		if (arr[ny][nx] == 0)
		{
			continue;
		}

		sum += arr[ny][nx];
		visited[ny][nx] = 1;
		dfs(ny, nx);
		visited[ny][nx] = 0;
		sum -= arr[ny][nx];
	}
}

int main()
{
	cin >> height >> width;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			cin >> arr[y][x];
		}
	}

	sum = arr[0][0];
	dfs(0,0);
	cout << maxval;


}