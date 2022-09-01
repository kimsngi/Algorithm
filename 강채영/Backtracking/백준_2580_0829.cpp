#include <iostream>
#include <vector>
using namespace std;

int arr[9][9];
int found = 0;

struct Node
{
	int y;
	int x;
};

vector <Node> v;

int check(int y, int x)
{
	int p = y / 3;
	int q = x / 3;
	for (int i = 0; i < 9; i++)
	{
		if (arr[y][i] == arr[y][x] && i != x)
		{
			return 0; //같은 행에 같은 숫자가 있으면 0 
		}
		if (arr[i][x] == arr[y][x] && i != y)
		{
			return 0; //같은 열에 같은 숫자가 있으면 0
		}
	}

	for (int i = 3 * p; i < 3 * p + 3; i++)
	{
		for (int j = 3 * q; j < 3 * q + 3; j++)
		{
			if (arr[i][j] == arr[y][x])
			{
				if (i != y && j != x)
				{
					return 0; //같은 구역에 같은 숫자가 있으면 0
				}
			}
		}
	}

	return 1; //나머지는 통과이므로 1 return
}

void sudoku(int index)
{
	if (index == v.size())
	{
		found = 1;
		return;
	}

	for (int i = 1; i <= 9; i++)
	{
		arr[v[index].y][v[index].x] = i;
		if (check(v[index].y, v[index].x) == 1)
		{
			sudoku(index + 1);
		}
		if (found == 1)
		{
			return;
		}
	}

	arr[v[index].y][v[index].x] = 0; //최적해를 못찾으면 그냥 0으로 기록
	return;
}


int main()
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			cin >> arr[y][x];
		}
	}

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (arr[y][x] == 0)
			{
				v.push_back({ y,x });
			}
		}
	}

	sudoku(0);

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			cout << arr[y][x] << " ";
		}
		cout << endl;
	}

}