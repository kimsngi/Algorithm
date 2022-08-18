#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[20][20];
int cnt;
int dr[] = { 0,1,1 };
int dc[] = { 1,0,1 };

void func(int y, int x, int index)
{
	
	if (y == n && x == n) // func 종료 조건 
	{
		cnt++;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if (index == 0 && i == 1)  //index값에 따라 갈 수 있는 방향 제한
		{
			continue;
		}

		if (index == 1 && i == 0)
		{
			continue;
		}

		int ny = y + dr[i];
		int nx = x + dc[i];

		if (ny < 1 || nx < 1|| ny > n || nx > n)
		{
			continue;
		}

		if (arr[ny][nx] == 1)
		{
			continue;
		}

		if (i == 2 && (arr[y + 1][x] == 1 || arr[y][x + 1] == 1))  // 대각선으로 이동했을 때 주변에 벽이 있는 경우 제외시켜야함
		{
			continue;
		}

		func(ny, nx, i);
	}
	
} 

int main()
{
	cin >> n;
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			cin >> arr[y][x];
		}
	}

	func(1, 2, 0);
	cout << cnt;
}