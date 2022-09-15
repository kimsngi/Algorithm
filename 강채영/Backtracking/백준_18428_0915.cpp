#include <iostream>
#include <vector>
using namespace std;

int n;
int flag;
char arr[10][10];
int watch[10][10];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };

struct Node
{
	int y; 
	int x;
};

vector <Node> teacher;
vector <Node> space;
vector <Node> student;

void check()
{
	for (int i = 0; i < teacher.size(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int ny = teacher[i].y;
			int nx = teacher[i].x;
			watch[ny][nx] = 1;
			while (1)
			{
				ny += dr[j];
				nx += dc[j];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				{
					break;
				}
				if (arr[ny][nx] == 'O')
				{
					break;
				}
				watch[ny][nx] = 1;
			}
		}
	}
}

void reset()
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			watch[y][x] = 0;
		}
	}
}

void dfs(int cnt, int index)
{
	if (cnt == 3)
	{
		reset();
		check();

		for (int j = 0; j < student.size(); j++)
		{
			if (watch[student[j].y][student[j].x] == 1)
			{
				return;
			}
		}
		flag = 1;
		return;
	}

	for (int i = index; i < space.size(); i++)
	{
		int ny = space[i].y;
		int nx = space[i].x;

		arr[ny][nx] = 'O';
		dfs(cnt + 1, i + 1);
		arr[ny][nx] = 'X';
	}
}

int main()
{
	cin >> n;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> arr[y][x];
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (arr[y][x] == 'T')
			{
				teacher.push_back({ y,x });
			}
			if (arr[y][x] == 'X')
			{
				space.push_back({ y,x });
			}
			if (arr[y][x] == 'S')
			{
				student.push_back({ y,x });
			}
		}
	}

	dfs(0, 0);

	if (flag == 1)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}